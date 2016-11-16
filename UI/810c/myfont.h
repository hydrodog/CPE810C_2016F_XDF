#ifndef MYFONT_H
#define MYFONT_H

#include <string>


class myFont{
//This class represent a single character and it has its own different style
private:
    std::string language;
    int color;
    std::string font;
    double  size;
    int bold;
    bool italic;
    bool underline;
public:
    myFont(std::string l="English",int c=255,std::string f="times",double s=11.0,int b=1,bool i=false,bool u=false);

};


#endif // MYFONT_H
