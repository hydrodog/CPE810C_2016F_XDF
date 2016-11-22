#include "page.h"

Page::Page(int height, int width, int pageNum):m_pageNumber(pageNum),m_height(height),m_width(width)
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

void Page::addNewFrame(int startX, int startY, int height, int width, int FrameNum){
    Frame f(startX,startY,height,width,FrameNum);
    m_frameList.push_back(f);
}

void Page::addFrame(Frame& f){
    m_frameList.push_back(f);
}


