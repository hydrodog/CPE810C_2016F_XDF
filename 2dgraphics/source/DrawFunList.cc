#include "DrawFunList.hh"

//constructor
DrawFunList::DrawFunList() {
  mapDrw = {
    {"m",  &DrawFunList::draw1},
    {"l",  &DrawFunList::draw2},
    {"h",  &DrawFunList::draw3},
    {"re", &DrawFunList::draw4},
    {"f",  &DrawFunList::draw5}
  };
}
//deconstructor
DrawFunList::~DrawFunList() {}

//TODO: implement each draw method
void DrawFunList::draw1(const std::vector<Shape>& shape, const int& currentIndex){
  std::cout << "\t\t" << "This is draw1!" << "\t";
#if 0
  std::string currentOperator = shape[currentIndex].getOpter();
  std::vector<double> currentOperands = shape[currentIndex].getOpnds();
  
  //using QT Painter method to draw certain shapes on the main window and fulfill color if necessary
  
  //if current information is not enough to make a draw, using shape object can reference all other operators and operands
  for(int i = 0; i < shape[currentIndex].getOpnds().size(); ++i){
    if(shape[i].getOpter() == "c"){
      for(auto ite = shape[i].getOpnds().end(); ite != shape[i].getOpnds().begin(); --ite){
        if(*ite == "red"){
          //draw shape and fulfill color
        }
      }
    }
  }
#endif
}
void DrawFunList::draw2(const std::vector<Shape>& shape, const int& currentIndex){
  std::cout << "\t\t" << "This is draw2!" << "\t";
}
void DrawFunList::draw3(const std::vector<Shape>& shape, const int& currentIndex){
  std::cout << "\t\t" << "This is draw3!" << "\t";
}
void DrawFunList::draw4(const std::vector<Shape>& shape, const int& currentIndex){
  std::cout << "\t\t" << "This is draw4!" << "\t";
}
void DrawFunList::draw5(const std::vector<Shape>& shape, const int& currentIndex){
  std::cout << "\t\t" << "This is draw5!" << "\t";
//draw function table
DrawFunList::draw(const std::string& currentOperator, const std::vector<Shape>& shapeList, const int& currentIndex){
  if(mapDrw[currentOperator]){
    (this->*mapDrw[currentOperator])(shapeList, currentIndex);
  }
}