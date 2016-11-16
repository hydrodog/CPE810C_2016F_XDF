#ifndef TEXTLINE_H__
#define TEXTLINE_H__
#include <string>
#include <list>
#include <map>
#include <myfont.h>
#include <vector>
#include <string>

extern int PublicLinecode;
class TextLine{
/*A line should have a bunch of characters and length and height
*If one line’s length is wider than the width of frame, create a new line
*/
private:
    //Every index of char in string should have a characterStyle
    int linecode;
    std::string lineStyle;
    std::vector<char> lineContent;//The list contains whole text content
    //std::map<int,myFont> specialFontList;
public:
    TextLine();
    void insertString(const char *s);//insert a string with same style
    void insertChar(const char  c);//inset a character
    void deleteCharacter(int i);//Delete Character at index i
    void setlineStyle(char*);
    std::vector<char> getLineContent(){return lineContent;}

};
#endif // TEXTLINE_H
