#include "text.h"
#include "myfont.h"
#include <iostream>
Text::Text():linespace(1.0),defalutFont()
{}
void Text::insertString(const char *s){
    if(textLineList.empty()){
        TextLine newline;
        newline.insertString(s);
        textLineList.push_back(newline);
    }
    else{//TODO: should consider the situation that line may full
        textLineList.back().insertString(s);
    }
}//insert a string
void Text::insertChar(char c){
    if(textLineList.empty()){
        TextLine newline;
        newline.insertChar(c);
        textLineList.push_back(newline);
    }
    else{
        textLineList.back().insertChar(c);
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
    this->textLineList.push_back(tl);
    std::cout<<"TextLineList'length after set "<<textLineList.size()<<'\n';
    this->len++;
}

void Text::addContent(Content c){
    contentList=c;
}


std::list<TextLine> Text::getTextLineList() const{
    std::cout<<"TextLineList'length when get "<<textLineList.size()<<'\n';
    return textLineList;
}


Content Text::getContentList() const{
    return contentList;
}
