#ifndef IMPORTMESSAGE_H
#define IMPORTMESSAGE_H
/*This head file "importmessage" is written by the Frame and Text group,we share it with the
 * print group!
 */
#include<string>
#include<iostream>
#include<map>
#include<fstream>
#include<myfont.h>
using namespace std;
class ImportMessage{
private:
    map<char,int> m;
    myFont t;
public:
    ImportMessage();
    void getmessage();
    void getfont();
    void givemessage();
    void givefont();
};

#endif // IMPORTMESSAGE_H
