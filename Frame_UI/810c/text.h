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
    std::list<Content> m_contentList;  //make a list to store the Content objects
    //int m_len;
    int n=0;   //represent how many Content objects this Text object have
    int m_imagepos[100]={0};         //the image position
    int m_imagenum=0;               //how many images does this Text object have
public:
    Text();
    int getnumber();    //get the quantity of Content objects in the Text object
    //void dealContentmessage();
    int* getimagepos();     //get the image position
    void readInText(const wstring w,const string v);      //read in the message the other groups give to us
    //void getallfont(const string v);
    int getimagenum();                               //get the quantity of image in the Text object
    //int len(){return m_len;}

    std::list<Content> contentList() const{return m_contentList;}  //get the Content objects in the Text object

    void addContent(Content c);  //read in addition Content object into the object, mostly needn't use this function

};

#endif // TEXT_H
