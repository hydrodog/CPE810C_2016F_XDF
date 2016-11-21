#ifndef CONTENT_HH__
#define CONTENT_HH__
/*This head file "content" is written by the Frame and Text group,we share it with the
 * print group!
 */
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <QFont>
#include <QColor>

class Content{
private:
    QFont font;
    QColor color;
    std::wstring content;
    int k;
    int n=0;
    char *words;
    int *changelinepos=new int[n];
    std::map<int,std::string> alignment;
public:
    Content();
    void getmessage(std::string a);
    void getfont(std::string a);
    QFont getContentFont();
    QColor getContentColor();
    void setFont(QFont f);
    void setColor(QColor c);
    void getalignment(int *n,int *m);
    std::map<int,std::string> exportalignment();
    char* getword();
    int getlength();
    int* getlinechange();
    int getlineamount();
};

#endif // CONTENT_H
