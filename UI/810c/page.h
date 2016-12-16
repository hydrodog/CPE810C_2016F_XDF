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
    std::list<Frame> m_frameList;//A list of frame in the page
    int m_height;
    int m_width;
    std::string m_backgroudColor;
    bool m_LtoR;//Left to right or right to left
public:
    Page(int height, int width, int pageNum);

    void clear();//Reset all information to defalut value
    void print();
    void save();
    void import();//Way to import a file
    void addNewFrame(int startX, int startY, int height, int width, int FrameNum);
    void addFrame(Frame& f);//Add a given frame to the list


    std::list<Frame> frameList(){ return m_frameList;}
    int pageNumber(){ return m_pageNumber;}
    int height(){return m_height;}
    int width (){return m_width;}
    std::string backgroudColor(){return m_backgroudColor;}
    void backgroudColor(std::string s){ m_backgroudColor=s;}



};


#endif // PAGE_H
