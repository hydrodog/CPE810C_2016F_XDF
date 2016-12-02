#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include <QFileDialog>
#include <QDebug>
#include <QFontDialog>
#include <QColorDialog>
#include <QTableWidget>
#include <QPainter>
/** if you have any printer issues: check the .pro file to have
 * QT += printsupport
  */
#include <QPrintDialog>
#include <QPrinter>
#include <QTextImageFormat>
#include <algorithm>
#include <vector>
#include <string>
#include <QFileInfo>
#include <iostream>
#include <time.h>

/**
 * QUESTION: not all buttons on the window have functions yet right?
 *
 */
int MainWindow::fileState=0;

QString MainWindow::s2q(const std::string &s)
{
    return QString(QString::fromLocal8Bit(s.c_str()));
}

std::string MainWindow::q2s(const QString &s)
{
    return std::string((const char *)s.toLocal8Bit());
}
/**
Sets up window name and size
Sets font size in text editor

TODO: talk to frame team to get frames and text functions
currently using a pseudo text editor

NOTE: if you get a textEdit error check your mainwindow.ui that you have the textEdit widget
*/
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("XDF Project");
    this->resize(1300,800);
    ui->textEdit->setFontPointSize(15);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief MainWindow::on_actionOpen_file_triggered
 * Open Files Function:
 * Opens and displays a file from local machine
 *  Accepts .txt and .pdf
 *      .pdf comes out scary
 * Cancel/errors causes a popup "failed to open files"
 *
 * TODO: work with pdf group to get pdf to display
 */
void MainWindow::on_actionOpen_file_triggered()
{
    fileName = QFileDialog::getOpenFileName(this,"Open File","D:","text(*.txt *.pdf)");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,"Open File",tr("Failed to Open Files").arg(file.errorString()));
        MainWindow::fileName="";
        return;
    }
    MainWindow::fileState=HaveOpenFile;
    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->textEdit->setPlainText(in.readAll());
    ui->textEdit->setFontPointSize(15);
    QApplication::restoreOverrideCursor();
    file.close();
    return;
}
/**
 * @brief MainWindow::on_actionSave_as_triggered
 * SaveAs File Function:
 *  popup to get file save destination, name, type (.txt)
 */
void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save File"),"D:",tr("Text files(*.txt)"));
    QFile *file=new QFile;
    file->setFileName(filename);
    bool ok=file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);
        QString text = ui->textEdit->toPlainText();
        text.replace(QString("\n"), QString("\r\n"));
        out<< text;
        file->close();
        delete file;
        MainWindow::fileState=NoState;
    }

}
/**
 * @brief MainWindow::on_actionSave_file_triggered
 * Save File Function:
 *   saves current file name
 *
 * TODO: do we need a function to default to save as if it is a new file?
 */
void MainWindow::on_actionSave_file_triggered(){
    if(MainWindow::fileState==NoState && ui->textEdit->toPlainText()!=""){
        MainWindow::on_actionSave_as_triggered();
    }
    else{
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly|QIODevice::Text)){
            QTextStream out(&file);
            QString text = ui->textEdit->toPlainText();
            text.replace(QString("\n"), QString("\r\n"));
            out<< text;
            file.close();
            MainWindow::fileState=HaveOpenFile;
        }
    }

}
/**
 * @brief MainWindow::on_actionNew_file_triggered
 * New File Function:
 *  Opens a new file
 *      If blank: opens new document
 *      Elseif new doc you made: Popup if you want to save
 *          does save routine or just opens a new doc
 *      Elseif opened doc: popup if you want to save
 *          does save routine or just opens a new doc
 */
void MainWindow::on_actionNew_file_triggered(){
    if(ui->textEdit->toPlainText()==""){
        return;
    }
    if(ui->textEdit->toPlainText()!=""){
        if(MainWindow::fileState==NoState){
            int question1=QMessageBox::question(this,"New File","Do you want to save your work?", QMessageBox::Yes,QMessageBox::No);
            if(question1==QMessageBox::Yes){
                MainWindow::on_actionSave_as_triggered();
                ui->textEdit->clear();
                return;
            }
            else if(question1==QMessageBox::No){
                ui->textEdit->clear();
                return;
            }
        }
        else if(MainWindow::fileState==HaveOpenFile){
            int question2 = QMessageBox::question(this,"New File","Do you want to save your work??",QMessageBox::Yes,QMessageBox::No);
            if(question2==QMessageBox::Yes){
                MainWindow::on_actionSave_file_triggered();
                ui->textEdit->clear();
                MainWindow::fileState=NoState;
                return;
            }
            else if(question2==QMessageBox::No){
                ui->textEdit->clear();
                MainWindow::fileState=NoState;
                return;
            }
        }
    }
}
/**
 * @brief MainWindow::on_actionFont_triggered
 * Text Font Function:
 *  brings up the generic font change dialog box
 *      can change font, style, size, effects, gives preview of what it will look like
 */
void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok) ui->textEdit->setCurrentFont(font);
}
/**
 * @brief MainWindow::on_actionColor_triggered
 * Text Color Function:
 *  brings up color change dialog box
 *      can pick basic color, make custom colors (pic, screen, rbg, hsv, html) custom color tray
 *      preview color choice
 */
void MainWindow::on_actionColor_triggered()
{
    QColorDialog color(this);
    color.setOption(QColorDialog::ShowAlphaChannel);
    color.exec();
    QColor color1=color.currentColor();
    ui->textEdit->setTextColor(color1);
}
/**
 * @brief MainWindow::on_actionCopy_triggered
 * Copy Function
 */
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->QTextEdit::copy();
}
/**
 * @brief MainWindow::on_actionPaste_triggered
 * Paste Function
 */
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->QTextEdit::paste();
}
/**
 * @brief MainWindow::on_actionCut_triggered
 * Cut Function
 */
void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->QTextEdit::cut();
}
/**
 * @brief MainWindow::on_actionImport_image_triggered
 * Import Image Function
 *  Inserts image inline from local machine
 *      accepts .png, .jpg
 *
 * TODO: do we need to add importing from the internet?
 */
void MainWindow::on_actionImport_image_triggered()
{
    imageName = QFileDialog::getOpenFileName(this,tr("Import Image"),"D:",tr("Text files(*.png *.jpg)"));
    QTextImageFormat format;
    format.setName(imageName);
    ui->textEdit->textCursor().insertImage(format);
}
/**
 * @brief MainWindow::on_actionDigital_signature_triggered
 * Digital Signature Function:
 *  Makes a popup with a table with the time, date, and signature
 *      is signature a string of numbers or....
 * TODO: see where digital signature encrytion team is
 *      does anyone else have this problem where it causes the window to crash? or just me?
 */
void MainWindow::on_actionDigital_signature_triggered()
{
    exist_Signture++;
    QTableWidgetItem signture[10];
    QTableWidgetItem time1[10];
    qDebug()<<exist_Signture;
    QDialog a;
    a.resize(500,200);
    QTableWidget table(&a);
    table.resize(500,200);

    int columncount=0;
    if(exist_Signture>=3){
        columncount=exist_Signture;
    }
    else columncount=3;
    table.setRowCount(columncount);
    table.setColumnCount(2);

    for(int i = 0; i < columncount; i++)
        table.setRowHeight(i, 22);
    table.setColumnWidth(0,250);
    table.horizontalHeader()->setStretchLastSection(true);
    table.setSelectionBehavior(QAbstractItemView::SelectItems);
    table.setEditTriggers(QAbstractItemView::DoubleClicked);

    QStringList horizontitle;
    horizontitle << "time" << "signture";
    table.setHorizontalHeaderLabels(horizontitle);
    table.horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

    int loopcount;
    if(exist_Signture>1 && exist_Signture<=10){
        loopcount=exist_Signture-2;
    }
    else if(exist_Signture>10)
        loopcount=10;
    else if(exist_Signture==1)
        loopcount=-1;

    for(int i=0;i<=loopcount;i++){
        signture[i].setText(s2q(Signture[i][1]));
        qDebug()<<s2q(Signture[i][1]);
        //.setFlags(signture[i].flags() & (~Qt::ItemIsEditable));
        time1[i].setText(s2q(Signture[i][0]));
        qDebug()<<s2q(Signture[i][0]);
        //.setFlags(time[i].flags() & (~Qt::ItemIsEditable));
        table.setItem(i,0,&time1[i]);
        table.setItem(i,1,&signture[i]);
    }

    QTableWidgetItem timenew;
    QTableWidgetItem signturenew;

    time_t t;
    time(&t);
    struct tm*now = localtime(&t);
    std::string str=asctime(now);
    Signture[exist_Signture-1][0]=str;
    timenew.setText(s2q(str));


    std::hash<std::string> str_hash;
    QString content = ui->textEdit->toPlainText();
    std::string author="Xi";
    std::string signture1 = std::to_string(str_hash(std::to_string(str_hash(author)) + q2s(content)));
    Signture[exist_Signture-1][1]=signture1;
    signturenew.setText(s2q(signture1));

    table.setItem(exist_Signture-1,0,&timenew);
    table.setItem(exist_Signture-1,1,&signturenew);

    table.show();
    a.exec();
}
/**
 * @brief MainWindow::on_actionExport_PDF_triggered
 * Export PDF Function:
 *  brings up save box to save as a pdf with name and location
 *  prints out file as pdf
 */
void MainWindow::on_actionExport_PDF_triggered()
{
    PDFName = QFileDialog::getSaveFileName(this,"Export PDF",QString(),"*.pdf");

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(PDFName);

    ui->textEdit->document()->print(&printer);
}
/**
 * @brief MainWindow::on_actionPrint_triggered
 * Print Function:
 *  brings up print box dialog
 *
 * TODO: talk to print team to see what functions they have
 */
void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog dialog(&printer);
    dialog.setWindowTitle("Print Document");
    if(dialog.exec()==QDialog::Accepted){
        printer.setOutputFormat(QPrinter::NativeFormat);
     // printer.setOutputFileName("print.pdf");
        QPainter painter;
        painter.begin(&printer);

/**
  what does this part do?
  */
        for(int page=0;page<4;++page){
            painter.drawText(1000, 1000, "LET's FUJI CO.LTD 6666 哈哈哈哈");
            if(page!=4)
                printer.newPage();
        }
        painter.end();
    }
}
