#include <string>
#include <vector>
#include <iostream>
#include "shape.h"
#include "drawfunlist.h"
#include "exceptionoptdic.h"
#include "exceptiontwodg.h"
#include "operatordictrie.h"
#include "twodgraphics.h"

/*
 @author: Seito Ryu  18/11/16
 @Purpose: set test data and draw graphic
 @modifer: Seito Ryu 1/12/16  "fix some bugs"
 */

int main(){
#if 0
  twoDGraphics* twoDGph;
#endif
  //read operator.dat file from config folder in the current directory,
  twoDGraphics* twoDGph = new twoDGraphics("D:\EE810_Project","test.txt");
  //set test data: set each shape info seperately
  //1st shape:
  std::string opter1 = "m";
  std::vector<double> opnds1;
  opnds1.push_back(12.21);
  opnds1.push_back(34.43);
  twoDGph->setShape(opter1, opnds1);
  //2nd shape:
  std::string opter2 = "l";
  std::vector<double> opnds2;
  opnds2.push_back(56.65);
  opnds2.push_back(78.87);
  twoDGph->setShape(opter2, opnds2);

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