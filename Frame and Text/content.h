#ifndef CONTENT_H
#define CONTENT_H
/*This head file "content" is written by the Frame and Text group,we share it with the
 * print group!
 */
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <font.h>
using namespace std;
class Content{
private:
	typedef map<string,int>::iterator It;
    map<char,int> m;
    myFont t;
public:
    Content();
    void getmessage();
    void getfont();
    void exportContent();
    void contentFont();
};

#endif // CONTENT_H
