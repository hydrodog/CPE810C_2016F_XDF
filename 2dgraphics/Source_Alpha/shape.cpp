#include "Shape.h"

/*
 @author: Seito Ryu  17/11/16
 */
Shape::~Shape(){
  if(opter != nullptr){
    delete opter;
  }
}
//copy constructor
Shape::Shape(const Shape& curShp){
  curX = curShp.curX;
  curY = curShp.curY;
  pageNo = curShp.pageNo;
  pageBot = curShp.pageBot;
  pageLef = curShp.pageLef;
  pageWid = curShp.pageWid;
  pageHei = curShp.pageHei;

  std::string tmpStr = curShp.opter;
  opter = new char[tmpStr.size() + 1];
  std::strcpy(opter, tmpStr.c_str());
  for(auto x: curShp.opnds){
    opnds.push_back(x);
  }
}
//add current operator into shape object
void Shape::setOpter(const std::string& val){
  opter = new char[val.size() + 1];
  std::strcpy(opter, val.c_str());
}
//add all numbers for drawing into shape object
void Shape::setOpnds(const std::vector<double>& val){
  for(auto x: val){
    opnds.push_back(x);
  }
}
//return shape object's operator
//inline const char*  Shape::getOpter() const{
std::string Shape::getOpter() const{
  return opter;
}
//return all numbers of the shape object
//inline const std::vector<double>& Shape::getOpnds() const{
const std::vector<double>& Shape::getOpnds() const{
  return opnds;
}

