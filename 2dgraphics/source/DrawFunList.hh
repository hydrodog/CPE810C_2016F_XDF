#ifndef DRAW_FUNLIST_HH__
#define DRAW_FUNLIST_HH__

#include "Shape.h"
#include "ExceptionDraw.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

/*
 @author: Seito Ryu  20/11/16
 @Purpose: Set all QT draw methods and initialize operator:method set
 @modifer: Seito Ryu 1/12/16  "fix some bugs"
 */
/**
 TODO: implement basic and complicated QT methods
*/
class DrawFunList{
private:
  std::map<std::string, void (DrawFunList::*)(const std::vector<Shape>&, const int&)> mapDrw;
  void draw1(const std::vector<Shape>& shape, const int& currentIndex);
  void draw2(const std::vector<Shape>& shape, const int& currentIndex);
  void draw3(const std::vector<Shape>& shape, const int& currentIndex);
  void draw4(const std::vector<Shape>& shape, const int& currentIndex);
  void draw5(const std::vector<Shape>& shape, const int& currentIndex);
public:
    DrawFunList();
    ~DrawFunList();
    void draw(const std::string& currentOperator, const std::vector<Shape>& shapeList, const int& currentIndex);
};

#endif
