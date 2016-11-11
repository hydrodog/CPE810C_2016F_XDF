#include "page.h"

Page::Page(double height, double width, int pageNum):height(height),width(width),pageNumber(pageNum)
{
}
void Page::clear(){

}//Reset all information to defalut value
void Page::print(){

}
void Page::save(){

}
void Page::import(){

}//Way to import a file  NOT YOUR PROBLEM

void Page::addNewFrame(double x,double y, double height,double width){
    Frame f(x,y,height,width);
    frameList.push_back(f);
}

void Page::addFrame(Frame& f){
    frameList.push_back(f);
}

std::list<Frame> Page::getFrameList(){
    return frameList;
}

int Page::getPageNumber(){
    return pageNumber;
}

void Page::setPageNumber(int i){
    pageNumber=i;
}

double Page::getHeight(){
    return height;
}

double Page::getWidth (){
    return width;
}

