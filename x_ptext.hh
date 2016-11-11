#ifndef X_PTEXT_H
#define X_PTEXT_H

#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

class PText{
private:
    string text;
    string fileName;

public:
    PText(string name);
    void print(int x, int y);//print this text out

};

#endif // X_PTEXT_H
