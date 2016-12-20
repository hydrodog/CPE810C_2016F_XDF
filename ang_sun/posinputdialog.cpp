#include "posinputdialog.h"
#include "ui_posinputdialog.h"

PosInputDialog::PosInputDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::PosInputDialog)
{
    ui->setupUi(this);

    connect(ui->confirmButton, SIGNAL(clicked()), SLOT(setPostionClicked()));
    connect(ui->closeButton, SIGNAL(clicked()), SLOT(close()));
}

PosInputDialog::~PosInputDialog()
{
    delete ui;
}

void PosInputDialog::setPostionClicked()
{
    emit setPostion(ui->spinBox->value(), ui->spinBox_2->value());
    close();
}
