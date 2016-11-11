#ifndef TEXTLINE_H__
#define TEXTLINE_H__
#include <string>
#include <list>
#include <map>
#include <myfont.h>


class TextLine{
/*A line should have a bunch of characters and length and height
*If one line’s length is wider than the width of frame, create a new line
*/
private:
    //Every index of char in string should have a characterStyle
    char* lineStyle;
    std::list<char> lineContent;//The list contains whole text content
    std::map<int,myFont> specialFontList;
public:
    TextLine();
    void insert(char *s);//insert a string with same style
    void insert(char  c);//inset a character
    void deleteCharacter(int i);//Delete Character at index i
    void setlineStyle(char*);

};

#endif // TEXTLINE_H
