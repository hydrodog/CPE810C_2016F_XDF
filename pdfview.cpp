#include "pdfview.h"
#include "ui_pdfview.h"

#include <QFileDialog>
#include <QPainter>
#include <QFile>
#include <QDebug>
#include <stdlib.h>

QString PDFview::s2q(const std::string &s)
{
    return QString(QString::fromLocal8Bit(s.c_str()));
}

std::string PDFview::q2s(const QString &s)
{
    return std::string((const char *)s.toLocal8Bit());
}

char PDFview::check_first_letter_t(std::string a)
{
    qDebug()<<1;
    for(int i=0;!a.length();i++){
        if(a[i]=='t'){
            return a[i];
        }
    }
}

QString PDFview::analyze(int a[4],std::string str)
{
    int count=0;
    int num=0;
    int receving=0;
    //int flag=0;
    std::string haha;
    for (int i=0;str[i]!='\n';i++){
        //qDebug()<<i;
        if(count<4&&(str[i]=='t'||str[i]=='p')) {
            continue;
        }
        if(str[i]==' ' && receving==0) continue;

        if(count<4 && (str[i]>='0' && str[i]<='9')){
            haha=haha+str[i];
            receving=1;
        }
        if(receving==1 && str[i]==' ' &&count <4){
            haha=haha+'\0';
            a[num]=atoi(haha.c_str());
            haha="";
            num++;
            receving=0;
            count++;
        }
        if(count==4 && str[i]!=' '){
            haha=haha+str[i];
            receving=1;
        }
        //if(count==4 && (str[i]==' ' || str[i]=='\n') && receving==1){
        //    haha=haha+'\0';
        //    return s2q(haha);
        //}
    }
    haha=haha+'\0';
    return s2q(haha);
}


PDFview::PDFview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PDFview)
{
    ui->setupUi(this);
    this->setModal(false);
}

PDFview::~PDFview()
{
    delete ui;
}

void PDFview::on_pushButton_clicked()
{
    PDFviewname=QFileDialog::getOpenFileName(this,"pdf import","D:","text( *.txt)");
    open_flag=1;
}
/*//////////////////////////////////////////*/
void PDFview::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    if(open_flag==1){
        QFile a(PDFviewname);
        a.open(QIODevice::ReadOnly|QIODevice::Text);
        QString str = a.readAll();
        qDebug()<<str;
        QRect rect(50,50,100,100);
        p.drawRect(rect);
        p.drawText(rect,str);
    }

    if(open_setting_flag==1){
        open_flag=0;
        QFile a(PDFsettingname);
        a.open(QIODevice::ReadOnly|QIODevice::Text);
        for(int i=0;!a.atEnd();i++){
            QString str=a.readLine();
            qDebug()<<str;
            if(q2s(str)[0]=='t'){
            //if(1){
                int rect[4]={0};
                PDFviewname=analyze(rect,q2s(str));

                QRect rect1(rect[0],rect[1],rect[2],rect[3]);
                //p.drawRect(rect1);
                QFile file(PDFviewname);
                file.open(QIODevice::ReadOnly|QIODevice::Text);
                QString content=file.readAll();
                p.drawText(rect1,content);
            }
            else if(q2s(str)[0]=='p'){
                //qDebug()<<3;
                int rect[4]={0};
                PDFviewname=analyze(rect,q2s(str));
                qDebug()<<PDFviewname;
                qDebug()<<rect[0]<<rect[1]<<rect[2]<<rect[3];
                QRect rect1(rect[0],rect[1],rect[2],rect[3]);
                //p.drawRect(rect1);
                QPixmap file;
                file.load(PDFviewname);
                p.drawPixmap(rect1,file);
            }
        }
    }
}

void PDFview::on_pushButton_open_setting_clicked()
{
    PDFsettingname=QFileDialog::getOpenFileName(this,"pdf import","D:","text( *.txt)");
    open_setting_flag=1;
}
