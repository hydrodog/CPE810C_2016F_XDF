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
    string words;
public:
    Content(){};
    void getmessage();
    void getfont();
    myFont contentFont();
};

#endif // CONTENT_H
