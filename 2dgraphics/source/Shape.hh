#ifndef SHAPE_HH__
#define SHAPE_HH__

#include <iostream>
#include <vector>
#include <string>
/*
 @author: Seito Ryu  17/11/16
 @purpose: store data of each 2dgraphics, each shape object is one unit for draw method
 */
 //TODO: Confirm: how many variables necessary and whether there are others
class Shape{
private:
  double curX;
  double curY;
  int pageNo;
  double pageBot;
  double pageLef;
  double pageWid;
  double pageHei;
  //currently, variables below using is enough for draw a shape using QT painter
  char* opter;
  std::vector<double> opnds;
public:
  Shape(double curX = 0, double curY = 0, int pageNo = 0, double pageBot = 0, double pageLef = 0, double pageWid = 0, double pageHei = 0, char* opter = nullptr, std::vector<double> opnds = {}): curX(curX), curY(curY), pageNo(pageNo), pageBot(pageBot), pageLef(pageLef), pageWid(pageWid), pageHei(pageHei), opter(opter), opnds(opnds) {}
  ~Shape(){}
  //copy constructor
  Shape(const Shape& curShp){}
  //add current operator into shape object
  void setOpter(const std::string& val){}
  //add all numbers for drawing into shape object
  void setOpnds(const std::vector<double>& val){}
  //return shape object's operator
  //inline std::string getOpter() const{
  inline const char*  getOpter() const{}
  //return all numbers of the shape object
  inline const std::vector<double>& getOpnds() const{}
};
#endif