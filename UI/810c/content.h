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
    int k;
    int n=0;
    char *words=new char [k];
    int *changelinepos=new int[n];
    map<int,string> alignment;
public:
    Content();
    void getmessage(string a);
    void getfont(string a);
    myFont contentFont();
    void getalignment(int *n,int *m);
    map<int,string> exportalignment();
    char* getword();
    int getlength();
    int* getlinechange();
    int getlineamount();
};

#endif // CONTENT_H
