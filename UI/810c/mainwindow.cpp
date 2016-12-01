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
void MainWindow::addFrame(Frame f){

    QFrame* frame_3 = new QFrame(ui->centralWidget);
    QString str=QString("frame").append(QChar(f.frameNum()));
    frame_3->setObjectName(str);
    frame_3->setGeometry(QRect(f.startX(), f.startY(), f.height(), f.width()));
    frame_3->setFrameShape(QFrame::StyledPanel);
    frame_3->setFrameShadow(QFrame::Raised);
    frame_3->setStyleSheet("background-color:yellow;");
    frame_3->setMidLineWidth(1);
    frame_3->setLineWidth(2);
    if(f.text().contentList().empty()){
        return;
    }else{
        QTextBrowser* textBrowser = new QTextBrowser(frame_3);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        str.append("_textBrowser");
        textBrowser->setObjectName(str);
        textBrowser->setFrameStyle(QFrame::NoFrame);
        int a;
        a=f.startX();

        textBrowser->setGeometry(QRect(f.border().leftEdge(), f.border().topEdge(), f.height()-f.border().downEdge()-f.border().topEdge(), f.width()-f.border().leftEdge()-f.border().rightEdge()));
        textBrowser->setStyleSheet("background-color:white;");

        QString str;

        //Get the content list from text and append string to textbrowser
        std::list<Content> mycontent=f.text().contentList();
        for (std::list<Content>::iterator it =mycontent.begin(); it != mycontent.end(); ++it){
            wstring temp=(*it).str();
            str=QString::fromStdWString(temp);
            QFont t=(*it).font();
            QColor c=(*it).color();
            textBrowser->setCurrentFont(t);
            textBrowser->setTextColor(c);
            textBrowser->append(str);
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
        textBrowser->setAlignment(Qt::AlignRight);
        //textBrowser->insertHtml("<img src='/Users/zhiyuanchen/Downloads/abc.jpg'>");
        //textBrowser->insertHtml("<html><head><title>HTML DEMO</title><style>p{color: yellow}</style></head><body><h1> My first heading</h1><p> My <b>first</b> paragraph</p><h1>My seconde heading</h1><p> My <sub>aa</sub>secon<sup>d</sup> paragraph</p><img src='/Users/zhiyuanchen/Downloads/lee.png'/></body></html>");
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
