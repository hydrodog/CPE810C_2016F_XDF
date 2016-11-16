#ifndef TEXT_H__
#define TEXT_H__
#include "myfont.h"
#include "textline.h"
#include <string>
#include <map>
#include <list>

class Text{
/*This class represents the words and text in the frame
*Contains the width and height of this text
*If the height of all lines is over than the height of frame, create a new frame or page
*/

private:
    myFont defalutFont;// A List of line in the text
    std::list<TextLine> textLineList;
    int len;
    double linespace;
public:
    Text();


    void insertString(const char *s);//insert a string

    void insertChar(const char c);//inset a character

    void insertReturn();//insert return

    void deleteLine(int i);//Delete line at index i

    void setLineSpace(double);

    double getLineSpace();

    myFont getDefalutFont();

    void setDefalutFont(myFont&);

    void addTextLine(TextLine &);

    int getLen(){return len;}
    std::list<TextLine> getTextLineList() const;

};

#endif // TEXT_H
