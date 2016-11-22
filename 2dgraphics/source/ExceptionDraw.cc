#include "ExceptionDraw.hh"

/*
 @author: Seito Ryu  18/11/16
 */

std::ostream& ExceptionDraw::operator << (std::ostream& s, const EcpDraw& e){
  return s << "Error: " << e.errCnt << ". When processing 2dgraphics!" << "\n";
}

std::string ExceptionDraw::getCng() const{
  return errCnt;
}
