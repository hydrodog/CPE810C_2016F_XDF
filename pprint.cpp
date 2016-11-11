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
    if(dialog.exec()==QDialog::Accepted){
        printer.setOutputFormat(QPrinter::NativeFormat);
       // printer.setOutputFileName("print.pdf");
        QPainter painter;
        painter.begin(&printer);
        for(int page=startPageNum;PageNum<endPageNum;++page){
            //painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 哈哈哈哈");//Just test code in case other team fuck up
            if(page!=endPageNum)
                printer.newPage();
        }
        painter.end();
    }
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

