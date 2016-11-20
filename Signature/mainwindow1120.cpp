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
    QTableWidgetItem Signature[10];
    QTableWidgetItem time1[10];
    qDebug()<<exist_Signature;
    QDialog a;
    a.resize(500,200);
    QTableWidget table(&a);
    table.resize(500,200);

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
    table.horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);//居中

    int loopcount;
    if(exist_Signature>1 && exist_Signature<=10){
        loopcount=exist_Signature-2;
    }
    else if(exist_Signature>10)
        loopcount=10;
    else if(exist_Signature=1)
        loopcount=-1;

    for(int i=0;i<=loopcount;i++){
        QTableWidgetItem wrong1= Signature[i];
        wrong1.setText(s2q(Signature[i][1]));
        qDebug()<<s2q(Signature[i][1]);//.setFlags(Signature[i].flags() & (~Qt::ItemIsEditable));

        QTableWidgetItem wrong2=time1[i];
        wrong2.setText(s2q(Signature[i][0]));
        qDebug()<<s2q(Signature[i][0]);//.setFlags(time[i].flags() & (~Qt::ItemIsEditable));
        table.setItem(i,0,&time1[i]);
        table.setItem(i,1,&Signature[i]);
    }

    QTableWidgetItem timenew;
    QTableWidgetItem Signaturenew;
    time_t t;
    time(&t);
    struct tm*now = localtime(&t);
    std::string str=asctime(now);
    Signature[exist_Signature-1][0]=str;
    timenew.setText(s2q(str));


    std::hash<std::string> str_hash;
    QString content = ui->textEdit->toPlainText();
    std::string author="Xi";
    std::string Signature1 = std::to_string(str_hash(std::to_string(str_hash(author)) + q2s(content)));
    Signature[exist_Signature-1][1]=Signature1;
    Signaturenew.setText(s2q(Signature1));


    table.setItem(exist_Signature-1,0,&timenew);
    table.setItem(exist_Signature-1,1,&Signaturenew);
    table.show();
    a.exec();



}
