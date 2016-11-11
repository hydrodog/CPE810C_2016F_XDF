#include <pprint.hh>

PPrint::PPrint(int total, int start, int end) {}

void PPrint::PProcess(){
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog dialog(&printer);
    dialog.setWindowTitle("Print Document");
    if(dialog.exec()==QDialog::Accepted){
        printer.setOutputFormat(QPrinter::NativeFormat);
       // printer.setOutputFileName("print.pdf");
        QPainter painter;
        painter.begin(&printer);


        for(int page=0;page<4;++page){
            painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 哈哈哈哈");
            if(page!=4)
                printer.newPage();
        }
        painter.end();
    }
}
