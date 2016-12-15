#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QColorDialog>
#include <QAction>
#include <QFontDialog>
#include <QFrame>
#include <QTextBrowser>
#include "frame.h"
#include "border.h"
#include "page.h"

using namespace  std;
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

void MainWindow::addFrame(Page pg){
    std::list<Frame> myframeList=pg.frameList();
    for (std::list<Frame>::iterator it =myframeList.begin(); it != myframeList.end(); ++it){
        Frame f=(*it);
        QFrame* frame_3 = new QFrame(ui->centralWidget);
        QString str=QString("frame").append(QChar(f.frameNum()));
        frame_3->setObjectName(str);
        frame_3->setGeometry(QRect(f.startX(), f.startY(), f.height(), f.width()));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setStyleSheet("background-color:grey");
        frame_3->setMidLineWidth(10);
        frame_3->setLineWidth(10);
        if(f.text().contentList().empty()){
            return;
        }else{

            QDialog* myDia=new QDialog(ui->centralWidget);
            myDia->setGeometry(100,100,300,300);
            myDia->setStyleSheet("background-color:black;");
            QTextBrowser* textBrowser = new QTextBrowser(frame_3);
            textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            textBrowser->setFrameShape(QFrame::Box);
            textBrowser->setFrameShadow(QFrame::Sunken);
            textBrowser->setStyleSheet("background-color:grey");
            QTextOption* myOp= new QTextOption();
            myOp->setTextDirection(Qt::RightToLeft);
            //textBrowser->document()->setDefaultTextOption(*myOp);
            str.append("_textBrowser");
            textBrowser->setObjectName(str);
            textBrowser->setFrameStyle(QFrame::NoFrame);
            textBrowser->viewport()->setAutoFillBackground(false);
            QFrame* frame_4 = new QFrame(textBrowser);
            frame_4->setGeometry(QRect(0,0,100,100));
            frame_4->setStyleSheet("background-color:green;");
            int a;
            a=f.startX();

            textBrowser->setGeometry(QRect(f.border().leftEdge(), f.border().topEdge(), f.height()-f.border().downEdge()-f.border().topEdge(), f.width()-f.border().leftEdge()-f.border().rightEdge()));
            //textBrowser->setStyleSheet("background-color:white;");

            QString str;

            //Get the content list from text and append string to textbrowser
            //textBrowser->insertHtml("<img src='/Users/zhiyuanchen/Downloads/lee.png' width='30%'/>");

            std::list<Content> mycontent=f.text().contentList();
            for (std::list<Content>::iterator it =mycontent.begin(); it != mycontent.end(); ++it){
                wstring temp=(*it).str();
                str=QString::fromStdWString(temp);
                QFont t=(*it).font();
                QColor c=(*it).color();
                textBrowser->setCurrentFont(t);
                textBrowser->setTextColor(c);
                textBrowser->insertPlainText(str);
            }
            textBrowser->append("str");
            textBrowser->insertPlainText("b");
            textBrowser->insertPlainText("c");




#if 0
        //This loop is to find all characters of all lines in text and append them on screen
        std::list<TextLine> t=f.text().textLineList();
        for (std::list<TextLine>::iterator it =t.begin(); it != t.end(); ++it){
            std::vector<char> temp= (*it).lineContent();
            count++;
            for (std::vector<char>::iterator it2 = temp.begin() ; it2 != temp.end(); ++it2){

                str.append(*it2);
            }
            textBrowser->append(str);
            if(count==1){
                textBrowser->setAlignment(Qt::AlignRight);
            }
            else{
                textBrowser->setAlignment(Qt::AlignCenter);
            }
            str.clear();
        }
#endif
#if 0
        //Just test some english words
        QFont serifFont2("Times", 28, QFont::Bold);
        serifFont2.setItalic(true);
        textBrowser->setCurrentFont(serifFont2);
        textBrowser->setTextColor(QColor( "green" ));
        textBrowser->append("This is another test!!!!!\n");
        textBrowser->setAlignment(Qt::AlignLeft);
        QFont serifFont3("Times", 44, QFont::Bold);
        serifFont2.setItalic(true);
        textBrowser->setCurrentFont(serifFont3);
        textBrowser->setTextColor(QColor( "blue" ));
        textBrowser->insertPlainText("This is another string!\nmm");
 #endif

        }
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
    //QColor color1=color.currentColor();
}
