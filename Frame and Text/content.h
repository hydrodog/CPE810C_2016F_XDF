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
#include <windows.h>
#include<QString>
#include<QFont>
#include<Qcolor>
using namespace std;
void Wchar_tToString(std::string& szDst,const wchar_t *wchar); //This function is copied from the Internet,just for testing the wchar.
class Content{
private:
    QFont font;
    QColor color;
    int k;
    int n=0;
    wchar_t *words=new wchar_t [k];
    int *changelinepos=new int[n];
    map<int,string> alignment;
public:
    Content(){};
    void getmessage(wstring a);
    void getfont(string a);
    QFont contentFont();
    void getalignment(int *n,int *m);
    map<int,string> exportalignment();
    wchar_t* getword();
    int getlength();
    int* getlinechange();
    int getlineamount();
    QString getQString();
};

#endif // CONTENT_H
