#include "text.h"
#include <iostream>
using namespace std;
Text::Text(){}

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
        m_textcontent[j].getmessage(lis);
        tem.erase(tem.begin(),tem.begin()+pos+13);
        j++;
    }
}
void Text::getallfont(const string v){
    string tem=v;
    string lis=NULL;
    int j=0;
    int pos=0;
    while(1){
        if(pos==-1)break;
        pos=tem.find("<stylechange>");
        for(int i=0;i<pos;i++){
            lis[i]=tem[i];
        }
        m_textcontent[j].getfont(lis);
        tem.erase(tem.begin(),tem.begin()+pos+13);
        j++;
    }
}
void Text::insertcontent(){
    for(int i=0;i<n;i++){
        m_contentList.push_front(m_textcontent[i]);
    }
}


void Text::insertString(const char *s){
    if(m_textLineList.empty()){
        TextLine newline;
        newline.insertString(s);
        m_textLineList.push_back(newline);
    }
    else{//TODO: should consider the situation that line may full
        m_textLineList.back().insertString(s);
    }
}//insert a string
void Text::insertChar(char c){
    if(m_textLineList.empty()){
        TextLine newline;
        newline.insertChar(c);
        m_textLineList.push_back(newline);
    }
    else{
        m_textLineList.back().insertChar(c);
    }
}//inset a character

void Text::insertReturn(){
    TextLine newline;
    m_textLineList.push_back(newline);
}//insert return


void Text::addTextLine(TextLine& tl){
    this->m_textLineList.push_back(tl);
    std::cout<<"TextLineList'length after set "<<m_textLineList.size()<<'\n';
    this->m_len++;
}

void Text::addContent(Content c){
    m_contentList.push_back(c);
}

Content Text::getContent(int i){
    return m_textcontent[i];
}
int Text::getnumber(){
    return n;
}
