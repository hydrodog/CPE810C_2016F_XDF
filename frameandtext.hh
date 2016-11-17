
#ifndef FRAMEANDTEXT_H
#define FRAMEANDTEXT_H



/*This head file "content" is written by the Frame and Text group,we share it with the
 * print group!
 */
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>
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
    // added for testing @fanyang
    string getLanguage(){
        return language;
    }
    int getColor(){
        return color;
    }
    string getFont(){
        return font;
    }
    double getSize(){
        return size;
    }
    int getBold(){
        return bold;
    }
    bool getItalic(){
        return italic;
    }
    bool getUnderline(){
        return underline;
    }

};


class Content{
private:
    myFont t;
    string words;
public:
    Content();
    void getmessage();
    void getfont();
    myFont contentFont();
};

#endif // FRAMEANDTEXT_H
