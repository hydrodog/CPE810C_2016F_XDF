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

}

void MainWindow::addFrame(Page pg){
    //First create a frame for the whole page
    QFrame* frame2 = new QFrame(ui->centralWidget);
    frame2->setObjectName("page");
    frame2->setGeometry(QRect(0, 0, pg.height(), pg.width()));
    frame2->setFrameShape(QFrame::Box);
    frame2->setFrameShadow(QFrame::Raised);
    frame2->setStyleSheet("background-color:white");
    frame2->setMidLineWidth(5);
    frame2->setLineWidth(5);
    //Find all the frame in the page, then put them inside of the Big frame of Page
    std::list<Frame> myframeList=pg.frameList();
    for (std::list<Frame>::iterator it =myframeList.begin(); it != myframeList.end(); ++it){
        Frame f=(*it);
        QFrame* frame_3 = new QFrame(frame2);
        QString str=QString("frame").append(QChar(f.frameNum()));
        frame_3->setObjectName(str);
        frame_3->setGeometry(QRect(f.startX(), f.startY(), f.height(), f.width()));
        //Get the x,y coordinate, height and weight from the frame
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setStyleSheet("background-color:grey");
        frame_3->setMidLineWidth(10);
        frame_3->setLineWidth(10);
        if(f.text().contentList().empty()){
            //If There is no content just return
            return;
        }else{

            //Create a QtextBrowser to put all the text in it
            //And make the textBrowser inside the given frame
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
            //Set the textBrowser to be noFrameStyle

            textBrowser->viewport()->setAutoFillBackground(false);

            //Based on the Border of the frame, adjust the x,y coordinate, weight and height of the textBrowser
            textBrowser->setGeometry(QRect(f.border().leftEdge(), f.border().topEdge(), f.height()-f.border().downEdge()-f.border().topEdge(),
                                           f.width()-f.border().leftEdge()-f.border().rightEdge()));

            //textBrowser->setStyleSheet("background-color:white;");


            //textBrowser->insertHtml("<img src='/Users/zhiyuanchen/Downloads/lee.png' width='30%'/>");

            /*
             * Find all the content in the text
             * Get the font and color from the content, then set the information for textbrowser
             */
            QString str;
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
