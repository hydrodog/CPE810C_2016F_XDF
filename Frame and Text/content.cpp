#include <content.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
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
    for(int i=0;i<256;i++) {
        m.insert(pair<char,int>(a[i],i));
    }
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
    while(1) {
        posA=b.find("language",posA+1);
        if(posA==-1)break;
    }
    while(1) {
        posB=b.find("color",posB+1);
        if(posB==-1)break;
    }
    char c[20];
    for(int i=posA+8;i<posB;i++){
        c[i-posA]=a[i];
    }
    language=c;
    posA=posB;
    while(1) {
        posB=b.find("font",posB+1);
        if(posB==-1)break;
    }
<<<<<<< HEAD:Frame and Text/content.cpp
    for(int i=posA;i<posB;i++) {
=======
    for(int i=posA+5;i<posB;i++){
>>>>>>> f758dc704c60c6af914421aaf0e5bb1400146611:Frame and Text/importmessage.cpp
        c[i-posA]=a[i];
    }
    sscanf(c,"%d",&color);
    posA=posB;
    while(1) {
        posB=b.find("size",posB+1);
        if(posB==-1)break;
    }
<<<<<<< HEAD:Frame and Text/content.cpp
    for(int i=posA;i<posB;i++) {
=======
    for(int i=posA+4;i<posB;i++){
>>>>>>> f758dc704c60c6af914421aaf0e5bb1400146611:Frame and Text/importmessage.cpp
        c[i-posA]=a[i];
    }
    font=c;
    posA=posB;
    while(1) {
        posB=b.find("bold",posB+1);
        if(posB==-1)break;
    }
<<<<<<< HEAD:Frame and Text/content.cpp
    for(int i=posA;i<posB;i++) {
=======
    for(int i=posA+4;i<posB;i++){
>>>>>>> f758dc704c60c6af914421aaf0e5bb1400146611:Frame and Text/importmessage.cpp
        c[i-posA]=a[i];
    }
    sscanf(c,"%lf",&size);
    posA=posB;
    while(1) {
        posB=b.find("italic",posB+1);
        if(posB==-1)break;
    }
<<<<<<< HEAD:Frame and Text/content.cpp
    for(int i=posA;i<posB;i++) {
=======
    for(int i=posA+4;i<posB;i++){
>>>>>>> f758dc704c60c6af914421aaf0e5bb1400146611:Frame and Text/importmessage.cpp
        c[i-posA]=a[i];
    }
    sscanf(c,"%d",&bold);
    posA=posB;
    while(1) {
        posB=b.find("underline",posB+1);
        if(posB==-1)break;
    }
<<<<<<< HEAD:Frame and Text/content.cpp
    for(int i=posA;i<posB;i++) {
=======
    for(int i=posA+6;i<posB;i++){
>>>>>>> f758dc704c60c6af914421aaf0e5bb1400146611:Frame and Text/importmessage.cpp
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
    while(1) {
        posB=b.find("end",posB+1);
        if(posB==-1)break;
    }
<<<<<<< HEAD:Frame and Text/content.cpp
    for(int i=posA;i<posB;i++) {
=======
    for(int i=posA+9;i<posB;i++){
>>>>>>> f758dc704c60c6af914421aaf0e5bb1400146611:Frame and Text/importmessage.cpp
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
void Content::exportContent() {
    for(It it = m.begin(); it != m.end(); it++) {
        cout << it->first << " "<< it->second << endl; 
    }
}
void Content::contentFont() {
    
}
