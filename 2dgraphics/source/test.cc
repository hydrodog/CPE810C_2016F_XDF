#include <string>
#include <vector>
#include <iostream>

int main(){
  twoDGraphics* twoDGph;
  DrawFunList drawFunList;
  int i = 0;
  
  for(auto ite = twoDGph->getAllShape().begin(); ite != twoDGph->getAllShape().end(); ++ite, ++i){
    std::string curOpt = ite->getOpter();
    
    std::cout << "Operator is " << curOpt << "\t";
    std::vector<double> allOpnds = ite->getOpnds();
    
    drawFunList.draw(curOpt, twoDGph->getAllShape(), i);
    
    for(auto iteOpnds = allOpnds.begin(); iteOpnds != allOpnds.end(); ++iteOpnds){
      std::cout << "\t\t" << *iteOpnds;
    }
    std::cout << "\n";
  }
}