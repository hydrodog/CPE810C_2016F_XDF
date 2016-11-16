#include "read.h"
#include <stdlib.h>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

void Read::readContent(char (&a)[256]) {
    string b=a;
    int pos;
    for(int i=0;i<256;i++) {
        pos=b.find("<linechange>");
        if(pos==-1){break;}
        lc.insert(pair<int,string>(pos-1,"linechange"));
        b.erase(pos,12);
    }
    for(int i=0;i<256;i++) {
        pos=b.find("<parachange>");
        if(pos==-1){break;}
        pc.insert(pair<int,string>(pos-1,"parachange"));
        b.erase(pos,12);
    }
    for(int i=0;i<256;i++) {
        if(b[i])break;
        m.insert(pair<int,char>(i,b[i]));
    }
}
