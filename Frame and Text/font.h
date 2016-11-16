#ifndef FONT_H
#define FONT_H

#include <string>

using namespace std;

class myFont{
//This class represent a single character and it has its own different style
private:
    string language;
    int color;
    string font;
    double size;
    int bold;
    bool italic;
    bool underline;
public:
    myFont(string l="English",int c=255,string f="times",double s=11.0,int b=1,bool i=false,bool u=false);
    void setfont(string l,int c,string f,double s,int b,bool i,bool u);
    friend ostream& operator <<(ostream& s, myFont f) {
        return s << f.language << f.font;
    }
};

#endif // FONT_H
