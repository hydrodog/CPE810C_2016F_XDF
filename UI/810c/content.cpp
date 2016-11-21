#include "content.h"
#include <stdlib.h>
#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Content::Content(){

}

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
    string b=a;
    int j=0;
    int pos;
    while(1){
        pos=b.find("<n>");
        if(pos==-1)break;
        n++;
        //cout<<pos<<endl;
        changelinepos[j]=pos;
        b.erase(pos,3);
        j++;
    }
    k=b.length();
    char c[k];
    for(int i=0;i<k;i++){
        c[i]=b.c_str()[i];
    }
    for(int i=0;i<k;i++){
        words[i]=c[i];
    }
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
}
QFont Content::getContentFont() {
    return font;
}

QColor Content::getContentColor(){
    return color;
}

void Content::setFont(QFont f){
    font=f;
}

void Content::setColor(QColor c){
    color=c;
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

char* Content::getword(){
    char *a=&words[0];
    return a;
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
