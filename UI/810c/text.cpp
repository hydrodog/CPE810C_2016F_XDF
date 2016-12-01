#include "text.h"
#include <iostream>
using namespace std;
Text::Text(){}

void Text::getText(const wstring w,const string v){
    wstring tem1=w;
    Content temstore;
    int pos=0;
    wstring lis;
    int j=0;
    string temp=v;
    string lisf;
    int posf=0;
    int length=w.length();
    wstring tem=tem1.substr(length/3,length/3);
    pos=tem.find(L"<stylechange>");
    int first=(length/3)+pos+12;
    if(pos==-1){tem=tem1;}else{tem=tem1.substr(0,first);}

    while(1){
        if(posf==-1)break;
        posf=temp.find("<stylechange>");
        lisf=temp.substr(0,posf);
        pos=tem.find(L"<stylechange>");
        if(pos==-1)break;
        n++;
        lis=tem.substr(0,pos);
        temstore.getmessage(lis);
        temstore.getfont(lisf);
        m_contentList.push_back(temstore);                                    //push here
        tem.erase(tem.begin(),tem.begin()+pos+13);
        temp.erase(temp.begin(),temp.begin()+posf+13);
        j++;       
    }
    tem=tem1.substr(length*2/3,length/3);
    pos=tem.find(L"<stylechange>");
    int second=(length*2/3)+pos+12;
    if(pos==-1){tem=tem1;}else{tem=tem1.substr(first+1,second-first);}
    while(1){
        if(posf==-1)break;
        posf=temp.find("<stylechange>");
        lisf=temp.substr(0,posf);
        pos=tem.find(L"<stylechange>");
        if(pos==-1)break;
        n++;
        lis=tem.substr(0,pos);
        temstore.getmessage(lis);
        temstore.getfont(lisf);
        m_contentList.push_back(temstore);                                    //push here
        tem.erase(tem.begin(),tem.begin()+pos+13);
        temp.erase(temp.begin(),temp.begin()+posf+13);
        j++;
    }
    tem=tem1.substr(second+1,length-second);
    while(1){
        if(posf==-1)break;
        posf=temp.find("<stylechange>");
        lisf=temp.substr(0,posf);
        pos=tem.find(L"<stylechange>");
        if(pos==-1)break;
        n++;
        lis=tem.substr(0,pos);
        temstore.getmessage(lis);
        temstore.getfont(lisf);
        m_contentList.push_back(temstore);                                    //push here
        tem.erase(tem.begin(),tem.begin()+pos+13);
        temp.erase(temp.begin(),temp.begin()+posf+13);
        j++;
    }
}
#if 0
void Text::getallfont(const string v){
    string temp=v;
    string lisf;
    int j=0;
    int posf=0;
    while(1){
        if(posf==-1)break;
        posf=temp.find("<stylechange>");
        for(int i=0;i<posf;i++){
            lisf[i]=temp[i];
        }
        m_textcontent[j].getfont(lisf);
        temp.erase(temp.begin(),temp.begin()+posf+13);
        j++;
    }
}

void Text::insertcontent(){
    for(int i=0;i<n;i++){
        m_contentList.push_front(m_textcontent[i]);
    }
}
#endif

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

//Content Text::getContent(int i){
    //return m_textcontent[i];
//}
int Text::getnumber(){
    return n;
}
