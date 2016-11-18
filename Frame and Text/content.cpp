#include "content.h"
#include <stdlib.h>
#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void Content::getmessage(string a) {
    /*ifstream in("sampletext.txt");
    string words;
    try {
       in.is_open();
    }
    catch(double) {
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
	int k=a.length();
	words=a.c_str();
}
void Content::getfont(string a) {
    string language;
    int color;
    string font;
    double  size;
    int bold;
    bool italic;
    bool underline;
  /*  ifstream in("samplefont.txt");
    string a;
    try {
       in.is_open();
    }
    catch(double) {
        cout<<"Opening file error!"<<endl;
    }
    const int LINE_LENGTH = 10;  //fix in 11/16
    char str[LINE_LENGTH];
    string *k;
    int i=0;
    while( in.getline(str,LINE_LENGTH) ){
    k[i]=str;
    i++;
    if(i>=20)break;
    }                //fix in 11/16 */
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
myFont Content::contentFont() {
    return t;
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
