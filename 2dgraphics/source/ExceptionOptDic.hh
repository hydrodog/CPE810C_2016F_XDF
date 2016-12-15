#ifndef EXCEPTION_OPTDIC_HH__
#define EXCEPTION_OPTDIC_HH__

#include <iostream>

/**
 @author: Seito Ryu  17/11/16
 @purpose: Exception class when processing operator list
 */
class ExceptionOptDic{
private:
  char valChr;
public:
  ExceptionOptDic(char val): valChr(val) {}
    friend std::ostream& operator << (std::ostream& s, const ExceptionOptDic& b) {}
  };
#endif