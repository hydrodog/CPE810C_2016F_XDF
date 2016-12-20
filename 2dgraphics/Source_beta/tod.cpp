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
    pTwoDGph=twoDGph;
}

ToD::~ToD()
{
    delete ui;
}
void ToD::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    DrawFunList drawFunList(&painter);
    painter.translate(this->rect().bottomLeft());
    painter.scale(.8, -.8);

    for(auto ite = pTwoDGph->getAllShape().begin(); ite != pTwoDGph->getAllShape().end(); ++ite){

        std::string curOpt = ite->getOpter();
        std::cout << "Operator is " << curOpt << " <";
        std::vector<double> allOpnds = ite->getOpnds();

        drawFunList.draw(curOpt, allOpnds,1);
        for(auto iteOpnds = allOpnds.begin(); iteOpnds != allOpnds.end(); ++iteOpnds)
            std::cout << " " << *iteOpnds;
        std::cout << " > " << '\n';
        //std::getchar();
    }
    for (auto it=pTwoDGph->pTextBoxes()->begin(); it != pTwoDGph->pTextBoxes()->end(); ++it)
    {
        //painter.drawText(it->topLeftPosition(), it->text());
    }

/*

    painter.setPen(drawFunList.getPen());
    painter.setBrush(drawFunList.getBrush());
    painter.drawPath(drawFunList.getPath());







    painter.drawPath(drawFunList.getPath());
    */
}
