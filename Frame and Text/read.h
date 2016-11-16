#ifndef READ_H
#define READ_H
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include "font.h"
using namespace std;
class Read{
private:
    map<int,char> m;
    map<int,string> lc,pc;
public:
    Read(){};
    void readContent();
};
#endif // READ_H
