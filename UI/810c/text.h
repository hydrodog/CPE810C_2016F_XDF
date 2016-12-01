#ifndef TEXT_HH__
#define TEXT_HH__
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
    std::list<Content> m_contentList;
    int m_len;
    int n=0;
public:
    Text();
    int getnumber();
    //void dealContentmessage();
    void insertString(const char *s);//insert a string
    void getText(const wstring w,const string v);
    //void getallfont(const string v);

    int len(){return m_len;}

    std::list<Content> contentList() const{return m_contentList;}

    void addContent(Content c);

};

#endif // TEXT_H
