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
    string k="sdjfaghdsfkjaskjgasjhasgfasjkhgasjhgfdasjfhasdf";
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
    return 0;
}
