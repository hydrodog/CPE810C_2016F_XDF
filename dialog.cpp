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
    if(ui->EvenRadioButton->isChecked())//check if user want odd/even pages printed only
        pt.setIsOdd(2);
    else if(ui->OddRadioButton->isChecked())
        pt.setIsOdd(1);
    else
        pt.setIsOdd(0);
    pt.print(Text & mytext);
}

void Dialog::on_cancelButton_clicked()
{
    this->close();
}

