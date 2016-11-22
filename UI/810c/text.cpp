#include "text.h"
#include <iostream>
using namespace std;
void Text::getText(const wstring w){
    wstring tem=w;
    wstring lis=NULL;
    int j=0;
    int pos=0;
    while(1){
        if(pos==-1)break;
        n++;
        pos=tem.find(L"<stylechange>");
        for(int i=0;i<pos;i++){
            lis[i]=tem[i];
        }
        textcontent[j].getmessage(lis);
        tem.erase(tem.begin(),tem.begin()+pos+13);
        j++;
    }
}

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
