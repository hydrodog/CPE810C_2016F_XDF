#include "textline.h"
#include <QString>
#include <QFontMetrics>

TextLine::TextLine():lineStyle("LeftAlign")
{

}

void TextLine::insert(char *s){
    while(*s != 0){
        lineContent.push_back(*s++);
    }
}//insert a string with same style
void TextLine::insert(char c){
    lineContent.push_back(c);
}//inset a character

void TextLine::deleteCharacter(int i){

}//Delete Character at index i

void TextLine::setlineStyle(char* str){
    strcpy(lineStyle,str);
}
