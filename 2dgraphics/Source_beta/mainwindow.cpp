#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawfunlist.h"

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

        std::cout << "Operator is " << curOpt << "\t";

        std::vector<double> allOpnds = ite->getOpnds();

        drawFunList.draw(curOpt, allOpnds,1);

        for(auto iteOpnds = allOpnds.begin(); iteOpnds != allOpnds.end(); ++iteOpnds){
          std::cout << "\t\t" << *iteOpnds;
        }
        std::cout << "\n";
    }


    QPainter painter(this);
    painter.setPen(drawFunList.getPen());
    painter.setBrush(drawFunList.getBrush());
    painter.drawPath(drawFunList.getPath());

}
