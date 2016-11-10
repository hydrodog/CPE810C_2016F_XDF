#ifndef TEXT_H__
#define TEXT_H__
#include "characterstyle.h"
#include "textline.h"
#include <string>
#include <list>

class Text{
/*This class represents the words and text in the frame
*Contains the width and height of this text
*If the height of all lines is over than the height of frame, create a new frame or page
*/

private:
    std::list<TextLine> linelist;// A List of line in the text
    double linespace;
    double width,height;
public:
    Text();


    void insert(std::string , CharacterStyle);//insert a string
    void insert(char c, CharacterStyle);//inset a character
    void insertSpace(); // insert a space
    void insertReturn();//insert return
    void deleteLine(int i);//Delete line at index i

};

#endif // TEXT_H
