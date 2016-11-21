#include "text.h"
#include <iostream>
Text::Text():linespace(1.0)
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


void Text::setLineSpace(double ls){
    linespace=ls;
}

double Text::getLineSpace(){
    return linespace;
}

void Text::addTextLine(TextLine& tl){
    this->textLineList.push_back(tl);
    std::cout<<"TextLineList'length after set "<<textLineList.size()<<'\n';
    this->len++;
}

void Text::addContent(Content c){
    contentList.push_back(c);
}


std::list<TextLine> Text::getTextLineList() const{
    std::cout<<"TextLineList'length when get "<<textLineList.size()<<'\n';
    return textLineList;
}


std::list<Content> Text::getContentList() const{
    return contentList;
}
