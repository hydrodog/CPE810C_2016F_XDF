#include "ExceptionOptDic.h"

/**
  @author: Seito Ryu  17/11/16
  @modifer: Seito Ryu 1/12/16  "fix some bugs"
*/
#if 0
std::ostream& ExceptionOptDic::operator << (std::ostream& s, const IsNotLowCaseChar& b) {
  return s << "Error: " << b.valChr << " is not low case character and is not in operators dictionary!" << "\n";
}
#endif
