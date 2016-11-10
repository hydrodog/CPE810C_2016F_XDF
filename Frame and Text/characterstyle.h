#ifndef CHARACTERSTYLE_H__
#define CHARACTERSTYLE_H__
#include <string>

class CharacterStyle{
//This class represent a single character and it has its own different style
private:
    std::string language;
    int c;
    std::string font;
    double  size;
    int bold;
    bool italic;
    bool underline;
public:
    CharacterStyle();

};

#endif // CHARACTERSTYLE_H
