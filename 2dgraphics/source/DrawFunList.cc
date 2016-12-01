#include "DrawFunList.hh"

/*
 @author: Seito Ryu  20/11/16
 @modifer: Seito Ryu 30/11/16 "add some sample code"
 */

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
}
//draw function table
DrawFunList::draw(const std::string& currentOperator, const std::vector<Shape>& shapeList, const int& currentIndex){
  if(mapDrw[currentOperator]){
    (this->*mapDrw[currentOperator])(shapeList, currentIndex);
  }
}