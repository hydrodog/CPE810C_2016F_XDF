#include "text.h"
#include <iostream>
using namespace std;
Text::Text(){}

void Text::readInText(const wstring w,const string v){
    wstring tem1=w;
    Content temstore;
    int pos=0;
    wstring lis;
    int j=0;
    string temp=v;
    string lisf;
    int posf=0;
    int posfont;
    int first[11]={0};
    first[0]=0;
    int firstfont[11]={0};
    firstfont[0]=0;
    int fontlength=temp.length();
    int length=w.length();
    string temfont;
    wstring tem;
    for(int e=1;e<10;e++){                                  //The string is too long,so we have to divide it into a few parts,othervise the program may crash.
        if(e<9){
            tem=tem1.substr(e*length/10,length/10);       //divide into 10 parts,if necessary we can divide it into more parts,just need to change some number in the program.
            pos=tem.find(L"<stylechange>");                 //find the mark "<stylechange>" in case of cutting the mark
            if(pos==-1){first[e]=first[e-1];firstfont[e]=firstfont[e-1];continue;}  //If the string is short,the string can be divided into fewer parts.
            first[e]=(e*length/10)+pos+12;                            //The array "first" can store where the string should be split.
            if(posfont==-1){continue;}else{tem=tem1.substr(first[e-1]+1,first[e]-first[e-1]);}   //cut the string

            temfont=temp.substr(e*fontlength/10,fontlength/10);      //deal with the string of font,same as wstring
            posfont=temfont.find("<stylechange>");
            if(posfont==-1){firstfont[e]=firstfont[e-1];continue;}
            firstfont[e]=(e*fontlength/10)+posfont+12;
            if(posfont==-1){continue;}else{temfont=temp.substr(firstfont[e-1],firstfont[e]-firstfont[e-1]);}
            posf=0;
            pos=0;
        }else{
            int a=tem1.length();
            tem=tem1.substr(first[e-1]+1,length-first[e-1]+1);
            temfont=temp.substr(firstfont[e-1],fontlength-firstfont[e-1]);
            posf=0;
            pos=0;
        }
        while(1){
            if(posf==-1)break;
            posf=temfont.find("<stylechange>");         //find the mark "<stylechange>" to make a new Content object.
            lisf=temfont.substr(0,posf);
            pos=tem.find(L"<stylechange>");
            if(pos==-1)break;
            n++;
            lis=tem.substr(0,pos);
            temstore.readInMessage(lis);
            temstore.readInFont(lisf);
            m_contentList.push_back(temstore);                                    //push here
            tem.erase(tem.begin(),tem.begin()+pos+13);
            temfont.erase(temfont.begin(),temfont.begin()+posf+13);     //erase the mark "<stylechange>"
            j++;
            m_imagepos[m_imagenum]=tem.find(L"<img>")+first[e-1];       //find the image position
            m_imagenum++;
        }
    }
    #if 0
    /*tem=tem1.substr(length*2/3,length/3);
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
    }*/
    #endif
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

int Text::getnumber(){
    return n;
}
int* Text::getimagepos(){
    return m_imagepos;
}
int Text::getimagenum(){
    return m_imagenum;
}
