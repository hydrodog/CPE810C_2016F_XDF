#include "tod.h"
#include "ui_tod.h"
#include "drawfunlist.h"

ToD::ToD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ToD)
{
    ui->setupUi(this);
}
ToD::ToD(twoDGraphics *twoDGph)
{
    mTwoDGph=twoDGph;
}

ToD::~ToD()
{
    delete ui;
}
void ToD::paintEvent(QPaintEvent *)
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




    painter.translate(this->rect().bottomLeft());
    painter.scale(1.0, -1.0);


    painter.drawPath(drawFunList.getPath());
}
