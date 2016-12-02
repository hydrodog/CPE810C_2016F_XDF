#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);

    connect(ui->confirmButton, SIGNAL(clicked()), SLOT(setWidthHeightClicked()));
    connect(ui->closeButton, SIGNAL(clicked()), SLOT(close()));
}

InputDialog::~InputDialog()
{
    delete ui;
}

void InputDialog::setWidthHeightClicked()
{
    emit setWidthHeight(ui->spinBox->value(), ui->spinBox_2->value());
    close();
}
