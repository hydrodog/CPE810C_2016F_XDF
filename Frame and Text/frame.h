#ifndef FRAME_H__
#define FRAME_H__
#include "border.h"
#include "text.h"
#include "myfont.h"
#include <string>
#include <list>


class Frame{
    //This class represent a rectangle area to fill in all the Text or Image
    private:
        Border border;
        std::list<Frame> insideFrame;//If necessary  //TODO: choose better name:
        //list<Image> imageList;
        Text text;//Not sure make it a list or not
        double width,height;
        double startX,startY;
    //When change the border, need to update the width and height at the same time
    public:
        Frame(double startX,double startY,double height,double width);
        void clear();//Reset all information to defalut value
        void insert(char *s,bool withLink);//insert a string with a link or not
        void insert(char *s);//insert a string with a link or not
        void insert(char  c);//insert a character with certain style
        void insertSpace(); // insert a space
        void insertReturn();// insert return


        void setText(Text& t);
        Text getText();
};



#endif
