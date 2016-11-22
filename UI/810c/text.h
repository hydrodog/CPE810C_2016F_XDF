#ifndef TEXT_HH__
#define TEXT_HH__
#include "textline.h"
#include <string>
#include <map>
#include <list>
#include "content.h"
using namespace std;
class Text{
/*This class represents the words and text in the frame
*Contains the width and height of this text
*If the height of all lines is over than the height of frame, create a new frame or page
*/

private:
    std::list<TextLine> m_textLineList;
    std::list<Content> m_contentList;
    int m_len;
public:
    Text();


    void insertString(const char *s);//insert a string
    void getText(const wstring w);
    void insertChar(const char c);//inset a character

    void insertReturn();//insert return

    void addTextLine(TextLine &);

    int len(){return m_len;}

    std::list<TextLine> textLineList() const{return m_textLineList;}

    std::list<Content> contentList() const{return m_contentList;}

    void addContent(Content c);

};

#endif // TEXT_H
