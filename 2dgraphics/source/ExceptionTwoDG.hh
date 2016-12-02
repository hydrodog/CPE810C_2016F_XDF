#ifndef EXCEPTION_TWODG_HH__
#define EXCEPTION_TWODG_HH__

#include <iostream>
#include <string>

/*
 @author: Seito Ryu  18/11/16
 @Purpose: Exception class for twoDGraphics class
 @modifer: Seito Ryu 1/12/16  "fix some bugs"
 */
class ExceptionTwoDG{
private:
  std::string errCnt;
public:
  ExceptionTwoDG(std::string val): errCnt(val) {}
#if 0
  friend std::ostream& operator << (std::ostream& s, const ExceptionTwoDG& e);
#endif
  std::string getCng() const;
};

#endif
