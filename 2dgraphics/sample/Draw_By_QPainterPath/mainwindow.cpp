#include "mainwindow.h"
#include "ui_mainwindow.h"

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
void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainterPath path;
    //vector<QPainterPath> mypath;
    /*path.moveTo(200,200);
    path.lineTo(400,400);
    path.lineTo(600,200);
    path.closeSubpath();

    QPainter painter(this);
    painter.setPen(QPen(QColor(0.5*255,0,0),3,Qt::SolidLine));
    painter.drawPath(path);
    */
    //mypath.push_back(path);
    path.moveTo(0,0);
    path.lineTo(100,0);
    path.moveTo(400,300);
    path.cubicTo(400,355.2,355.2,400,300,400);
    path.cubicTo(244.8,400,200,355.2,200,300);
    path.cubicTo(200,244.8,244.8,200,300,200);
    path.cubicTo(355.2,200,400,244.8,400,300);
    QPainter painter(this);
    painter.setPen(QPen(QColor(0.5*255,0,0),3,Qt::SolidLine));
    painter.setBrush(QColor(0.5*255,0,0));
    painter.drawPath(path);

}
