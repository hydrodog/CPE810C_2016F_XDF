#include "ExceptionTwoDG.hh"

ExceptionTwoDG::ExceptionTwoDG(std::string val): errCnt(val) {}
friend std::ostream& ExceptionTwoDG::operator << (std::ostream& s, const ExceptionTwoDG& e){
  return s << "Error: " << e.errCnt << ". When processing 2dgraphics!" << "\n";
}

std::string ExceptionTwoDG::getCng() const{
  return errCnt;
}

#endif