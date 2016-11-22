#include "ExceptionOptDic.hh"

std::ostream& ExceptionOptDic::operator << (std::ostream& s, const IsNotLowCaseChar& b) {
        return s << "Error: " << b.valChr << " is not low case character and is not in operators dictionary!" << "\n";
}