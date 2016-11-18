#include "myfont.h"

myFont::myFont(){

}


QFont myFont::getFont(){
     return font;
}
QColor myFont::getColor(){
    return c;
}

void myFont::setFont(){
font.setFamily("宋体");

font.setPixelSize(50);

font.setBold(true);

font.setItalic(true);

font.setPointSize(20);

font.setStyle(QFont::StyleItalic);

font.setWeight(QFont::Light);

font.setOverline(true);

font.setUnderline(true);

font.setStrikeOut(true);


font.setLetterSpacing(QFont::PercentageSpacing,300);

font.setLetterSpacing(QFont::AbsoluteSpacing,20);

font.setCapitalization(QFont::Capitalize);
}
