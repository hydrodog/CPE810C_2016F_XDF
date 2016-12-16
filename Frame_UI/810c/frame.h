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

        std::string m_shape;//Shape style
        std::string m_shadow;//Shadow style
        std::string m_backgroudColor;//Backgroud color
        Border m_border;// call the object of the class Border
        std::list<Frame> m_insideFrame;//If necessary
        //list<Image> imageList;
        Text m_text;//Contain the text information
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
        std::string shape(){return m_shape;}
        std::string shadow(){return m_shadow;}
        std::string backgroudColor(){return m_backgroudColor;}

        void addContent(Content c);
        void shape(std::string s){m_shape=s;}
        void shadow(std::string s){m_shadow=s;}
        void backgroudColor(std::string s){ m_backgroudColor=s;}
        void text(Text& t){m_text=t;}
        Text text(){return m_text;}
        Border border(){return m_border;}


};



#endif
