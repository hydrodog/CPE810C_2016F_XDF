#ifndef TEXT_HH__
#define TEXT_HH__
#include <string>
#include <map>
#include <list>
#include "content.h"
using namespace std;
class Text{
/*
 * Represents the words and text in the frame
 * Contains a list of Content instance
 *
*/

private:
    std::list<Content> m_contentList;
    int m_len;
    int n=0;
public:
    Text();
    int getnumber();
    //void dealContentmessage();

    void getText(const wstring w,const string v);
    //void getallfont(const string v);

    int len(){return m_len;}

    std::list<Content> contentList() const{return m_contentList;}

    void addContent(Content c);

};

#endif // TEXT_H
