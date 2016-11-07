#ifndef FRAME_H__
#define FRAME_H__
#include "border.h"
#include "text.h"
#include "characterstyle.h"
#include <string>
#include <list>


class Frame{
    //This class represent a rectangle area to fill in all the Text or Image
    private:
        Border border;
        bool LeftToRight,horizontal;
        std::list<Frame> insideFrame;//If necessary  //TODO: choose better name:
        //list<Image> imageList;
        Text text;//Not sure make it a list or not
        double width,height;
    //When change the border, need to update the width and height at the same time
    public:
        Frame(double height,double width,bool LtoR,bool horizontal);


        void clear();//Reset all information to defalut value
        void insert(std::string s, CharacterStyle cs, bool withLink);//insert a string with a link or not
        void insert(char c,   CharacterStyle cs);//insert a character with certain style
        void insertSpace(); // insert a space
        void insertReturn();// insert return
};



#endif
