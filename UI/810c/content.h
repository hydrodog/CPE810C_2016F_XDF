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
#include "myfont.h"

using namespace std;

class Content{
private:
    myFont t;
    string words;
    map<int,string> alignment;
public:
    Content();
    void getmessage();
    void getfont();
    myFont contentFont();
    void getalignment(int *n,int *m);
    map<int,string> exportalignment();
};

#endif // CONTENT_H
