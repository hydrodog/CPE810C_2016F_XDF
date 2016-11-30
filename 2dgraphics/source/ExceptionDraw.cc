#include "ExceptionDraw.hh"

/*
 @author: Seito Ryu  18/11/16
 */

std::ostream& ExceptionDraw::operator << (std::ostream& s, std::string currentOpter){
  return s << "Error: " << e.errCnt << ". When processing draw function! Operator is " << currentOpter << "!" << "\n";
}