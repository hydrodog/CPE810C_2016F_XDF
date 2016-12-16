#include "frame.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Frame::Frame(int startX, int startY, int height, int width, int FrameNum):m_frameNum(FrameNum),
    m_height(height),m_width(width),m_startX(startX),m_startY(startY),m_border(height,width),m_text()
{}

void Frame::clear(){
    m_height=0;
    m_width=0;
    m_startX=0;
    m_startY=0;
    m_frameNum=0;

}//Reset all information to defalut value


void Frame::addContent(Content c){//Add one content to the text
    m_text.addContent(c);
}
