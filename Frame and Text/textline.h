#ifndef TEXTLINE_H__
#define TEXTLINE_H__
#include "characterstyle.h"
#include <string>
#include <list>
#include <map>

class TextLine{
/*A line should have a bunch of characters and length and height
*If one line’s length is wider than the width of frame, create a new line
*/
private:
    std::map<int,CharacterStyle> characterMap;
    //Every index of char in string should have a characterStyle
    std::string lineStyle;
    std::list<char> lineContent;//The list contains whole text content
    double width;
    double height;
public:
    TextLine();
    void insert(std::string s, CharacterStyle);//insert a string with same style
    void insert(char c,   CharacterStyle);//inset a character
    void insertSpace(); // insert a space
    void deleteCharacter(int i);//Delete Character at index i


};

#endif // TEXTLINE_H
