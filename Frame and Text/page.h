#ifndef PAGE_H__
#define PAGE_H__
#include "frame.h"
#include <list>

class Page{//Maybe a class should be written by other team
/*This class represents a single page of XDF
*Information such as the text is left to right or right to left, horizontal or vertical, the heights and width of the page and a rectangle frame in the page.
*Function like import,export.
*/
private:
    int pageNumber;
    std::list<Frame> frameList;
    double height,width;
    bool LtoR;//Left to right or right to left
    bool horizontal;// horizontal or vertical
public:
    Page(double height, double width, int pageNum);

    void clear();//Reset all information to defalut value
    void print();
    void save();
    void import();//Way to import a file  NOT YOUR PROBLEM
    void addNewFrame(double x,double y, double height,double width);
    void addFrame(Frame& f);
    std::list<Frame> getFrameList();
    int getPageNumber();
    double getHeight();
    double getWidth ();
    void setPageNumber(int i);

};


#endif // PAGE_H
