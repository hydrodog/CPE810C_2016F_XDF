#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
char buf[999999];//it must be long enough
string getbodysetting(string cssfile, string settingname);
string openfile(string path);
string openfile(string path){
    ifstream file(path);
    if(!file){
        cout<<"open file err";
    }
    string src = "";
    while(!file.eof()){
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
    string body;
    while(true){
        int pos1 = src.find("body>");//head of body
        if(pos1<0)
            break;
        int pos2 = src.find("/body>",pos1+5);//tail of body
        if (pos2<0)
            break;
        body = src.substr(pos1+5,pos2-pos1-6);//text of body
        src.erase(src.begin()+pos1,src.begin()+pos2+1);
            //cout<<body<<endl;
    }
    //cout<<body<<endl;
    string sub;
    while(true){
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
    //cout << csssub<<endl;
    string bodysetting = getbodysetting(csssub,"body")+"0>";
    string h1setting = getbodysetting(csssub,"h1")+"0>";
    string h2setting = getbodysetting(csssub,"h2")+"0>";
    string h3setting = getbodysetting(csssub,"h3")+"0>";
    string h4setting = getbodysetting(csssub,"h4")+"0>";
    string h5setting = getbodysetting(csssub,"h5")+"0>";
    string asetting = getbodysetting(csssub,"a ")+"1";//lack of href
    //cout << h1setting;
    string bodytrans = "";
    for(int i = 0; i < body.size();i++){
        if(body[i]=='<'){
            if(body[i+1]=='p'){
                if(body[i+2]=='>'){
                bodytrans += "\\n";
                i += 2;
                }
            }
        if(body[i+1]=='/'){
            if(body[i+2]=='b'){
                if(body[i+3]=='r'){
                    if(body[i+4]=='/'){
                        bodytrans += "\\n";
                        i += 4;
                    }
                }
            }
            i = body.find('>',i)
        }


    }
    }
    //cout << bodytrans;
    system("pause");
    return 0;
}

string getbodysetting(string csssub, string settingname){
    string buf1;
    string fullsetting;
    string setting = "<color";
    if(csssub.find(settingname)!=-1){
            int pos1 = csssub.find("{",csssub.find(settingname));
            int pos2 = csssub.find("}",pos1 + 1);
            fullsetting = csssub.substr(pos1+1,pos2-pos1-1);
            //cout << fullsetting;
        }
        if(fullsetting.find("color")!=-1){
            int pos1 = fullsetting.find(":",fullsetting.find("color"));
            int pos2 = fullsetting.find(";",pos1+1);
            buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
            string buf2 = "";
            for(int i = 0;i<buf1.size();i++){
                if(buf1[i]!=' ')
                buf2 += buf1[i];
            }
            setting +=buf2 +" font";
        }
        else{
            setting += "default font";
        }
        if(fullsetting.find("font-family")!=-1){
            int pos1 = fullsetting.find(":",fullsetting.find("font-family"));
            int pos2 = fullsetting.find(";",pos1+1);
            buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
            string buf2 = "";
            for(int i = 0;i<buf1.size();i++){
                if(buf1[i]!=' ')
                buf2 += buf1[i];
            }
            setting +=buf2 +" size";
        }
        else{
            setting += "default size";
        }if(fullsetting.find("font-size")!=-1){
            int pos1 = fullsetting.find(":",fullsetting.find("font-size"));
            int pos2 = fullsetting.find(";",pos1+1);
            buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
            string buf2 = "";
            for(int i = 0;i<buf1.size();i++){
                if(buf1[i]!=' ')
                buf2 += buf1[i];
            }
            setting +=buf2 +" bold";
        }
        else{
            setting += "default bold";
        }if(fullsetting.find("bold")!=-1){
            setting += "1 italic";
        }
        else{
            setting += "0 italic";
        }if(fullsetting.find("italic")!=-1){
            setting += "1 underline";
        }
        else{
            setting += "0 underline";
        }if(fullsetting.find("underline")!=-1){
            setting += "1 align";
        }
        else{
            setting += "0 align";
        }if(fullsetting.find("align")!=-1){
            int pos1 = fullsetting.find(":",fullsetting.find("align"));
            int pos2 = fullsetting.find(";",pos1+1);
            buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
            string buf2 = "";
            for(int i = 0;i<buf1.size();i++){
                if(buf1[i]!=' ')
                buf2 += buf1[i];
            }
            setting +=buf2 +" url";
        }
        else{
            setting += "default url";
        }
    return setting;//lack of ">"
}
