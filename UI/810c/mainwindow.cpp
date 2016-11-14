#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QColorDialog>
#include <QAction>
#include <QFontDialog>
#include <QFrame>
#include <QTextBrowser>
#include "frame.h"
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
void MainWindow::addFrame(Frame f){
    QFrame* frame_3 = new QFrame(ui->centralWidget);
    QString str=QString("frame").append(QChar(f.getframeNum()));
    frame_3->setObjectName(str);
    frame_3->setGeometry(QRect(40, 660, 511, 291));
    frame_3->setFrameShape(QFrame::StyledPanel);
    frame_3->setFrameShadow(QFrame::Raised);
    if(f.getText().getTextLineList().empty()){
        return;
    }else{
        QTextBrowser* textBrowser = new QTextBrowser(frame_3);
        textBrowser->setObjectName(QStringLiteral("frame_3_textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 511, 291));
        QString str="this is a text";
        textBrowser->setText(str);
    }

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
