#include <iostream>
#include <page.h>
#include "font.h"
#include "content.h"

using namespace std;

int main(){

//    char c='a';
//    Page p(29.7,20.99,1);
//    p.getFrame().insert(c);

    Content c;
    string k="sdjfaghds<n>fkjaskjgasjha<n>sgfasjkhgasjhgfdasjfhasdf";
    c.getmessage(k);
    int n=c.getlength();
    char a[n];
    char *b=c.getword();
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;
    int *d=c.getlinechange();
    int j=c.getlineamount();
    int e[j];
    for(int i=0;i<j;i++){
        e[i]=d[i];
        cout<<e[i]<<endl;
    }
    return 0;
}
