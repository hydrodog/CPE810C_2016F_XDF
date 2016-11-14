#include <pprint.hh>

PPrint::PPrint() {
    startPageNum=0;
    endPageNum=0;
    totalPageNum=0;//initiate all private members

}

void PPrint::PProcess(){
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog dialog(&printer);
    dialog.setWindowTitle("Print Document");
#if 0
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
#endif
          if(dialog.exec()==QDialog::Accepted){              
              }
          printer.setOutputFormat(QPrinter::NativeFormat);
         // printer.setOutputFileName("print.pdf");
          QPainter painter;
          painter.begin(&printer);
          for(int PageNum=0;PageNum<=5;PageNum++){
              painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 55哈哈哈");//Just test code in case other team fuck up
              if(PageNum!=endPageNum)
                  printer.newPage();
              painter.end();
            }
//        }
 //  }
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

}
