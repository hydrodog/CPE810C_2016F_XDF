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
#include<QString>
#include<QFont>
#include<Qcolor>
using namespace std;
class Content{
private:

    QFont m_font;
    QColor m_color;
    std::wstring m_str;
    int k;
    int n=0;
    wchar_t *words=new wchar_t [k];
    int *changelinepos=new int[n];
    map<int,string> alignment;
public:
    void getmessage(std::wstring a);
    void getfont(std::string a);

    QFont font(){return m_font;}
    QColor color(){return m_color;}
    std::wstring str(){return m_str;}
    void str(std::wstring str){m_str=str;}
    void font(QFont f){m_font=f;}
    void color(QColor c){m_color=c;}

    void getalignment(int *n,int *m);
    map<int,string> exportalignment();
    wchar_t* getword();
    int getlength();
    int* getlinechange();
    int getlineamount();
    QString getQString();
};

#endif // CONTENT_H
