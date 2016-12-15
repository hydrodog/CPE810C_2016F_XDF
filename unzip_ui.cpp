#include "epub_unzip_ui.h"
#include <QFileDialog>
#include "ZHead.h"

epub_unzip_ui::epub_unzip_ui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.btn1,SIGNAL(clicked()),this, SLOT(onBtn1()));
    connect(ui.btn2,SIGNAL(clicked()),this, SLOT(onBtn2()));
    connect(ui.btn3,SIGNAL(clicked()),this, SLOT(onBtn3()));
}

epub_unzip_ui::~epub_unzip_ui()
{

}

void epub_unzip_ui::onBtn1()
{
    QString file_name = QFileDialog::getOpenFileName(this, QString(), QString(), "*.*");
    if (file_name.isEmpty())
	    return;

    ui.lineEdit1->setText(file_name);
}

void epub_unzip_ui::onBtn2()
{
    QString file_name = QFileDialog::getExistingDirectory(this, QString());
    if (file_name.isEmpty())
	    return;

    ui.lineEdit2->setText(file_name);
}

void epub_unzip_ui::onBtn3()
{
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor)); 

    QString zip = ui.lineEdit1->text();
    QString dir = ui.lineEdit2->text();
    UnZipToDirectory(zip.toStdString().c_str(),dir.toStdString().c_str());
    QApplication::restoreOverrideCursor();
}
