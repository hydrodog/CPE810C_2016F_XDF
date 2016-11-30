#ifndef EXCEPTION_DRAW_HH__
#define EXCEPTION_DRAW_HH__

#include <string>
#include <iostream>

/*
 @author: Seito Ryu  18/11/16
 @Purpose: Exception class for draw methods
 @modifer: Seito Ryu 30/11/16 "delete the function: getCng"
 */
class ExceptionDraw{
private:
  std::string errCnt;
public:
  ExceptionDraw(std::string val): errCnt(val) {}
  friend std::ostream& operator << (std::ostream& s, const ExceptionDraw& e){}
};

#endif