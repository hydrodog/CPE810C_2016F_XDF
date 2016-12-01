#include <pprint.hh>
#include <list>
#include <QString>

using namespace std;
PPrint::PPrint() {
    startPageNum=0;
    endPageNum=0;
    totalPageNum=0;//initiate all private members

}

void PPrint::PProcess(){
    print();
    //printtext(Text & sampleText);
}

void PPrint::setEndPageNum(int num){
    endPageNum=num;
}

void PPrint::setStartPageNum(int num){
    startPageNum=num;
}

void PPrint::setTotalPageNum(int num){
    totalPageNum=num;
}

void PPrint::setIsOdd(int num){
    isOdd=num;
}

void PPrint::setIsReverse(bool num){
    isReverse=num;
}

void PPrint::setIsPDF(bool is)
{
    isPDF=is;
}

void PPrint::print(){
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
    if(isReverse){//if the user wanna print from end to begin
        QPainter painter;
        painter.begin(&printer);
        if(isOdd==0){//means normal print
            for(int PageNum=endPageNum;PageNum>=startPageNum;PageNum--){
                QString str = "123456,酷哥酷哥酷哥handsome,handsome,handsome_@¥AAA111111111111111111111111111111111111";
                //test sampe 1
                const QRect r1(0,0,2000,400);
                //QRect boundingRect;
                QTextOption option(Qt::AlignLeft);

                QFont font("Greek",20,QFont::Bold, true);
                font.setUnderline(false);// the setting of the underline
                font.setOverline(false);// the setting of the overline
                font.setCapitalization(QFont::SmallCaps);
                font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                painter.setFont(font);
                painter.setPen(Qt::red);
                painter.drawText(r1, str, option);
                int Y = r1.height();
                //painter.drawtext(120,80,100,Qt::AlignLeft, str, QRect * boundingRect = 0);
                //painter.drawText(120,80,str);//Just test code in case other team fuck up

                //test sample 2
                const QRect r2(0,Y,2000,2000);
                QFont font2("Latin",20,QFont::Bold, false);
                font.setUnderline(true);// the setting of the underline
                font.setOverline(false);// the setting of the overline
                font.setCapitalization(QFont::MixedCase);//MixedCase, AllUppercase,AllLowercase,SmallCaps,Capitalize
                font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                //PercentageSpacing,AbsoluteSpacingA positive value increases the letter spacing by the corresponding pixels; a negative value decreases the spacing.()
                painter.setFont(font2);
                painter.setPen(Qt::blue);
                painter.drawText(r2, str, option);
                if(PageNum!=startPageNum)
                    printer.newPage();
            }
            painter.end();
        }
        else if(isOdd==1){//means odd pages printed
            if(endPageNum%2==0)//end page is even page
                endPageNum--;//switch to odd page
                for(int PageNum=endPageNum;PageNum>=startPageNum;PageNum=PageNum-2){
                    QString str = "123456,酷哥酷哥酷哥handsome,handsome,handsome_@¥AAA111111111111111111111111111111111111";
                    //test sampe 1
                    const QRect r1(0,0,2000,400);
                    //QRect boundingRect;
                    QTextOption option(Qt::AlignLeft);

                    QFont font("Greek",20,QFont::Bold, true);
                    font.setUnderline(false);// the setting of the underline
                    font.setOverline(false);// the setting of the overline
                    font.setCapitalization(QFont::SmallCaps);
                    font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                    painter.setFont(font);
                    painter.setPen(Qt::red);
                    painter.drawText(r1, str, option);
                    int Y = r1.height();
                    //painter.drawtext(120,80,100,Qt::AlignLeft, str, QRect * boundingRect = 0);
                    //painter.drawText(120,80,str);//Just test code in case other team fuck up

                    //test sample 2
                    const QRect r2(0,Y,2000,2000);
                    QFont font2("Latin",20,QFont::Bold, false);
                    font.setUnderline(true);// the setting of the underline
                    font.setOverline(false);// the setting of the overline
                    font.setCapitalization(QFont::MixedCase);//MixedCase, AllUppercase,AllLowercase,SmallCaps,Capitalize
                    font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                    //PercentageSpacing,AbsoluteSpacingA positive value increases the letter spacing by the corresponding pixels; a negative value decreases the spacing.()
                    painter.setFont(font2);
                    painter.setPen(Qt::blue);
                    painter.drawText(r2, str, option);
                    if(PageNum!=startPageNum)
                        printer.newPage();
                }
            painter.end();
        }
        else if(isOdd==2){//means even pages printed
            if(endPageNum%2!=0)//end page is odd page
                endPageNum--;//switch to odd page
                for(int PageNum=endPageNum;PageNum>=startPageNum;PageNum=PageNum-2){
                    QString str = "123456,酷哥酷哥酷哥handsome,handsome,handsome_@¥AAA111111111111111111111111111111111111";
                    //test sampe 1
                    const QRect r1(0,0,2000,400);
                    //QRect boundingRect;
                    QTextOption option(Qt::AlignLeft);

                    QFont font("Greek",20,QFont::Bold, true);
                    font.setUnderline(false);// the setting of the underline
                    font.setOverline(false);// the setting of the overline
                    font.setCapitalization(QFont::SmallCaps);
                    font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                    painter.setFont(font);
                    painter.setPen(Qt::red);
                    painter.drawText(r1, str, option);
                    int Y = r1.height();
                    //painter.drawtext(120,80,100,Qt::AlignLeft, str, QRect * boundingRect = 0);
                    //painter.drawText(120,80,str);//Just test code in case other team fuck up

                    //test sample 2
                    const QRect r2(0,Y,2000,2000);
                    QFont font2("Latin",20,QFont::Bold, false);
                    font.setUnderline(true);// the setting of the underline
                    font.setOverline(false);// the setting of the overline
                    font.setCapitalization(QFont::MixedCase);//MixedCase, AllUppercase,AllLowercase,SmallCaps,Capitalize
                    font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                    //PercentageSpacing,AbsoluteSpacingA positive value increases the letter spacing by the corresponding pixels; a negative value decreases the spacing.()
                    painter.setFont(font2);
                    painter.setPen(Qt::blue);
                    painter.drawText(r2, str, option);
                    if(PageNum!=startPageNum)
                        printer.newPage();
                }
            painter.end();
        }
        else
            throw ("/nPrivate member isOdd number is wrong, in pprint::print");

    }

    else {//print forward
        QPainter painter;
        painter.begin(&printer);
        if(isOdd==0){

            for(int PageNum=startPageNum;PageNum<=endPageNum;PageNum++){

                QString str = "123456,酷哥酷哥酷哥handsome,handsome,handsome_@¥AAA111111111111111111111111111111111111";
                //test sampe 1
                const QRect r1(0,0,2000,400);
                //QRect boundingRect;
                QTextOption option(Qt::AlignLeft);

                QFont font("Greek",20,QFont::Bold, true);
                font.setUnderline(false);// the setting of the underline
                font.setOverline(false);// the setting of the overline
                font.setCapitalization(QFont::SmallCaps);
                font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                painter.setFont(font);
                painter.setPen(Qt::red);
                painter.drawText(r1, str, option);
                int Y = r1.height();
                //painter.drawtext(120,80,100,Qt::AlignLeft, str, QRect * boundingRect = 0);
                //painter.drawText(120,80,str);//Just test code in case other team fuck up

                //test sample 2
                const QRect r2(0,Y,2000,2000);
                QFont font2("Latin",20,QFont::Bold, false);
                font.setUnderline(true);// the setting of the underline
                font.setOverline(false);// the setting of the overline
                font.setCapitalization(QFont::MixedCase);//MixedCase, AllUppercase,AllLowercase,SmallCaps,Capitalize
                font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                //PercentageSpacing,AbsoluteSpacingA positive value increases the letter spacing by the corresponding pixels; a negative value decreases the spacing.()
                painter.setFont(font2);
                painter.setPen(Qt::blue);
                painter.drawText(r2, str, option);
//                painter.drawText(120,160,str);
//                painter.translate(50,50);
//                painter.rotate(90);
//                painter.drawText(0,0,str);
                if(PageNum!=endPageNum)
                    printer.newPage();
              }
            painter.end();
        }
        else if(isOdd==1){
            if(endPageNum%2==0)//end page is even page
                endPageNum++;//switch to odd page
            for(int PageNum=startPageNum;PageNum<=endPageNum;PageNum=PageNum+2){
                QString str = "123456,酷哥酷哥酷哥handsome,handsome,handsome_@¥AAA111111111111111111111111111111111111";
                //test sampe 1
                const QRect r1(0,0,2000,400);
                //QRect boundingRect;
                QTextOption option(Qt::AlignLeft);

                QFont font("Greek",20,QFont::Bold, true);
                font.setUnderline(false);// the setting of the underline
                font.setOverline(false);// the setting of the overline
                font.setCapitalization(QFont::SmallCaps);
                font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                painter.setFont(font);
                painter.setPen(Qt::red);
                painter.drawText(r1, str, option);
                int Y = r1.height();
                //painter.drawtext(120,80,100,Qt::AlignLeft, str, QRect * boundingRect = 0);
                //painter.drawText(120,80,str);//Just test code in case other team fuck up

                //test sample 2
                const QRect r2(0,Y,2000,2000);
                QFont font2("Latin",20,QFont::Bold, false);
                font.setUnderline(true);// the setting of the underline
                font.setOverline(false);// the setting of the overline
                font.setCapitalization(QFont::MixedCase);//MixedCase, AllUppercase,AllLowercase,SmallCaps,Capitalize
                font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                //PercentageSpacing,AbsoluteSpacingA positive value increases the letter spacing by the corresponding pixels; a negative value decreases the spacing.()
                painter.setFont(font2);
                painter.setPen(Qt::blue);
                painter.drawText(r2, str, option);
                if(PageNum!=endPageNum)
                    printer.newPage();
              }
            painter.end();
        }
        else if(isOdd==2){
            if(endPageNum%2!=0)//end page is odd page
                endPageNum++;//switch to even page
            for(int PageNum=startPageNum;PageNum<=endPageNum;PageNum=PageNum+2){
                QString str = "123456,酷哥酷哥酷哥handsome,handsome,handsome_@¥AAA111111111111111111111111111111111111";
                //test sampe 1
                const QRect r1(0,0,2000,400);
                //QRect boundingRect;
                QTextOption option(Qt::AlignLeft);

                QFont font("Greek",20,QFont::Bold, true);
                font.setUnderline(false);// the setting of the underline
                font.setOverline(false);// the setting of the overline
                font.setCapitalization(QFont::SmallCaps);
                font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                painter.setFont(font);
                painter.setPen(Qt::red);
                painter.drawText(r1, str, option);
                int Y = r1.height();
                //painter.drawtext(120,80,100,Qt::AlignLeft, str, QRect * boundingRect = 0);
                //painter.drawText(120,80,str);//Just test code in case other team fuck up

                //test sample 2
                const QRect r2(0,Y,2000,2000);
                QFont font2("Latin",20,QFont::Bold, false);
                font.setUnderline(true);// the setting of the underline
                font.setOverline(false);// the setting of the overline
                font.setCapitalization(QFont::MixedCase);//MixedCase, AllUppercase,AllLowercase,SmallCaps,Capitalize
                font.setLetterSpacing(QFont::AbsoluteSpacing,10);
                //PercentageSpacing,AbsoluteSpacingA positive value increases the letter spacing by the corresponding pixels; a negative value decreases the spacing.()
                painter.setFont(font2);
                painter.setPen(Qt::blue);
                painter.drawText(r2, str, option);
                if(PageNum!=endPageNum)
                    printer.newPage();
              }
            painter.end();
        }//er
    }

#if 0//save the original print code just in case @Zejian
    if(isReverse){//if you wanna print from end to begin
        if(isPDF){}//TODO: is pdf? I need to deal with paint class now @Zejian

        if(dialog.exec()==QDialog::Accepted){
            printer.setOutputFormat(QPrinter::NativeFormat);
           // printer.setOutputFileName("print.pdf");
            QPainter painter;
            painter.begin(&printer);
            for(int PageNum=endPageNum;PageNum>=startPageNum;PageNum--){
                painter.drawText(1000, 1000, str);//Just test code in case other team fuck up
                if(PageNum!=startPageNum)
                    printer.newPage();
            }
            painter.end();
        }
    else{

          if(dialog.exec()==QDialog::Accepted){
              printer.setOutputFormat(QPrinter::NativeFormat);
             // printer.setOutputFileName("print.pdf");
              QPainter painter;
              painter.begin(&printer);
              for(int PageNum=0;PageNum<=5;PageNum++){
                  painter.drawText(1000, 1000, str);//Just test code in case other team fuck up
                  if(PageNum!=endPageNum)
                      printer.newPage();//TODO: need to debug, always have an extra page
              }
              painter.end();
            }
//        }
 //  }
#endif
}
