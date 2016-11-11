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
    myFont();

};


#endif // MYFONT_H
