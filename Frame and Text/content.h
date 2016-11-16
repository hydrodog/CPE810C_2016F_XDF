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
void ReadDataFromFileLBLIntoCharArray() {
    ifstream fin("data.txt");
    const int LINE_LENGTH = 10;
    char str[LINE_LENGTH];
    string *k;
    int i=0;
    while( fin.getline(str,LINE_LENGTH) )
    {
        k[i]=str;
        i++;
    }
}
class Content{
private:
    myFont t;
    Read r;
    string* contentFont = new string[6];
public:
    Content(){};
    void getmessage();
    void getfont();
    list<char> exportContent();
    //myFont contentFont();
};

#endif // CONTENT_H
