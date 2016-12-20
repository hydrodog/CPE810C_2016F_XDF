#include "drawfunlist.h"
//constructor

/*
 @author: Seito Ryu  11/20/16
 @modifer: Bingyang Wen 12/2/16 "Build the connection between DrawFunList and Window, which shows graphs"
 @modifer: Bo fan       12/2/16 "Set specific draw functions"
 */

/**
 TODO: implement basic and complicated QT methods
*/


DrawFunList::DrawFunList(QPainter* pQPainter): pQPainter(pQPainter)
{
  mapDrw = {
      {"m",  &DrawFunList::moveTo},
      {"l",  &DrawFunList::drawLine},
      {"re",  &DrawFunList::drawRect},
      {"c", &DrawFunList::drawCubic},
      {"h",  &DrawFunList::closePath},
      {"SC", &DrawFunList::setStrokingColor},
      {"sc",&DrawFunList::setNonStrokingColor},
      {"S",&DrawFunList::stroke},
      {"s",&DrawFunList::stroke},
      {"f",&DrawFunList::fill},
      {"F",&DrawFunList::fill},
      {"cm",&DrawFunList::setCTM}

  };
}
//destructor
DrawFunList::~DrawFunList() {}

//TODO: implement each draw method
void DrawFunList::moveTo(const std::vector<double>& operands, const int& currentIndex)
{
    path.moveTo(operands[0],operands[1]);
}
void DrawFunList::drawLine(const std::vector<double>& operands, const int& currentIndex){

  path.lineTo(operands[0],operands[1]);
}
void DrawFunList::drawRect(const std::vector<double>& operands, const int& currentIndex)
{
    double x = operands[0];
    double y = operands[1];
    double width = operands[2];
    double height = operands[3];
    path.addRect(x, y, width, height);
}
void DrawFunList::drawCubic(const std::vector<double>& operands, const int& currentIndex){

    path.cubicTo(operands[0],operands[1],operands[2],operands[3],operands[4],operands[5]);
}
void DrawFunList::closePath(const std::vector<double>& operands, const int& currentIndex){
    path.closeSubpath();
}
void DrawFunList::setStrokingColor(const std::vector<double>& operands, const int& currentIndex){

    color=QColor(operands[0]*255,operands[1]*255,operands[2]*255);
    pen = QPen(color,10);
}
void DrawFunList::setNonStrokingColor(const std::vector<double>& operands, const int& currentIndex){

    color=QColor(operands[0]*255,operands[1]*255,operands[2]*255);
    brush = QBrush(color);
}
void DrawFunList::stroke(const std::vector<double>& operands, const int& currentIndex)
{
    pQPainter->strokePath(path, pen);
}
void DrawFunList::fill(const std::vector<double>& operands, const int& currentIndex){
    path.closeSubpath();
    pQPainter->fillPath(path,QBrush());
    //std::cout<<"filling!!!!!!!!!!";
}
void DrawFunList::setCTM(const std::vector<double>& operands, const int& currentIndex){

    *transformer=QTransform(operands[0],operands[1],0,operands[2],operands[3],0,operands[4],operands[5],1);
}
//draw function table
void DrawFunList::draw(const std::string& currentOperator, const std::vector<double>& operands, const int& currentIndex){
  if(mapDrw[currentOperator]){
    (this->*mapDrw[currentOperator])(operands, currentIndex);
  }
}
QPainterPath DrawFunList::getPath()
{
    return path;
}
QColor DrawFunList::getColor()
{
    return color;
}

QPen DrawFunList::getPen()
{
    return pen;
}

QBrush DrawFunList::getBrush()
{
    return brush;
}

QTransform DrawFunList::getCTM()
{
    return *transformer;
}
