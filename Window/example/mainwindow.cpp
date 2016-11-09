#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include <QFileDialog>
#include <QDebug>

int MainWindow::fileState=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("XDF project");
    this->resize(1300,800);
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
    QApplication::restoreOverrideCursor();
    file.close();
    return;
}

void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save Text"),"",tr("Text files(*.txt)"));
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
