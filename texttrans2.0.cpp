#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <locale>
#include <wchar.h>
#include <cstdio>

using namespace std;

string getsetting(string cssfile, string settingname);
wstring wopenfile(string path);
string openfile(string path);
string openfile(string path){
    string buf;
    ifstream file;
    file.open(path);
    if(!file){
        cout<<"open file err";
    }
    string src = "";
    while(!file.eof()){
        getline(file,buf);
        if(buf.length() == 0)
        {
            continue;
        }
        src+=buf;
        //cout << src<<endl;
    }
    //cout << src<<endl;
    file.close();
    return src;
}
wstring wopenfile(string path){
    wstring wbuf;
    wifstream wfile;
    wfile.open(path);
    if(!wfile){
        cout<<"open wfile err";
    }
    wstring src = L"";
    while(!wfile.eof()){
        getline(wfile,wbuf);
        if(wbuf.length() == 0)
        {
            continue;
        }
        src+=wbuf;
        //wcout << src<<endl;
    }
    //wcout << src<<endl;
    wfile.close();
    return src;
}

int main() {
    /*setlocale(LC_ALL, "chs");
    ios_base::sync_with_stdio(false); // 缺少的话，wcout wchar_t 会漏掉中文
    wcout.imbue(locale(""));
    wstring u = L"中国";
    wcout << u;*/
    wstring wsrc = wopenfile("H:\\810C XDF EPUB\\2478944\\content2478944_41749293.html");
    wstring body;
    while(true){
        int pos1 = wsrc.find(L"body>");//head of body
        if(pos1<0)
            break;
        int pos2 = wsrc.find(L"/body>",pos1+5);//tail of body
        if (pos2<0)
            break;
        body = wsrc.substr(pos1+5,pos2-pos1-6);//text of body
        wsrc.erase(wsrc.begin()+pos1,wsrc.begin()+pos2+1);
            //wcout<<body<<endl;
    }
    //wcout<<body<<endl;
    string src = openfile("H:\\810C XDF EPUB\\2478944\\content2478944_41749293.html");
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
    string bodysetting = getsetting(csssub,"body")+"0>";
    string h1setting = getsetting(csssub,"h1")+"0>";
    string h2setting = getsetting(csssub,"h2")+"0>";
    string h3setting = getsetting(csssub,"h3")+"0>";
    string h4setting = getsetting(csssub,"h4")+"0>";
    string h5setting = getsetting(csssub,"h5")+"0>";
    string h6setting = getsetting(csssub,"h6")+"0>";
    string divsetting = getsetting(csssub,"div")+"0>";
    string asetting = getsetting(csssub,"a ")+"1>";//lack of href
    //cout << h1setting;
    wstring stylechange = L"(stylechange)";
    wstring bodytrans = stylechange;
    string allsetting = bodysetting;
    for(int i = 0; i < body.size();i++){
        if(body[i]=='<'){
            if(body[i+1]==L'p'){
                if(body[i+2]==L'>'){
                bodytrans += L"\\n";
                }
            }
            if(body[i+1]==L'/'){
                if(body[i+2]==L'b'){
                    if(body[i+3]==L'r'){
                        if(body[i+4]==L'/'){
                            bodytrans += L"\\n";
                            }
                        }
                    }
                }
            if(body[i+1]==L'h'){
                if(body[i+2]==L'1')
                    bodytrans += stylechange;
                allsetting += h1setting;
                if(body[i+2]==L'2')
                    bodytrans += stylechange;
                allsetting += h2setting;
                if(body[i+2]==L'3')
                    bodytrans += stylechange;
                allsetting += h3setting;
                if(body[i+2]==L'4')
                    bodytrans += stylechange;
                allsetting += h4setting;
                if(body[i+2]==L'5')
                    bodytrans += stylechange;
                allsetting += h5setting;
                if(body[i+2]==L'6')
                    bodytrans += stylechange;
                allsetting += h6setting;
            }
            if(body[i+1]==L'd'){
                if(body[i+2]==L'i'){
                    if(body[i+3]==L'v'){
                        bodytrans += stylechange;
                        allsetting += divsetting;
                    }
                }
            }
            if(body[i+1]==L'a'){
                int pos1 = body.find(L"href=",i);
                int pos2 = body.find(L"\"",pos1+6);
                wstring href = body.substr(pos1 + 6,pos2 - pos1 - 6);
                //cout << href;
                bodytrans += L"(" + href + L")";
                allsetting += asetting;
            }
            i = body.find(L'>',i);
        }
        else
            bodytrans += body[i];

    }

    //cout << allsetting;
    system("pause");
    return 0;
}

string getsetting(string csssub, string settingname){
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
