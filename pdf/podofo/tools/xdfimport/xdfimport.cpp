/*
 * Author: Dominik Seichter
 * Edited by: Zhuo Chen, Yingting Huang
*/
#include "xdfimport.h"

#include <stack>
#include <iomanip>
TextExtractor::TextExtractor():of("out.txt")
{

}

TextExtractor::~TextExtractor()
{
}

void TextExtractor::Init( const char* pszInput )
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

            this->ExtractText( &document, pPage );
        }
    }
}

void TextExtractor::ExtractText( PdfMemDocument* pDocument, PdfPage* pPage ) 
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
            // of << pszToken << '\n';
            // support 'l' and 'm' tokens
            if( strcmp( pszToken, "l" ) == 0 || 
                strcmp( pszToken, "m" ) == 0 )
            {
                // dCurPosX = stack.top().GetReal();
                stack.pop();
                // dCurPosY = stack.top().GetReal();
                stack.pop();
                //of << '(' << setprecision(3) << dCurPosX << ',' << dCurPosY << ") " << '\n';
            }
            else if( strcmp( pszToken, "BT" ) == 0 ) 
            {
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

            if( bTextBlock ) 
            {
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

void TextExtractor::AddTextElement( double dCurPosX, double dCurPosY, 
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
