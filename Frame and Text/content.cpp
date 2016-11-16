#include "content.h"
#include <stdlib.h>
#include <map>
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void Content::getmessage() {
    ifstream in("filename");
    char a[256];
    try {
       in.is_open();
    }
    catch(double) {
        cout<<"Opening file error!"<<endl;
    }
    while(!in.eof()) {
        in.getline(a,256);
    }
    r.readContent(a);
}
void Content::getfont() {
    string language;
    int color;
    string font;
    double  size;
    int bold;
    bool italic;
    bool underline;
    ifstream in("fontname");
    char a[256];
    try {
       in.is_open();
    }
    catch(double) {
        cout<<"Opening file error!"<<endl;
    }
    while(!in.eof()) {
        in.getline(a,256);
    }
    string b=a;
    int posA=1;
    int posB=1;
    posA=b.find("language");
    posB=b.find("color");
    char c[20];
    for(int i=posA+8;i<posB;i++){
        c[i-posA]=a[i];
    }
    language=c;
    posA=posB;
    posB=b.find("font");
    for(int i=posA+5;i<posB;i++){
        c[i-posA]=a[i];
    }
    sscanf(c,"%d",&color);
    posA=posB;
    posB=b.find("size");
    for(int i=posA+4;i<posB;i++){
        c[i-posA]=a[i];
    }
    font=c;
    posA=posB;
    posB=b.find("bold");
    for(int i=posA+4;i<posB;i++){
        c[i-posA]=a[i];
    }
    sscanf(c,"%lf",&size);
    posA=posB;
    posB=b.find("italic");
    for(int i=posA+4;i<posB;i++){
        c[i-posA]=a[i];
    }
    sscanf(c,"%d",&bold);
    posA=posB;
    posB=b.find("underline");
    for(int i=posA+6;i<posB;i++){
        c[i-posA]=a[i];
    }
    int x;
    sscanf(c,"%d",&x);
    if(x==1) {
        italic=true;
    }else{
        italic=false;
    }
    posA=posB;
    posB=b.find("end");
    for(int i=posA+9;i<posB;i++){
        c[i-posA]=a[i];
    }
    sscanf(c,"%d",&x);
    if(x==1) {
        underline=true;
    }else {
        underline=false;
    }
    t.setfont(language,color,font,size,bold,italic,underline);
}

list<char> Content::exportContent() {
    list<char> lstTemp;
    map<int,char>:: iterator itTemp = m.begin();
    for(;itTemp != m.end();itTemp++) {
        lstTemp.push_back(itTemp->second);
    }
    return lstTemp;
}
myFont Content::contentFont() {
    return t;
}
