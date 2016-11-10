#include "frame.h"

Frame::Frame(double height,double width,bool LtoR,bool horizontal):border(height,width),height(height),width(width),LeftToRight(LtoR),horizontal(horizontal)
{
}


void Frame::clear(){

}//Reset all information to defalut value
void Frame::insert(std::string s, CharacterStyle cs, bool withLink){

}//insert a string with a link or not
void Frame::insert(char c,   CharacterStyle cs){

}//insert a character with certain style
void Frame::insertSpace(){

} // insert a space
void Frame::insertReturn(){

}// insert return
