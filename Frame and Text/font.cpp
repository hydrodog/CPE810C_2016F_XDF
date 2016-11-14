#include "font.h"

myFont::myFont(string l,int c,string f,double s,int b,bool i,bool u):language(l),color(c),font(f),size(s),bold(b),italic(i),underline(u)
{

}

void myFont::setfont(string l,int c,string f,double s,int b,bool i,bool u){
    language=l;
    color=c;
    font=f;
    size=s;
    bold=b;
    italic=i;
    underline=u;
}
