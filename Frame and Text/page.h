#ifndef PAGE_H__
#define PAGE_H__
#include "frame.h"

class Page{//Maybe a class should be written by other team
/*This class represents a single page of XDF
*Information such as the text is left to right or right to left, horizontal or vertical, the heights and width of the page and a rectangle frame in the page.
*Function like import,export.
*/
private:
    int pageNumber;
    Frame frame;     // maybe more than one frame????
    double height,width;
    bool LtoR;//Left to right or right to left
    bool horizontal;// horizontal or vertical
public:
    Page(double height, double width,bool LtoR,bool horizontal,int pageNum);

    void clear();//Reset all information to defalut value
    void print();
    void save();
    void import();//Way to import a file  NOT YOUR PROBLEM
    Frame getFrame();
};


#endif // PAGE_H
