#include "DrawFunList.h"

/*
 @author: 2d_Graphic Group  12/2/2016
 @modifer: add some draw function
 */

//constructor
DrawFunList::DrawFunList() {
  mapDrw = {
    {"m",  &DrawFunList::draw1},
    {"l",  &DrawFunList::draw2},
    {"h",  &DrawFunList::draw3},
    {"re", &DrawFunList::draw4},
    {"f",  &DrawFunList::draw5},
    {"c",  &DrawFunList::draw6},
    {"s",  &DrawFunList::draw7}
  };
}
//deconstructor
DrawFunList::~DrawFunList() {}

//TODO: implement each draw method
void DrawFunList::draw1(const std::vector<double>& operands, const int& currentIndex){
  path.moveTo(operands[0],operands[1]);
#if 0
        //sample code version 1(get current operator's data):
        std::cout << "\n" << "===============" << "\n" <<"this is sample code of getting current operands for current operator!" << "\n";

        std::cout << "Current operator is " << shape[currentIndex].getOpter() << "\n";

        for(auto ite = shape[currentIndex].getOpnds().begin(); ite != shape[currentIndex].getOpnds().end(); ++ite){
            std::cout << *ite << "\t\t";
        }
        std::cout << "\n" << "===============" << "\n";

        try{
          // draw 2d graphic here!
        }catch(std::exception &e){
          throw ExceptionDraw(shape[currentIndex].getOpter());
          return;
        }

        //sample code version 2(get other operators' data):
        std::string currentOperator = shape[currentIndex].getOpter();
        std::vector<double> currentOperands = shape[currentIndex].getOpnds();
        //Draw a circle on the main window and fulfill color

        //reference prevois operators and operands
        for(int i = currentIndex - 1; i >= 0; i--){
            if(shape[i].getOpter() == "c"){
                for(auto ite = shape[i].getOpnds().end(); ite != shape[i].getOpnds().begin(); --ite){
                    if(*ite == "red"){
                        //fulfill color
                    }
                }
            }
        }
#endif
}
void DrawFunList::draw2(const std::vector<double>& operands, const int& currentIndex){
  path.lineTo(operands[0],operands[1]);
}

void DrawFunList::draw3(const std::vector<double>& operands, const int& currentIndex){
  path.closeSubpath();
}

void DrawFunList::draw4(const std::vector<double>& operands, const int& currentIndex){
  path.addRect(operands[0],operands[1],operands[2],operands[3]);
}

void DrawFunList::draw5(const std::vector<double>& operands, const int& currentIndex){
  brush.setColor(operands[0]*255,operands[1]*255,operands[2]*255);
}

void DrawFunList::draw6(const std::vector<double>& operands, const int& currentIndex){
  path.cubicTo(operands[0],operands[1],operands[2],operands[3],operands[4],operands[5]);
}

void DrawFunList::draw7(const std::vector<double>& operands, const int& currentIndex){
  pen.setColor(operands[0]*255,operands[1]*255,operands[2]*255);
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
QPainter DrawFunList::getPen()
{
    return pen;
}
QPainter DrawFunList::getBrush()
{
    return brush;
}

