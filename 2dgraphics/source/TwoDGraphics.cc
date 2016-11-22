#include "TwoDGraphics.hh"

std::ostream& TwoDGraphics::operator << (std::ostream& s, const Ecp2dGpc& e){
  return s << "Error: " << e.errCnt << ". When processing 2dgraphics!" << "\n";
}

std::string TwoDGraphics::getCng() const{
  return errCnt;
}