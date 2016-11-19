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
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        str.append("_textBrowser");
        textBrowser->setObjectName(str);
        textBrowser->setGeometry(QRect(0, 0, 600, 600));
        textBrowser->setStyleSheet("background-color:white;");
        QFont serifFont("Times", 50, QFont::Bold);
        serifFont.setStyle(QFont::StyleOblique);
        textBrowser->setCurrentFont(serifFont);
        textBrowser->setTextColor(QColor( "red" ));
        //textBrowser->setAlignment(Qt::AlignRight);
        QString str;
        int count=0;

        //This loop is to find all characters of all lines in text and append them on screen
        std::list<TextLine> t=f.getText().getTextLineList();
        for (std::list<TextLine>::iterator it =t.begin(); it != t.end(); ++it){
            std::vector<char> temp= (*it).getLineContent();
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

        QFont serifFont2("Times", 28, QFont::Bold);
        serifFont2.setItalic(true);
        textBrowser->setCurrentFont(serifFont2);
        textBrowser->setTextColor(QColor( "green" ));

        Content c=f.getText().getContentList();
        char *b=c.getword();
        std::cout<<b<<endl;
        textBrowser->append(b);



        textBrowser->append("This is another test!!!!!\n");
        textBrowser->setAlignment(Qt::AlignLeft);
        QFont serifFont3("Times", 44, QFont::Bold);
        serifFont2.setItalic(true);
        textBrowser->setCurrentFont(serifFont2);
        textBrowser->setTextColor(QColor( "blue" ));
        textBrowser->insertPlainText("This is another string!\nmm");
        //textBrowser->insertPlainText("This is another string!\n,This is another string!\n,This is another string!\n,This is another string!\n,This is another string!\n,This is another string!\n,This is another string!\n,This is another string!\n,This is another string!\n,This is another string!\n,This is another string!\n");
        textBrowser->setAlignment(Qt::AlignRight);
        QString zw="这是中文测试!!";
        textBrowser->append(zw.append("，另外的中文字"));
        textBrowser->setAlignment(Qt::AlignCenter);
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
