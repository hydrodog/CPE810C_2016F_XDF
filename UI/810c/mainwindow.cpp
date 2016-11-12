#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QColorDialog>
#include <QAction>
#include <QFontDialog>
#include <QFrame>
#include <QTextBrowser>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    //ui->textEdit->
}
void MainWindow::addFrame(){
    QFrame* frame_3 = new QFrame(ui->centralWidget);
    frame_3->setObjectName(QStringLiteral("frame_3"));
    frame_3->setGeometry(QRect(40, 660, 511, 291));
    frame_3->setFrameShape(QFrame::StyledPanel);
    frame_3->setFrameShadow(QFrame::Raised);
    QTextBrowser* textBrowser = new QTextBrowser(frame_3);
    textBrowser->setObjectName(QStringLiteral("textBrowser_3"));
    textBrowser->setGeometry(QRect(0, 0, 511, 291));
    QString str="this is a text";
    QString temp1="<font color=\"#00FF00\">";
    QString redPart = temp1.arg(str);
    textBrowser->setText(str);
}



void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
}

void MainWindow::on_actionColor_triggered()
{
    QColorDialog  color(this);
    color.setOption(QColorDialog::ShowAlphaChannel);
    color.exec();
    QColor color1=color.currentColor();
}
