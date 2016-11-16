#include "textline.h"
#include <QString>
#include <QFontMetrics>


int PublicLinecode=1;
TextLine::TextLine():lineStyle("LeftAlign")
{
    linecode=PublicLinecode;
    PublicLinecode++;
}
void TextLine::insertString(const char *s){
    while(*s != 0){
        lineContent.push_back(*s++);
    }
}//insert a string with same style
void TextLine::insertChar(const char c){
    lineContent.push_back(c);
}//inset a character

void TextLine::deleteCharacter(int i){

}//Delete Character at index i

void TextLine::setlineStyle(char* str){
    lineStyle=str;
}

