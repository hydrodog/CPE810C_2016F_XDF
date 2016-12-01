#ifndef TEXTLINE_HH__
#define TEXTLINE_HH__
#include <string>
#include <list>
#include <map>
#include <vector>


extern int PublicLinecode;
class TextLine{
/*A line should have a bunch of characters and length and height
*If one line’s length is wider than the width of frame, create a new line
*/
private:
    //Every index of char in string should have a characterStyle
    int m_linecode;
    std::vector<char> m_lineContent;//The list contains whole text content
    //std::map<int,myFont> specialFontList;
public:
    TextLine();
    void insertString(const char *s);//insert a string with same style
    void insertChar(const char  c);//inset a character
    std::vector<char> lineContent(){return m_lineContent;}

};
#endif // TEXTLINE_H