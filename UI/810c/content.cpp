#include "content.h"
#include <stdlib.h>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include<QFont>

using namespace std;



void Content::getmessage(wstring a) {
    /*ifstream in("sampletext.txt");
    string words;
    try {
       in.is_open();
    }
    catch(int) {
        cout<<"Opening file error!"<<endl;
    }
    const int LINE_LENGTH = 10;  //fix in 11/18
    char str[LINE_LENGTH];
    string *k;
    int i=0;
    while( in.getline(str,LINE_LENGTH) ){
    k[i]=str;
    i++;
    if(i>=20)break;
    }                  //fix in 11/18
    cout << words << endl;          */
    wstring b=a;
    int j=0;
    int pos;
    while(1){
        pos=b.find(L"<n>");
        if(pos==-1)break;
        n++;
        //cout<<pos<<endl;
        changelinepos[j]=pos;
        b.erase(pos,3);
        j++;
    }
    k=b.length();
    m_str=b;
}
void Content::getfont(string a) {
    string language;
    string colortem;
    string fonttem;
    double  size;
    bool bold;
    bool italic;
    bool underline;

    string b=a;
    int posA=1;
    int posB=1;
    posA=b.find("language");
    posB=b.find("color");
    string c;

    language=b.substr(posA+8,posB-posA-8);
    posA=posB;
    posB=b.find("font");

    colortem=b.substr(posA+5,posB-posA-5);
    posA=posB;
    posB=b.find("size");

    fonttem=b.substr(posA+4,posB-posA-4);
    posA=posB;
    posB=b.find("bold");
    c=b.substr(posA+4,posB-posA-4);
    const char *temc=c.c_str();
    sscanf(temc,"%lf",&size);
    posA=posB;
    posB=b.find("italic");

    c=b.substr(posA+4,posB-posA-4);
    const char *temc1=c.c_str();
    int x;
    sscanf(temc1,"%d",&x);
    if(x==1) {
        bold=true;
    }else{
        bold=false;
    }
    posA=posB;
    posB=b.find("underline");

    c=b.substr(posA+6,posB-posA-6);
    const char *temc2=c.c_str();
    sscanf(temc2,"%d",&x);
    if(x==1) {
        italic=true;
    }else{
        italic=false;
    }
    posA=posB;
    posB=b.find("end");

    c=b.substr(posA+9,posB-posA-9);
    const char *temc3=c.c_str();
    sscanf(temc3,"%d",&x);
    if(x==1) {
        underline=true;
    }else {
        underline=false;
    }
    QString fonttem1= QString::fromStdString(fonttem);
    QString colortem1= QString::fromStdString(colortem);
    m_font.setFamily(fonttem1);
    m_font.setPixelSize(size);
    m_font.setBold(bold);
    m_font.setItalic(italic);
    m_font.setUnderline(underline);
    m_color.setNamedColor(colortem1);
}

void Content::getalignment(int *n,int *m){
    for(int i=0;i<256;i++){
        if(n[i]==NULL||m[i]==NULL)break;
        if(m[i]==0){
            alignment.insert(pair<int,string>(n[i],"left"));
        }
        if(m[i]==1){
            alignment.insert(pair<int,string>(n[i],"mid"));
        }
        if(m[i]==2){
            alignment.insert(pair<int,string>(n[i],"right"));
        }
    }
}

map<int,string> Content::exportalignment(){
    return alignment;
}

wstring Content::getword(){
    return words;
}
int Content::getlength(){
    return k;
}
int* Content::getlinechange(){
    int *a=&changelinepos[0];
    return a;
}
int Content::getlineamount(){
    int m=n;
    return m;
}
QString Content::getQString(){
    QString str1= QString::fromStdWString(words);
    return str1;
}