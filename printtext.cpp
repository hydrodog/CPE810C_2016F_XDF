#include "printtext.hh"
#include "frameandtext.hh"
#include "pprint.hh"
//uncomplete @fan
void PPrint::printtext()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog dialog(&printer);
    dialog.setWindowTitle("Print Document");

    if (isPDF){//if the user want PDF output directly
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("printXDF.pdf");
    }
    else{
        printer.setOutputFormat(QPrinter::NativeFormat);
        if(dialog.exec()==QDialog::Accepted){ //what printer do you wanna use
            }
    }
    //initial setting for printer
   QPainter painter;
   painter.begin(&printer);
   Content Sample;
   list<char> SampleText;
     SampleText = sample.exportContent();
   list<myFont> SampleFont;
       SampleFont = sample.contentFont();
   for(int PageNum=endPageNum;PageNum>=startPageNum;PageNum--){
    for(list<char>::iterator it = SampleText.begin(); it!=SampleText.end(); it++)
    {
        for(list<myFont>::iterator it2 = SampleText.begin(); it2!=SampleText.end(); it2++){
        QString str, L;
        int S,B;
        QPainter painter;
        bool I, U;
        str = *it;
        L = it2.getLanguage();
        S = *it2.getSize();
        B = *it2.getBold();
        I = *it2.getItalic();
        QFont font(L, S, B, I);// QFont::QFont(const QString & family, int pointSize = -1, int weight = -1, bool italic = false)
        font.setUnderline( U );//setting of underline
        //font.setOverline(   );//setting of overline
        font.setCapitalization(QFont::SmallCaps );//setting the capitalization (Given data is not clear)
        font.setLetterSpacing(QFont::AbsoluteSpacing, 10);//setting the letter spacing (Given data is not clear)
        //Complete the setting of text font
        painter.setFont(font);
        painter.drawText(100,100, str);// setting the position for letter and print
    }
    }
    if(PageNum!=startPageNum)
        printer.newPage();
   }
   painter.end();
}
