#include "frame.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Frame::Frame(double startX, double startY, double height, double width, int FrameNum):border(height,width),height(height),width(width),
    startX(startX),startY(startY),text(),frameNum(FrameNum)
{}

void Frame::clear(){

}//Reset all information to defalut value
void Frame::insertChar(char c){
    text.insertChar(c);
}

void Frame::insertString(const char *s){
    text.insertString(s);
}

void Frame::insert(char *s, bool withLink){
}

void Frame::insertSpace(){
    text.insertChar(' ');
} // insert a space
void Frame::insertReturn(){
    text.insertReturn();
}// insert return


void Frame::setText(Text& t){
    text=t;
}

Text Frame::getText(){
    return text;
}


void Frame::addTextLine(TextLine& tl){
    text.addTextLine(tl);
}
