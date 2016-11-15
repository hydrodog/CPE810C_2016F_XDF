#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
int main() {
    ifstream in("H:\\810C XDF EPUB\\2478944\\content2478944_41743263.html");
    if(!in)
    {
        cout<<"open file err";
    }
    char buf[999999];//it must be long enough
    string src = "";
    while(!in.eof())
    {
        in.getline(buf,sizeof(buf));
        if(strlen(buf) == 0)
        {
            continue;
        }
        src+=buf;
        //cout << src<<endl;
    }

//It can be written in a text file
    ofstream out("H:\\810C XDF EPUB\\Xepub\\text\\test.txt");
    if(!out)
    {
        cout<<"open error"<<endl;
        system("pause");
        return 0;
    }
    in.close();
    int pos2 = 0;
    while(true)
    {
        int pos1 = src.find("body");//head of body
        if(pos1<0)
            break;
        pos2 = src.find("/body",pos1+5);//tail of body
        if (pos2<0)
            break;
        string sub = src.substr(pos1+5,pos2-pos1-6);//text of body
        src.erase(src.begin()+pos1,src.begin()+pos2+1);
            out<<sub<<endl;
    }
    system("pause");
    return 0;
}
