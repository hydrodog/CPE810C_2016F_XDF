#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QTableWidget>
#include <iostream>
#include <time.h>
#include <QDebug>

#include<algorithm>
#include<vector>
#include<string>


//QString <=>string
QString MainWindow::s2q(const std::string &s){
    return QString(QString::fromLocal8Bit(s.c_str()));
}
std::string MainWindow::q2s(const QString &s){
    return std::string((const char *)s.toLocal8Bit());
}




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()//打开文件
{
  QString fileName = QFileDialog::getOpenFileName(this,"open file","D:","text(*.txt *.pdf)");
  QFile file(fileName);
  if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
      QMessageBox::warning(this,"open file",tr("fail to open files").arg(file.errorString()));
      fileName="";
      return;
  }
   QTextStream in(&file);
   QApplication::setOverrideCursor(Qt::WaitCursor);
   ui->textEdit->setPlainText(in.readAll());
   ui->textEdit->setFontPointSize(15);
   QApplication::restoreOverrideCursor();
   file.close();
   return;
}

void MainWindow::on_actionMake_a_Sign_triggered()
{
    exist_Signature++;
       QDialog a;
       a.resize(500,200);
       QTableWidget table(&a);
       table.resize(500,200);

       if(exist_Signature>=11){
           QMessageBox::about(this,"warning","Digital Signature stores up to 10, next one will show on the #10 position.");
           exist_Signature=10;
       }

       int columncount=0;
       if(exist_Signature>=3){
           columncount=exist_Signature;
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
       horizontitle << "time" << "Signature";
       table.setHorizontalHeaderLabels(horizontitle);
       table.horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

       QTableWidgetItem Signature_1;
       QTableWidgetItem Signature_2;
       QTableWidgetItem Signature_3;
       QTableWidgetItem Signature_4;
       QTableWidgetItem Signature_5;
       QTableWidgetItem Signature_6;
       QTableWidgetItem Signature_7;
       QTableWidgetItem Signature_8;
       QTableWidgetItem Signature_9;
       QTableWidgetItem Signature_10;

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

       Signature_1.setFlags(Signature_1.flags() & (~Qt::ItemIsEditable));
       Signature_2.setFlags(Signature_2.flags() & (~Qt::ItemIsEditable));
       Signature_3.setFlags(Signature_3.flags() & (~Qt::ItemIsEditable));
       Signature_4.setFlags(Signature_4.flags() & (~Qt::ItemIsEditable));
       Signature_5.setFlags(Signature_5.flags() & (~Qt::ItemIsEditable));
       Signature_6.setFlags(Signature_6.flags() & (~Qt::ItemIsEditable));
       Signature_7.setFlags(Signature_7.flags() & (~Qt::ItemIsEditable));
       Signature_8.setFlags(Signature_8.flags() & (~Qt::ItemIsEditable));
       Signature_9.setFlags(Signature_9.flags() & (~Qt::ItemIsEditable));
       Signature_10.setFlags(Signature_10.flags() & (~Qt::ItemIsEditable));

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
       Signature[exist_Signature-1][0]=str;

       std::hash<std::string> str_hash;
       QString content = ui->textEdit->toPlainText();
       std::string author="Xi";
       std::string Signature1 = std::to_string(str_hash(std::to_string(str_hash(author)) + q2s(content)));
       Signature[exist_Signature-1][1]=Signature1;

       time1_1.setText(s2q(Signature[0][0]));
       time1_2.setText(s2q(Signature[1][0]));
       time1_3.setText(s2q(Signature[2][0]));
       time1_4.setText(s2q(Signature[3][0]));
       time1_5.setText(s2q(Signature[4][0]));
       time1_6.setText(s2q(Signature[5][0]));
       time1_7.setText(s2q(Signature[6][0]));
       time1_8.setText(s2q(Signature[7][0]));
       time1_9.setText(s2q(Signature[8][0]));
       time1_10.setText(s2q(Signature[9][0]));

       Signature_1.setText(s2q(Signature[0][1]));
       Signature_2.setText(s2q(Signature[1][1]));
       Signature_3.setText(s2q(Signature[2][1]));
       Signature_4.setText(s2q(Signature[3][1]));
       Signature_5.setText(s2q(Signature[4][1]));
       Signature_6.setText(s2q(Signature[5][1]));
       Signature_7.setText(s2q(Signature[6][1]));
       Signature_8.setText(s2q(Signature[7][1]));
       Signature_9.setText(s2q(Signature[8][1]));
       Signature_10.setText(s2q(Signature[9][1]));

       table.setItem(0,1,&Signature_1);
       table.setItem(1,1,&Signature_2);
       table.setItem(2,1,&Signature_3);
       table.setItem(3,1,&Signature_4);
       table.setItem(4,1,&Signature_5);
       table.setItem(5,1,&Signature_6);
       table.setItem(6,1,&Signature_7);
       table.setItem(7,1,&Signature_8);
       table.setItem(8,1,&Signature_9);
       table.setItem(9,1,&Signature_10);

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

       qDebug()<<exist_Signature;


       table.show();
       a.exec();
}
