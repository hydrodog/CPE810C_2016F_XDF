#include "DrawFunList.h"

/*
 @author: Seito Ryu  20/11/16
 @modifer: Seito Ryu 30/11/16 "add some sample code"
 */

//constructor
DrawFunList::DrawFunList() {
  mapDrw = {
    {"m",  &DrawFunList::setPoint},
    {"l",  &DrawFunList::drawLine},
    {"re",  &DrawFunList::drawRect},
    {"c", &DrawFunList::drawCubic},
    {"h",  &DrawFunList::closePath},
    {"sc",&DrawFunList::setColor},
    {"s",&DrawFunList::setPen},
    {"f",&DrawFunList::setBrush}

  };
}
//deconstructor
DrawFunList::~DrawFunList() {}

//TODO: implement each draw method
void DrawFunList::setPoint(const std::vector<double>& operands, const int& currentIndex){

  path->moveTo(operands[0],operands[1]);
}
void DrawFunList::drawLine(const std::vector<double>& operands, const int& currentIndex){

  path->lineTo(operands[0],operands[1]);
}
void DrawFunList::drawRect(const std::vector<double>& operands, const int& currentIndex){

    path->addRect(operands[1],operands[2],operands[3],operands[4]);
}
void DrawFunList::drawCubic(const std::vector<double>& operands, const int& currentIndex){

    path->cubicTo(operands[0],operands[1],operands[2],operands[3],operands[4],operands[5]);
}
void DrawFunList::closePath(const std::vector<double>& operands, const int& currentIndex){
    path->closeSubpath();
}
void DrawFunList::setColor(const std::vector<double>& operands, const int& currentIndex){

    *color=QColor(operands[0]*255,operands[1]*255,operands[2]*255);
}
void DrawFunList::setPen(const std::vector<double>& operands, const int& currentIndex){

    *pen=QPen(*color,3);
}
void DrawFunList::setBrush(const std::vector<double>& operands, const int& currentIndex){

    *brush=QBrush(*color);
}
//draw function table
void DrawFunList::draw(const std::string& currentOperator, const std::vector<double>& operands, const int& currentIndex){
  if(mapDrw[currentOperator]){
    (this->*mapDrw[currentOperator])(operands, currentIndex);
  }
}
QPainterPath DrawFunList::getPath()
{
    return *path;
}
QColor DrawFunList::getColor()
{
    return *color;
}

QPen DrawFunList::getPen()
{
    return *pen;
}

QBrush DrawFunList::getBrush()
{
    return *brush;
}