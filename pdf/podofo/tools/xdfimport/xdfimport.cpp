/*
 * Author: Dominik Seichter
 * Edited by: Zhuo Chen, Yingting Huang
 */
#include "xdfimport.h"

#include <stack>
#include <iomanip>
#include <unordered_set>
#include <sstream>
PdfImporter::PdfImporter():of("out.txt")
{
    loadFileConfig();
}

PdfImporter::~PdfImporter()
{
    fileConfig.close();
}

void PdfImporter::loadFileConfig()
{
    std::string sFileName("./../../../config/graphics_operator_list.conf");
    fileConfig.open(sFileName);
    if(!fileConfig.good())
    {
        std::string sErrorMessage;
        sErrorMessage += "\n  Cannot open the config file:";
        sErrorMessage += sFileName;
        sErrorMessage += "\n";
        throw sErrorMessage;
    }
    const int MAX_CHARS_PER_LINE = 256;
    int lineCount = 0;
    while(!fileConfig.eof())
    {
        char pszLine[MAX_CHARS_PER_LINE];
        fileConfig.getline(pszLine, MAX_CHARS_PER_LINE);
        lineCount++;
        if (pszLine[0] == '#' || pszLine[0] == 0)
            continue; //Lines starting with a # are comments
        std::string sLine(pszLine);
        std::istringstream ssLine(sLine);
        std::string sNameOperator;
        int numOperands;
        std::getline(ssLine, sNameOperator, ',');
        ssLine >> numOperands;
        if (numOperands>10 || numOperands<0)
        {
            std::string sErrorMessage;
            sErrorMessage += "\n  Error occurred while parsing line #";
            sErrorMessage += std::to_string(lineCount);
            sErrorMessage += " of file ";
            sErrorMessage += sFileName;
            sErrorMessage += "\n  Number of operands is out of range " ;
            throw sErrorMessage;
        }
#ifdef PDF_IMPORT_TEST_MODE
        std::cout << "Found graphics operator in the config file: " \
                  << sNameOperator << ", " \
                  << numOperands << '\n';
#endif
        mapPdfGraphicsObj[sNameOperator].numOperands = numOperands;
    }
}

void PdfImporter::Init( const char* pszInput )
{
    if( !pszInput )
    {
        PODOFO_RAISE_ERROR( ePdfError_InvalidHandle );
    }
    
    PdfMemDocument document( pszInput );
    
    int nCount = document.GetPageCount();
    for( int i=0; i<nCount; i++ )
    {
        PdfPage* pPage = document.GetPage( i );
        if (i==0)
        {
            const PdfRect& rPageSize = pPage -> GetPageSize();
            of << "Page size:\n  " <<
            "Bottom: " << rPageSize.GetBottom() << "  " <<
            "Left: " << rPageSize.GetLeft() << "  " <<
            "Width: " << rPageSize.GetWidth() << "  " <<
            "Height: " << rPageSize.GetHeight() << "\n\n";
            this->ImportPage( &document, pPage );
        }
    }
#ifdef PDF_IMPORT_TEST_MODE

    cout<<"operator found:\n";
    for(auto it = this->Operator_set.begin();it!=this->Operator_set.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
    
    cout<<"operator found but not handled yet:\n";
    for(auto it = this->Operator_set_not_handled.begin();it!=this->Operator_set_not_handled.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
#endif

}

void PdfImporter::ImportPage( PdfMemDocument* pDocument, PdfPage* pPage )
{
    const char*      pszToken = NULL;
    PdfVariant       var;
    EPdfContentsType eType;
    
    PdfContentsTokenizer tokenizer( pPage );
    
    double dCurPosX     = 0.0;
    double dCurPosY     = 0.0;
    //double dX, dY;
    bool   bTextBlock   = false;
    PdfFont* pCurFont   = NULL;
    
    std::stack<PdfVariant> stack;
    
    while( tokenizer.ReadNext( eType, pszToken, var ) )
    {
        
        if( eType == ePdfContentsType_Keyword )
        {
#ifdef PDF_IMPORT_TEST_MODE
            this->Operator_set.emplace(string(pszToken));
#endif
            mapPdfObj_t::iterator it = mapPdfGraphicsObj.find(pszToken);
            if (it != mapPdfGraphicsObj.end())
            {

            }
            else if( strcmp( pszToken, "BT" ) == 0 )
            {
                // BT = begin a new txt obj
                bTextBlock   = true;
                // BT does not reset font
                // pCurFont     = NULL;
            }
            else if( strcmp( pszToken, "ET" ) == 0 )
            {
                if( !bTextBlock )
                    fprintf( stderr, "WARNING: Found ET without BT!\n" );
            }
            else if( strcmp( pszToken, "Tm" ) == 0 )
            {
                //stack.pop(); stack.pop(); stack.pop();stack.pop();
                dCurPosY = stack.top().GetReal();
                stack.pop(); //stack.pop();
                dCurPosX = stack.top().GetReal();
                stack.pop();
                // of << '(' << setprecision(3) << dCurPosX << ',' << dCurPosX << ") " << '\n';
            }
            else if( strcmp( pszToken, "Td" ) == 0 || strcmp( pszToken, "TD" ) == 0)
                of << "\n";
            else if( strcmp( pszToken, "T*" ) == 0 )
                of << "\n";
            else {
                Operator_set_not_handled.emplace(string(pszToken));
            }
            
            if( bTextBlock )
            {
                // Tf = font size page247
                if( strcmp( pszToken, "Tf" ) == 0 )
                {
                    stack.pop();
                    PdfName fontName = stack.top().GetName();
                    PdfObject* pFont = pPage->GetFromResources( PdfName("Font"), fontName );
                    if( !pFont )
                    {
                        PODOFO_RAISE_ERROR_INFO( ePdfError_InvalidHandle, "Cannot create font!" );
                    }
                    
                    pCurFont = pDocument->GetFont( pFont );
                    if( !pCurFont )
                    {
                        fprintf( stderr, "WARNING: Unable to create font for object %i %i R\n",
                                pFont->Reference().ObjectNumber(),
                                pFont->Reference().GenerationNumber() );
                    }
                }
                else if( strcmp( pszToken, "Tj" ) == 0 ||
                        strcmp( pszToken, "'" ) == 0 )
                {
                    AddTextElement( dCurPosX, dCurPosY, pCurFont, stack.top().GetString() );
                    stack.pop();
                }
                else if( strcmp( pszToken, "\"" ) == 0 )
                {
                    AddTextElement( dCurPosX, dCurPosY, pCurFont, stack.top().GetString() );
                    stack.pop();
                    stack.pop(); // remove char spacing from stack
                    stack.pop(); // remove word spacing from stack
                }
                else if( strcmp( pszToken, "TJ" ) == 0 )
                {
                    PdfArray array = stack.top().GetArray();
                    stack.pop();
                    
                    for( int i=0; i<static_cast<int>(array.GetSize()); i++ )
                    {
                        if( array[i].IsString() || array[i].IsHexString() )
                            AddTextElement( dCurPosX, dCurPosY, pCurFont, array[i].GetString() );
                    }
                }
            }
        }
        else if ( eType == ePdfContentsType_Variant )
        {
            stack.push( var );
        }
        else
        {
            // Impossible; type must be keyword or variant
            PODOFO_RAISE_ERROR( ePdfError_InternalLogic );
        }
    }
}

void PdfImporter::AddTextElement( double dCurPosX, double dCurPosY,
                                 PdfFont* pCurFont, const PdfString & rString )
{
    static double dCurPosX_old, dCurPosY_old;
    if( !pCurFont )
    {
        fprintf( stderr, "WARNING: Found text but do not have a current font: %s\n", rString.GetString() );
        return;
    }
    
    if( !pCurFont->GetEncoding() )
    {
        fprintf( stderr, "WARNING: Found text but do not have a current encoding: %s\n", rString.GetString() );
        return;
    }
    
    // For now just write to console
    PdfString unicode = pCurFont->GetEncoding()->ConvertToUnicode( rString, pCurFont );
    const char* pszData = unicode.GetStringUtf8().c_str();
    while( *pszData ) {
        //printf("%02x", static_cast<unsigned char>(*pszData) );
        ++pszData;
    }
    if (dCurPosX_old != dCurPosX || dCurPosY_old != dCurPosY)
        of << "\n[Move Cursor to: (" << setprecision(5) << dCurPosX << ',' << dCurPosY << ")]" << '\n';
    of << unicode.GetStringUtf8().c_str();//<<unicode.GetLength();
    //of << unicode.GetString();
    dCurPosX_old = dCurPosX;
    dCurPosY_old = dCurPosY;
}
