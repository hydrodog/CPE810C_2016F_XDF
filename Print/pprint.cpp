#include <pprint.hh>

PPrint::PPrint() {
    startPageNum=0;
    endPageNum=0;
    totalPageNum=0;//initiate all private members

}

void PPrint::PProcess(){
    print();
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
                painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 哈哈哈哈");//Just test code in case other team fuck up
                if(PageNum!=startPageNum)
                    printer.newPage();
            }
            painter.end();
        }
        else if(isOdd==1){//means odd pages printed
            if(endPageNum%2==0)//end page is even page
                endPageNum--;//switch to odd page
                for(int PageNum=endPageNum;PageNum>=startPageNum;PageNum=PageNum-2){
                    painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 哈哈哈哈");//Just test code in case other team fuck up
                    if(PageNum!=startPageNum)
                        printer.newPage();
                }
            painter.end();
        }
        else if(isOdd==2){//means even pages printed
            if(endPageNum%2!=0)//end page is odd page
                endPageNum--;//switch to odd page
                for(int PageNum=endPageNum;PageNum>=startPageNum;PageNum=PageNum-2){
                    painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 哈哈哈哈");//Just test code in case other team fuck up
                    if(PageNum!=startPageNum)
                        printer.newPage();
                }
            painter.end();
        }
        else
            throw ("/nPrivate member isOdd number is wrong, in pprint::print");

    }

    else {
        QPainter painter;
        painter.begin(&printer);
        if(isOdd==0){
            for(int PageNum=startPageNum;PageNum<=endPageNum;PageNum++){
                painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 55哈哈哈");//Just test code in case other teams fuck up
                if(PageNum!=endPageNum)
                    printer.newPage();
              }
            painter.end();
        }
        else if(isOdd==1){
            if(endPageNum%2==0)//end page is even page
                endPageNum++;//switch to odd page
            for(int PageNum=startPageNum;PageNum<=endPageNum;PageNum=PageNum+2){
                painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 55哈哈哈");//Just test code in case other teams fuck up
                if(PageNum!=endPageNum)
                    printer.newPage();
              }
            painter.end();
        }
        else if(isOdd==2){
            if(endPageNum%2!=0)//end page is odd page
                endPageNum++;//switch to even page
            for(int PageNum=startPageNum;PageNum<=endPageNum;PageNum=PageNum+2){
                painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 55哈哈哈");//Just test code in case other teams fuck up
                if(PageNum!=endPageNum)
                    printer.newPage();
              }
            painter.end();
        }//
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
                painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 哈哈哈哈");//Just test code in case other team fuck up
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
                  painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 55哈哈哈");//Just test code in case other team fuck up
                  if(PageNum!=endPageNum)
                      printer.newPage();//TODO: need to debug, always have an extra page
              }
              painter.end();
            }
//        }
 //  }
#endif
}
