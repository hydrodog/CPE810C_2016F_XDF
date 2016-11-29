#include "textline.h"
#include <QString>
#include <QFontMetrics>


int PublicLinecode=1;
TextLine::TextLine()
{
    m_linecode=PublicLinecode;
    PublicLinecode++;
}
void TextLine::insertString(const char *s){
    while(*s != 0){
        m_lineContent.push_back(*s++);
    }
}//insert a string with same style
void TextLine::insertChar(const char c){
    m_lineContent.push_back(c);
}//inset a character



