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
#include <QPrintDialog>
#include <QPrinter>
#include <QTextImageFormat>
#include <algorithm>
#include <vector>
#include <string>
#include <QFileInfo>
#include <iostream>
#include <time.h>


int MainWindow::fileState=0;

QString MainWindow::s2q(const std::string &s)
{
    return QString(QString::fromLocal8Bit(s.c_str()));
}

std::string MainWindow::q2s(const QString &s)
{
    return std::string((const char *)s.toLocal8Bit());
}

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("XDF project");
    this->resize(800,500);
    ui->textEdit->setFontPointSize(15);
    for (int i=0;i<10;i++){
        for (int j=0;j<2;j++){
            Signture[i][j]="";
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_file_triggered()
{
    fileName = QFileDialog::getOpenFileName(this,"open file","D:","text(*.txt *.pdf)");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,"open file",tr("fail to open files").arg(file.errorString()));
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

void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save Text"),"D:",tr("Text files(*.txt ; *.sst)"));
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

void MainWindow::on_actionNew_file_triggered(){
    if(ui->textEdit->toPlainText()==""){
        return;
    }
    if(ui->textEdit->toPlainText()!=""){
        if(MainWindow::fileState==NoState){
            int question1=QMessageBox::question(this,"new file","do you want to save your work?", QMessageBox::Yes,QMessageBox::No);
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
            int question2 = QMessageBox::question(this,"new file","do you want to save your work??",QMessageBox::Yes,QMessageBox::No);
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

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok) ui->textEdit->setCurrentFont(font);

}

void MainWindow::on_actionColor_triggered()
{
    QColorDialog color(this);
    color.setOption(QColorDialog::ShowAlphaChannel);
    color.exec();
    QColor color1=color.currentColor();
    ui->textEdit->setTextColor(color1);
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->QTextEdit::copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->QTextEdit::paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->QTextEdit::cut();
}

void MainWindow::on_actionImport_image_triggered()
{
    imageName = QFileDialog::getOpenFileName(this,tr("import image"),"D:",tr("Text files(*.png *.jpg)"));
    QTextImageFormat format;
    format.setName(imageName);
    ui->textEdit->textCursor().insertImage(format);
}

void MainWindow::on_actionDigital_signature_triggered()
{
    exist_Signture++;
    QDialog a;
    a.resize(500,200);
    QTableWidget table(&a);
    table.resize(500,200);

    if(exist_Signture>=11){
        QMessageBox::about(this,"warning","Digital Signature stores up to 10, next one will show on the #10 position.");
        exist_Signture=10;
    }

    int columncount=0;
    if(exist_Signture>=3){
        columncount=exist_Signture;
    }
    else
        columncount=3;
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

    QTableWidgetItem signture_1;
    QTableWidgetItem signture_2;
    QTableWidgetItem signture_3;
    QTableWidgetItem signture_4;
    QTableWidgetItem signture_5;
    QTableWidgetItem signture_6;
    QTableWidgetItem signture_7;
    QTableWidgetItem signture_8;
    QTableWidgetItem signture_9;
    QTableWidgetItem signture_10;

    QTableWidgetItem time1_1;
    QTableWidgetItem time1_2;
    QTableWidgetItem time1_3;
    QTableWidgetItem time1_4;
    QTableWidgetItem time1_5;
    QTableWidgetItem time1_6;
    QTableWidgetItem time1_7;
    QTableWidgetItem time1_8;
    QTableWidgetItem time1_9;
    QTableWidgetItem time1_10;

    signture_1.setFlags(signture_1.flags() & (~Qt::ItemIsEditable));
    signture_2.setFlags(signture_2.flags() & (~Qt::ItemIsEditable));
    signture_3.setFlags(signture_3.flags() & (~Qt::ItemIsEditable));
    signture_4.setFlags(signture_4.flags() & (~Qt::ItemIsEditable));
    signture_5.setFlags(signture_5.flags() & (~Qt::ItemIsEditable));
    signture_6.setFlags(signture_6.flags() & (~Qt::ItemIsEditable));
    signture_7.setFlags(signture_7.flags() & (~Qt::ItemIsEditable));
    signture_8.setFlags(signture_8.flags() & (~Qt::ItemIsEditable));
    signture_9.setFlags(signture_9.flags() & (~Qt::ItemIsEditable));
    signture_10.setFlags(signture_10.flags() & (~Qt::ItemIsEditable));

    time1_1.setFlags(time1_1.flags() & (~Qt::ItemIsEditable));
    time1_2.setFlags(time1_2.flags() & (~Qt::ItemIsEditable));
    time1_3.setFlags(time1_3.flags() & (~Qt::ItemIsEditable));
    time1_4.setFlags(time1_4.flags() & (~Qt::ItemIsEditable));
    time1_5.setFlags(time1_5.flags() & (~Qt::ItemIsEditable));
    time1_6.setFlags(time1_6.flags() & (~Qt::ItemIsEditable));
    time1_7.setFlags(time1_7.flags() & (~Qt::ItemIsEditable));
    time1_8.setFlags(time1_8.flags() & (~Qt::ItemIsEditable));
    time1_9.setFlags(time1_9.flags() & (~Qt::ItemIsEditable));
    time1_10.setFlags(time1_10.flags() & (~Qt::ItemIsEditable));

    time_t t;
    time(&t);
    struct tm*now = localtime(&t);
    std::string str=asctime(now);
    Signture[exist_Signture-1][0]=str;

    std::hash<std::string> str_hash;
    QString content = ui->textEdit->toPlainText();
    std::string author="Xi";
    std::string signture1 = std::to_string(str_hash(std::to_string(str_hash(author)) + q2s(content)));
    Signture[exist_Signture-1][1]=signture1;

    time1_1.setText(s2q(Signture[0][0]));
    time1_2.setText(s2q(Signture[1][0]));
    time1_3.setText(s2q(Signture[2][0]));
    time1_4.setText(s2q(Signture[3][0]));
    time1_5.setText(s2q(Signture[4][0]));
    time1_6.setText(s2q(Signture[5][0]));
    time1_7.setText(s2q(Signture[6][0]));
    time1_8.setText(s2q(Signture[7][0]));
    time1_9.setText(s2q(Signture[8][0]));
    time1_10.setText(s2q(Signture[9][0]));

    signture_1.setText(s2q(Signture[0][1]));
    signture_2.setText(s2q(Signture[1][1]));
    signture_3.setText(s2q(Signture[2][1]));
    signture_4.setText(s2q(Signture[3][1]));
    signture_5.setText(s2q(Signture[4][1]));
    signture_6.setText(s2q(Signture[5][1]));
    signture_7.setText(s2q(Signture[6][1]));
    signture_8.setText(s2q(Signture[7][1]));
    signture_9.setText(s2q(Signture[8][1]));
    signture_10.setText(s2q(Signture[9][1]));

    table.setItem(0,1,&signture_1);
    table.setItem(1,1,&signture_2);
    table.setItem(2,1,&signture_3);
    table.setItem(3,1,&signture_4);
    table.setItem(4,1,&signture_5);
    table.setItem(5,1,&signture_6);
    table.setItem(6,1,&signture_7);
    table.setItem(7,1,&signture_8);
    table.setItem(8,1,&signture_9);
    table.setItem(9,1,&signture_10);

    table.setItem(0,0,&time1_1);
    table.setItem(1,0,&time1_2);
    table.setItem(2,0,&time1_3);
    table.setItem(3,0,&time1_4);
    table.setItem(4,0,&time1_5);
    table.setItem(5,0,&time1_6);
    table.setItem(6,0,&time1_7);
    table.setItem(7,0,&time1_8);
    table.setItem(8,0,&time1_9);
    table.setItem(9,0,&time1_10);

    qDebug()<<exist_Signture;

    table.show();
    a.exec();
}

void MainWindow::on_actionExport_PDF_triggered()
{
    PDFName = QFileDialog::getSaveFileName(this,"Export PDF",QString(),"*.pdf");

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(PDFName);

    ui->textEdit->document()->print(&printer);
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog dialog(&printer);
    dialog.setWindowTitle("Print Document");
    if(dialog.exec()==QDialog::Accepted){
        printer.setOutputFormat(QPrinter::NativeFormat);
      //printer.setOutputFileName("print.pdf");
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

void MainWindow::on_actionImage_triggered()
{
    image a;
    a.exec();
}
