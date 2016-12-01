#ifndef PAGE_HH__
#define PAGE_HH__
#include "frame.h"
#include <list>

class Page{//Maybe a class should be written by other team
/*This class represents a single page of XDF
*Information such as the text is left to right or right to left, horizontal or vertical, the heights and width of the page and a rectangle frame in the page.
*Function like import,export.
*/
private:
//    int m_pageNumber;
    std::list<Frame> m_frameList;
//    int m_height,m_width;
//    bool m_LtoR;//Left to right or right to left
//    bool m_horizontal;// horizontal or vertical
public:
    Page(int height, int width, int pageNum);
    Page();

//    void clear();//Reset all information to defalut value
//   void print();
//    void save();
//    void import();//Way to import a file  NOT YOUR PROBLEM
//    void addNewFrame(int startX, int startY, int height, int width, int FrameNum);
//    void addFrame(Frame& f);

    std::list<Frame> frameList(){
        Frame f1(20,20,100,100,0);
        Frame f2(140,140,20,20,0);
        Frame f3(200,200,30,30,0);
        Frame f4(300,200,70,70,0);

        f1.setType(1);
        f2.setType(1);
        f3.setType(1);
        f4.setType(1);


        m_frameList.push_back(f1);

        m_frameList.push_back(f2);
        m_frameList.push_back(f3);
        m_frameList.push_back(f4);
        return m_frameList;
    }
//    int pageNumber(){ return m_pageNumber;}
//    int height(){return m_height;}
//    int width (){return m_width;}



};


#endif // PAGE_H
