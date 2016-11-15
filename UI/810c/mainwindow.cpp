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
    frame_3->setGeometry(QRect(40, 20, 600, 600));
    frame_3->setFrameShape(QFrame::StyledPanel);
    frame_3->setFrameShadow(QFrame::Raised);
    if(f.getText().getTextLineList().empty()){
        return;
    }else{

        QTextBrowser* textBrowser = new QTextBrowser(frame_3);
        textBrowser->setObjectName(QStringLiteral("frame_3_textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 600, 600));
        textBrowser->setStyleSheet("background-color:white;");
        QFont serifFont("Times", 20, QFont::Bold);
        serifFont.setStyle(QFont::StyleOblique);
        textBrowser->setCurrentFont(serifFont);
        textBrowser->setTextColor(QColor( "red" ));
        QString str="this is a text,this is a text,this is a text,this is a text,this is a text,this is a text,this is a text";
        textBrowser->append(str);
        textBrowser->append(str);
        QFont serifFont2("Times", 44, QFont::Bold);
        serifFont2.setItalic(true);
        textBrowser->setCurrentFont(serifFont2);
        textBrowser->setTextColor(QColor( "blue" ));
        textBrowser->insertPlainText("This is another string!");


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
