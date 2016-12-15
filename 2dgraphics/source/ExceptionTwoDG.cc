#include "ExceptionTwoDG.h"

/*
 @author: Seito Ryu  18/11/16
 @modifer: Seito Ryu 1/12/16  "fix some bugs"
 */
#if 0
std::ostream& ExceptionTwoDG::operator << (std::ostream& s, const ExceptionTwoDG& e){
  return s << "Error: " << e.errCnt << ". When processing 2dgraphics!" << "\n";
}
#endif
std::string ExceptionTwoDG::getCng() const{
  return errCnt;
}
