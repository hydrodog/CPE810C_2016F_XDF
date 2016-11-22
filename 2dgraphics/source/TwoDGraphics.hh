#ifndef TWO_DGRAPHICS_HH__
#define TWO_DGRAPHICS_HH__

#include <string>
#include <iostream>

/*
 @author: Seito Ryu  18/11/16
 @Purpose: Exception class for twoDGraphics
 */
class TwoDGraphics{
private:
  std::string errCnt;
public:
  TwoDGraphics(std::string val): errCnt(val) {}
  friend std::ostream& operator << (std::ostream& s, const TwoDGraphics& e){}
  std::string getCng() const{}
};

#endif