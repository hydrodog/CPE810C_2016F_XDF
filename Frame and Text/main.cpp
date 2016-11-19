#include <iostream>
#include <page.h>
#include "font.h"
#include "content.h"
#include<locale>
using namespace std;

int main(){

//    char c='a';
//    Page p(29.7,20.99,1);
//    p.getFrame().insert(c);
    Content c;
    wstring k=L"sdjfagh中文测试ds<n>fkjaskjgas测试中文jha<n>sgfasjkhgasjhgfdasjfhasdf";
    c.getmessage(k);
    int n=c.getlength();
    wchar_t a[n];
    wchar_t *b=c.getword();
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
    string f;
    Wchar_tToString(f,a);
    cout<<f;
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
