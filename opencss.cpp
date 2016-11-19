#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
char buf[999999];//it must be long enough
string openfile(string path){
    ifstream file(path);
    if(!file)
    {
        cout<<"open file err";
    }

    string src = "";
    while(!file.eof())
    {
        file.getline(buf,sizeof(buf));
        if(strlen(buf) == 0)
        {
            continue;
        }
        src+=buf;
        //cout << src<<endl;
    }
    //cout << src<<endl;
    return src;
}

int main() {
    string src = openfile("H:\\810C XDF EPUB\\2478944\\content2478944_41749293.html");
    string sub;
    while(true)
    {
        int pos1 = src.find("link");//find css head
        if(pos1<0)
            break;
        int  pos2 = src.find("href=\"",pos1+4);//head of css
        if (pos2<0)
            break;
        int pos3 = src.find(".css",pos2+6);  // tail of css
        sub = src.substr(pos2+6,pos3-pos2-2);//text of body
        src.erase(src.begin()+pos1,src.begin()+pos2+1);
            //cout<<sub<<endl;
    }
    string csspath = "H:\\810C XDF EPUB\\2478944\\"+sub;
    string csssub =openfile(csspath);
    cout << csssub<<endl;

    system("pause");
    return 0;
}
