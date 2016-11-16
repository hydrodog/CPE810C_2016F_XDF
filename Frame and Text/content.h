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
#include "read.h"
using namespace std;
class Content{
private:
	typedef map<string,int>::iterator It;
    map<int,char> m;
    map<int,string> lc,pc;
    myFont t;
    Read r;
    string* contentFont = new string[6];
public:
    Content(){};
    void getmessage();
    void getfont();
    list<char> exportContent();
    myFont contentFont();
};

#endif // CONTENT_H
