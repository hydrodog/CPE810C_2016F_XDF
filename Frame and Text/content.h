#ifndef CONTENT_H
#define CONTENT_H
/*This head file "content" is written by the Frame and Text group,we share it with the
 * print group!
 */
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include "font.h"

using namespace std;

class Content{
private:
    myFont t;
    int k;
    char *words=new char [k];
    map<int,string> alignment;
public:
    Content(){};
    void getmessage(string a);
    void getfont(string a);
    myFont contentFont();
    void getalignment(int *n,int *m);
    map<int,string> exportalignment();
    char* getword();
    int getlength();
};

#endif // CONTENT_H
