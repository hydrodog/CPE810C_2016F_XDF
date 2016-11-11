#include "dialog.h"
#include "ui_dialog.h"
#include "includes.hh"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("XDF print");

    //back groud set
    //this->setStyleSheet(" background-image: url(C:/test.png);");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_acceptButton_clicked()
{
    PPrint pt;
    //this->setWindowTitle(ui->BeginTextEdit->toPlainText());
    pt.setStartPageNum(ui->BeginTextEdit->toPlainText().toInt());
    pt.setEndPageNum(ui->EndTextEdit->toPlainText().toInt());


    pt.PProcess();
}

void Dialog::on_cancelButton_clicked()
{
    this->close();
}

