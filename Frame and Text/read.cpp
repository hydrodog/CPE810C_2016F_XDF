#include "read.h"
#include <stdlib.h>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

void Read::readContent() {
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
    string b=a;
    int pos;
    for(int i=0;i<256;i++) {
        pos=b.find("<linechange>");
        lc.insert(pair<int,string>(pos-1,"linechange"));
        b.erase(pos,12);
    }
    for(int i=0;i<256;i++) {
        pos=b.find("<parachange>");
        pc.insert(pair<int,string>(pos-1,"parachange"));
        b.erase(pos,12);
    }
    for(int i=0;i<256;i++) {
        if(b[i])break;
        m.insert(pair<int,char>(i,b[i]));
    }
}
