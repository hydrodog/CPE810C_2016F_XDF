#ifndef FRAME_HH__
#define FRAME_HH__
#include "border.h"
#include "text.h"
#include <string>
#include <list>

 //Represent a rectangle area to fill in all the Text or Image
class Frame{
    private:
        int m_frameNum;//the numbers of frames
        int m_height,m_width;//the height and width of each frame
        int m_startX,m_startY;//the start point of each frame
        int m_type;//0 is pure text, 1 is image, 2 is 2d graphic

        Border m_border;// call the object of the class Border
        std::list<Frame> m_insideFrame;//If necessary
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
        int type(){return m_type;}
        void addContent(Content c);

        void text(Text& t){m_text=t;}
        Text text(){return m_text;}
        Border border(){return m_border;}


};



#endif
