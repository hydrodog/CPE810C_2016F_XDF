
#include <QtWidgets/QApplication>
#include <string>
#include <vector>
#include <iostream>

#include "xdfgraphics_includes.h"
#include "pdfimport.h"
/*
 @author: Seito Ryu  11/20/16    "Reading data and store data"
 @modifer: Bingyang Wen 12/2/16
 @modifer: Bo fan       12/2/16
                                  "Enable drawing function with given data"

 */

// For test of graphics group's code with PDF's
class test_XdfGraphics: public PdfImporter
{
public:
    test_XdfGraphics(): pTwoDGraphics(new twoDGraphics("D:\EE810_Project","test.txt"))
    {
    }
    ~test_XdfGraphics()
    {
        delete pTwoDGraphics;
    }
    virtual void AddTextElement( double dCurPosX, double dCurPosY,
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

        PdfString unicode = pCurFont->GetEncoding()->ConvertToUnicode( rString, pCurFont );
        static std::string text;

        if (dCurPosX_old != dCurPosX || dCurPosY_old != dCurPosY)
        {
            pTwoDGraphics->addTextBox(textBox(QPointF(dCurPosX_old, dCurPosY_old), text));
            text.clear();
        }
        text += unicode.GetStringUtf8();
        dCurPosX_old = dCurPosX;
        dCurPosY_old = dCurPosY;
    }

    virtual void addGraphicsOperation(std::string operatorName, \
                                      std::vector<double> operands)
    {
        pTwoDGraphics->setShape(operatorName, operands);
    }
    twoDGraphics* getTwoDGraphics()
    {
        return pTwoDGraphics;
    }

private:
    twoDGraphics* pTwoDGraphics;
};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    char* pszPdfPath = "../../CPE810C_2016F_XDF/pdf/samples/sample1.pdf";
    try {
        test_XdfGraphics importer;
        importer.Init( pszPdfPath );
        //importer.getXDoc();
        ToD m(importer.getTwoDGraphics());
        m.show();
        return a.exec();
    } catch( PdfError & e ) {
        fprintf( stderr, "Error: An error %i ocurred during processing the pdf file.\n", e.GetError() );
        e.PrintErrorMsg();
        return e.GetError();
    } catch(char const * pszErrorMessage) {
        std::cout << "Error occurred while importing a pdf file:" << pszErrorMessage << endl;
        return 1;
    } catch(string & sErrorMessage) {
        std::cout << "Error occurred while importing a pdf file:" << sErrorMessage << endl;
        return 1;
    }


}
