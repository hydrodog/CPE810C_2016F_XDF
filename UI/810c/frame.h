#ifndef FRAME_HH__
#define FRAME_HH__
#include "border.h"
#include "text.h"
#include <string>
#include <list>

 //Represent a rectangle area to fill in all the Text or Image
class Frame{
    private:
        int m_frameNum;
        int m_height,m_width;
        int m_startX,m_startY;
        Border m_border;
        std::list<Frame> m_insideFrame;//If necessary  //TODO: choose better name:
        //list<Image> imageList;
        Text m_text;//Not sure make it a list or not
    //When change the border, need to update the width and height at the same time
    public:
        Frame(int startX,int startY,int height,int width,int FrameNum);
        void clear();//Reset all information to defalut value

        int  frameNum(){return m_frameNum;}
        int startX(){return m_startX;}
        int startY(){return m_startY;}
        int height(){return m_height;}
        int width(){return m_width;}

        void addContent(Content c);

        void text(Text& t){m_text=t;}
        Text text(){return m_text;}
        Border border(){return m_border;}


};



#endif
