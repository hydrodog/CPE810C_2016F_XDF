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
    pt.setStartPageNum(ui->startPageLineEdit->text().toInt());
    pt.setEndPageNum(ui->EndTextLineEdit->text().toInt());
    pt.setIsReverse(ui->reverseCheckBox->isChecked());//check if you wanna print from end to begin
    pt.setIsPDF(ui->pdfCheckBox->isChecked());//check if the user wanna print out as PDF directly @Zejian
   // pt.setIsOdd(ui->);

    pt.PProcess();
}

void Dialog::on_cancelButton_clicked()
{
    this->close();
}

