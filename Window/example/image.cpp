#include "image.h"
#include "ui_image.h"

#include <QPainter>
#include <QFileDialog>
#include <QDebug>

image::image(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::image)
{
    ui->setupUi(this);
    ui->spinBox_height->setRange(0,500);
    ui->spinBox_width->setRange(0,500);
    ui->pushButton_open->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_save->setFocusPolicy(Qt::NoFocus);
    ui->label_size->setAlignment(Qt::AlignCenter);
    label_show();
}

QString image::s2q(const std::string &s)
{
    return QString(QString::fromLocal8Bit(s.c_str()));
}

std::string image::q2s(const QString &s)
{
    return std::string((const char *)s.toLocal8Bit());
}

image::~image()
{
    delete ui;
}

void image::on_pushButton_open_clicked()
{
    imagename = QFileDialog::getOpenFileName(this,"open file","D:","picture(*.png *.jpg)");
    open_flag=1;
    width_flag=0;
    height_flag=0;
    label_show();
    update();
    return;
}

void image::paintEvent(QPaintEvent *e)
{
    QPixmap a;
    a.load(imagename);
    qDebug()<<a.width();
    QPainter p(this);

    if(rotate_flag==1){
        QMatrix left;
        left.rotate(rotate);
        a=a.transformed(left);
    }

    if(width_flag!=0 && height_flag==0){
        a=a.scaled(width*time,300*time);
        p.drawPixmap(0,0,width*time,300*time,a);
    }
    else if(width_flag==0 && height_flag!=0){
        a=a.scaled(400*time,height*time);
        p.drawPixmap(0,0,400*time,height*time,a);
    }
    else if(width_flag!=0 && height_flag!=0){
        a=a.scaled(width*time,height*time);
        p.drawPixmap(0,0,width*time,height*time,a);
    }
    else if(width_flag==0 && height_flag==0){
        p.drawPixmap(0,0,400*time,300*time,a);
    }

    if(saveas_flag==1){
        if(a.save(imagesavename)){
            saveas_flag=0;
        }
    }
    p.end();
    e->accept();
}

void image::on_spinBox_width_editingFinished()
{
    width=ui->spinBox_width->value();
    width_flag=1;
    update();
    return;
}

void image::on_spinBox_height_editingFinished()
{
    height=ui->spinBox_height->value();
    height_flag=1;
    update();
    return;
}

void image::on_pushButton_save_clicked()
{
    imagesavename = QFileDialog::getSaveFileName(this,tr("Save image"),"D:",tr("Text files(*.png *.jpg)"));
    saveas_flag=1;
    update();
    return;
}

void image::on_spinBox_rotate_editingFinished()
{
    rotate=ui->spinBox_rotate->value();
    rotate_flag=1;
    update();
    return;
}

void image::on_spinBox_scale_editingFinished()
{
    time=ui->spinBox_scale->value();
    update();
    return;
}

void image::label_show()
{
    if(open_flag==0){
        ui->label_size->setText("no image");
    }
    if(open_flag==1){
        QPixmap a;
        a.load(imagename);
        int width_o=a.width();
        int height_o=a.height();
        QString str=s2q(std::to_string(width_o)+"*"+std::to_string(height_o));
        ui->label_size->setText(str);
    }
}
