#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawfunlist.h"

/*
  @author: Bingyang WEN, Bo FAN   12/2/2016
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::MainWindow(twoDGraphics *twoDGph)
{
    mTwoDGph = twoDGph;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    DrawFunList drawFunList;


    for(auto ite = mTwoDGph->getAllShape().begin(); ite != mTwoDGph->getAllShape().end(); ++ite){

        std::string curOpt = ite->getOpter();

        std::vector<double> allOpnds = ite->getOpnds();

        drawFunList.draw(curOpt, allOpnds,1);

        for(auto iteOpnds = allOpnds.begin(); iteOpnds != allOpnds.end(); ++iteOpnds){
        }
    }
    QPainter painter(this);

    painter.setPen(drawFunList.getPen());

    painter.setBrush(drawFunList.getBrush());

    painter.drawPath(drawFunList.getPath());

}
