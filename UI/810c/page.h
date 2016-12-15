#ifndef PAGE_HH__
#define PAGE_HH__
#include "frame.h"
#include <list>


/*This class represents a single page of XDF
*Information such as the text is left to right or right to left, horizontal or vertical, the heights and width of the page and a rectangle frame in the page.
*Function like import,export.
*/
class Page{
private:
    int m_pageNumber;
    std::list<Frame> m_frameList;
    int m_height,m_width;
    bool m_LtoR;//Left to right or right to left
public:
    Page(int height, int width, int pageNum);

    void clear();//Reset all information to defalut value
    void print();
    void save();
    void import();//Way to import a file  NOT YOUR PROBLEM
    void addNewFrame(int startX, int startY, int height, int width, int FrameNum);
    void addFrame(Frame& f);

    std::list<Frame> frameList(){ return m_frameList;}
    int pageNumber(){ return m_pageNumber;}
    int height(){return m_height;}
    int width (){return m_width;}



};


#endif // PAGE_H
