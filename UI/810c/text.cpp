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
    int posfont;

    int length=w.length();
    wstring tem=tem1.substr(length/3,length/3);
    pos=tem.find(L"<stylechange>");
    int first=(length/3)+pos+12;
    if(pos==-1){tem=tem1;}else{tem=tem1.substr(0,first);}

    int fontlength=temp.length();
    string temfont=temp.substr(fontlength/3,fontlength/3);
    posfont=temfont.find("<stylechange>");
    int firstfont=(fontlength/3)+posfont+12;
    if(posfont==-1){temfont=temp;}else{temfont=temp.substr(0,firstfont);}
    while(1){
        if(posf==-1)break;
        posf=temfont.find("<stylechange>");
        lisf=temfont.substr(0,posf);
        pos=tem.find(L"<stylechange>");
        if(pos==-1)break;
        n++;
        lis=tem.substr(0,pos);
        temstore.getmessage(lis);
        temstore.getfont(lisf);
        m_contentList.push_back(temstore);                                    //push here
        tem.erase(tem.begin(),tem.begin()+pos+13);
        temfont.erase(temfont.begin(),temfont.begin()+posf+13);
        j++;       
    }
    tem=tem1.substr(length*2/3,length/3);
    pos=tem.find(L"<stylechange>");
    int second=(length*2/3)+pos+12;
    if(pos==-1){tem=tem1;}else{tem=tem1.substr(first+1,second-first);}

    temfont=temp.substr(fontlength*2/3,fontlength/3);
    posfont=temfont.find("<stylechange>");
    int secondfont=(fontlength*2/3)+posfont+12;
    if(posfont==-1){temfont=temp;}else{temfont=temp.substr(firstfont+1,secondfont-firstfont);}
    while(1){

        posf=temfont.find("<stylechange>");
        if(posf==-1)break;
        lisf=temfont.substr(0,posf);
        pos=tem.find(L"<stylechange>");
        if(pos==-1)break;
        n++;
        lis=tem.substr(0,pos);
        temstore.getmessage(lis);
        temstore.getfont(lisf);
        m_contentList.push_back(temstore);                                    //push here
        tem.erase(tem.begin(),tem.begin()+pos+13);
        temfont.erase(temfont.begin(),temfont.begin()+posf+13);
        j++;
    }
    tem=tem1.substr(second+1,length-second+1);
    temfont=temp.substr(secondfont+1,fontlength-secondfont+1);
    while(1){

        posf=temfont.find("<stylechange>");
        if(posf==-1)break;
        lisf=temfont.substr(0,posf);
        pos=tem.find(L"<stylechange>");
        if(pos==-1)break;
        n++;
        lis=tem.substr(0,pos);
        temstore.getmessage(lis);
        temstore.getfont(lisf);
        m_contentList.push_back(temstore);                                    //push here
        tem.erase(tem.begin(),tem.begin()+pos+13);
        temfont.erase(temfont.begin(),temfont.begin()+posf+13);
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

void Text::addContent(Content c){
    m_contentList.push_back(c);
}

//Content Text::getContent(int i){
    //return m_textcontent[i];
//}
int Text::getnumber(){
    return n;
}
