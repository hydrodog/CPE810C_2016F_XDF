/*
 * Author: Dominik Seichter
 * Edited by: Zhuo Chen, Yingting Huang
 */
#include "xdfimport.h"

#include <stack>
#include <iomanip>
#include <unordered_set>
PdfImporter::PdfImporter():of("out.txt")
{
    
}

PdfImporter::~PdfImporter()
{
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
    cout<<"operator found:\n";
    for(auto it = this->Operator_set.begin();it!=this->Operator_set.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
    
    cout<<"operator found but not handled yet:\n";
    for(auto it = this->Operator_set_not_handled.begin();it!=this->Operator_set_not_handled.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
}

void PdfImporter::ImportPage( PdfMemDocument* pDocument, PdfPage* pPage )
{
    const char*      pszToken = NULL;
    PdfVariant       var;
    EPdfContentsType eType;
    
    PdfContentsTokenizer tokenizer( pPage );
    
    double dCurPosX     = 0.0;
    double dCurPosY     = 0.0;
    double dCurPosX1     = 0.0;
    double dCurPosY1     = 0.0;
    double dCurPosX2     = 0.0;
    double dCurPosY2     = 0.0;
    double dCurPosX3     = 0.0;
    double dCurPosY3     = 0.0;
    double width     = 0.0;
    double height     = 0.0;
    //double dX, dY;
    bool   bTextBlock   = false;
    PdfFont* pCurFont   = NULL;
    
    std::stack<PdfVariant> stack;
    
    while( tokenizer.ReadNext( eType, pszToken, var ) )
    {
        
        if( eType == ePdfContentsType_Keyword )
        {
            this->Operator_set.emplace(string(pszToken));
            // of << pszToken << '\n';
            // support 'l' and 'm' tokens
            
            //m = Begin a new subpath by moving the current point to x y  page226
            //l = Append a straight line segment from the current point to xy page226
            if( strcmp( pszToken, "l" ) == 0 ||
               strcmp( pszToken, "m" ) == 0 )
            {
                dCurPosX = stack.top().GetReal();
                stack.pop();
                dCurPosY = stack.top().GetReal();
                stack.pop();
                of <<"["<<pszToken<< '(' << setprecision(3) << dCurPosY << ',' << dCurPosX << ")] " << '\n';
            }
            else if( strcmp( pszToken, "c" ) == 0)
            {
                dCurPosY3 = stack.top().GetReal();
                stack.pop();
                dCurPosX3 = stack.top().GetReal();
                stack.pop();
                dCurPosY2 = stack.top().GetReal();
                stack.pop();
                dCurPosX2 = stack.top().GetReal();
                stack.pop();
                dCurPosY1 = stack.top().GetReal();
                stack.pop();
                dCurPosX1 = stack.top().GetReal();
                stack.pop();
                of <<"["<<pszToken<< '(' << setprecision(3) << dCurPosX1 << ',' << dCurPosY1 <<','
                <<dCurPosX2 << ',' << dCurPosY2 <<','
                <<dCurPosX3 << ',' << dCurPosY3 <<',' << ")] " << '\n';
            }

            else if( strcmp( pszToken, "q" ) == 0)
            {
                
                of <<"["<<pszToken<< ']' <<" //Save graphics state \n";
            }
            else if( strcmp( pszToken, "Q" ) == 0)
            {
                
                of <<"["<<pszToken<< ']' <<" //Restore graphics state \n";
            }

            else if( strcmp( pszToken, "Do" ) == 0)
            {
                cout<<"\nhere is a Do , let's see its variant 's type : "<<string(stack.top().GetDataTypeString())<<endl;
                string token;
                stack.top().ToString(token);
                of <<"["<<pszToken<< "("<<token<<")] //name \n";
                stack.pop();
            }

            else if( strcmp( pszToken, "cm" ) == 0)
            {
                
                dCurPosY3 = stack.top().GetReal();
                stack.pop();
                dCurPosX3 = stack.top().GetReal();
                stack.pop();
                dCurPosY2 = stack.top().GetReal();
                stack.pop();
                dCurPosX2 = stack.top().GetReal();
                stack.pop();
                dCurPosY1 = stack.top().GetReal();
                stack.pop();
                dCurPosX1 = stack.top().GetReal();
                stack.pop();
                of <<"["<<pszToken<< '(' << setprecision(3) << dCurPosX1 << ',' << dCurPosY1 <<','
                <<dCurPosX2 << ',' << dCurPosY2 <<','
                <<dCurPosX3 << ',' << dCurPosY3 <<',' << ")] //Modify the current transformation matrix" << '\n';
            }
            
            else if( strcmp( pszToken, "v" ) == 0)
            {
                dCurPosY3 = stack.top().GetReal();
                stack.pop();
                dCurPosX3 = stack.top().GetReal();
                stack.pop();
                dCurPosY2 = stack.top().GetReal();
                stack.pop();
                dCurPosX2 = stack.top().GetReal();
                stack.pop();
                
                of <<"["<<pszToken<< '(' << setprecision(3)
                <<dCurPosX2 << ',' << dCurPosY2 <<','
                <<dCurPosX3 << ',' << dCurPosY3 << ")] " << '\n';
            }
            else if( strcmp( pszToken, "y" ) == 0)
            {
                dCurPosY3 = stack.top().GetReal();
                stack.pop();
                dCurPosX3 = stack.top().GetReal();
                stack.pop();
                dCurPosY1 = stack.top().GetReal();
                stack.pop();
                dCurPosX1 = stack.top().GetReal();
                stack.pop();
                
                of <<"["<<pszToken<< '(' << setprecision(3)
                <<dCurPosX1 << ',' << dCurPosY1 <<','
                <<dCurPosX3 << ',' << dCurPosY3 << ")] " << '\n';
            }
            else if( strcmp( pszToken, "h" ) == 0)
            {
                
                of <<"["<<pszToken<<"]\n";
            }
            
            else if( strcmp( pszToken, "re" ) == 0)
            {
                height = stack.top().GetReal();
                stack.pop();
                width = stack.top().GetReal();
                stack.pop();
                dCurPosY = stack.top().GetReal();
                stack.pop();
                dCurPosX = stack.top().GetReal();
                stack.pop();
                
                of <<"["<<pszToken<< '(' << setprecision(3)
                <<dCurPosX << ',' << dCurPosY <<','
                <<width << ',' << height << ")] " << '\n';
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
            
            // {
            //     Operator_set_not_handled.emplace(string(pszToken));
            
            // }
            
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
