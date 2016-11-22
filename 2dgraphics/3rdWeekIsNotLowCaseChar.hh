#ifndef EXCEPTION_OPTDIC_HH__
#define EXCEPTION_OPTDIC_HH__
/**
 @purpose:
 Exception class when processing operator list
 @author: Seito Ryu  17/11/16
 */
#include <iostream>
class ExceptionOptDic{
private:
char valChr;
public:
    ExceptionOptDic(char val): valChr(val) {}
    friend std::ostream& operator << (std::ostream& s, const ExceptionOptDic& b) {}
};
#endif