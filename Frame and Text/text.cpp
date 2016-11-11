#include "text.h"
#include "myfont.h"
Text::Text():linespace(1.0)
{}
void Text::insert(char *s){
    if(textLineList.empty()){
        TextLine newline;
        newline.insert(s);
        textLineList.push_back(newline);
    }
    else{//TODO: should consider the situation that line may full
        textLineList.back().insert(s);
    }
}//insert a string
void Text::insert(char c){
    if(textLineList.empty()){
        TextLine newline;
        newline.insert(c);
        textLineList.push_back(newline);
    }
    else{
        textLineList.back().insert(c);
    }
}//inset a character

void Text::insertReturn(){
    TextLine newline;
    textLineList.push_back(newline);
}//insert return
void Text::deleteLine(int i){

}//Delete line at index i



void Text::setLineSpace(double ls){
    linespace=ls;
}

double Text::getLineSpace(){
    return linespace;
}

myFont Text::getDefalutFont(){
    return defalutFont;
}

void Text::setDefalutFont(myFont & myfont){
    defalutFont=myfont;
}

void Text::addTextLine(TextLine& tl){
    textLineList.push_back(tl);
}
