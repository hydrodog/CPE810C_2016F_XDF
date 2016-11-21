#ifndef TEXT_H__
#define TEXT_H__
#include "myfont.h"
#include "textline.h"
#include <string>
#include <map>
#include <list>
#include "content.h"

class Text{
/*This class represents the words and text in the frame
*Contains the width and height of this text
*If the height of all lines is over than the height of frame, create a new frame or page
*/

private:
    std::list<TextLine> textLineList;
    std::list<Content> contentList;
    int len;
    double linespace;
public:
    Text();


    void insertString(const char *s);//insert a string

    void insertChar(const char c);//inset a character

    void insertReturn();//insert return

    void setLineSpace(double);

    double getLineSpace();

    void addTextLine(TextLine &);

    int getLen(){return len;}

    std::list<TextLine> getTextLineList() const;

    std::list<Content> getContentList() const;

    void addContent(Content c);

};

#endif // TEXT_H
