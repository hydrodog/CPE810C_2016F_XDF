#include "page.h"

Page::Page(double height, double width,bool LtoR,bool horizontal,int pageNum):
    frame(height,width,LtoR,horizontal),height(height),width(width),LtoR(LtoR),horizontal(horizontal),pageNumber(pageNum)
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

Frame Page::getFrame(){
    return frame;
}
