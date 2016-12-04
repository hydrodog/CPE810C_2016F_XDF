#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

wstring buf;//it must be long enough
wstring getsetting(wstring cssfile, wstring settingname);
wstring openfile(string path);
wstring openfile(string path){
    wifstream file;
    file.open(path);
    if(!file){
        cout<<"open file err";
    }
    wstring src = L"";
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
    return src;
}

int main() {
    wstring src = openfile("H:\\810C XDF EPUB\\2478944\\content2478944_41749293.html");
    wstring body;
    while(true){
        int pos1 = src.find(L"body>");//head of body
        if(pos1<0)
            break;
        int pos2 = src.find(L"/body>",pos1+5);//tail of body
        if (pos2<0)
            break;
        body = src.substr(pos1+5,pos2-pos1-6);//text of body
        src.erase(src.begin()+pos1,src.begin()+pos2+1);
            //cout<<body<<endl;
    }
    //cout<<body<<endl;
    wstring sub;
    while(true){
        int pos1 = src.find(L"link");//find css head
        if(pos1<0)
            break;
        int  pos2 = src.find(L"href=\"",pos1+4);//head of css
        if (pos2<0)
            break;
        int pos3 = src.find(L".css",pos2+6);  // tail of css
        sub = src.substr(pos2+6,pos3-pos2-2);//text of body
        src.erase(src.begin()+pos1,src.begin()+pos2+1);
            //cout<<sub<<endl;
    }
    wstring csspath = L"H:\\810C XDF EPUB\\2478944\\"+sub;
    wstring csssub =openfile(csspath);
    //cout << csssub<<endl;
    wstring bodysetting = getsetting(csssub,L"body")+L"0>";
    wstring h1setting = getsetting(csssub,L"h1")+L"0>";
    wstring h2setting = getsetting(csssub,L"h2")+L"0>";
    wstring h3setting = getsetting(csssub,L"h3")+L"0>";
    wstring h4setting = getsetting(csssub,L"h4")+L"0>";
    wstring h5setting = getsetting(csssub,L"h5")+L"0>";
    wstring h6setting = getsetting(csssub,L"h6")+L"0>";
    wstring divsetting = getsetting(csssub,L"div")+L"0>";
    wstring asetting = getsetting(csssub,L"a ")+L"1";//lack of href
    //cout << h1setting;
    wstring bodytrans = bodysetting;
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
                    bodytrans += h1setting;
                if(body[i+2]==L'2')
                    bodytrans += h2setting;
                if(body[i+2]==L'3')
                    bodytrans += h3setting;
                if(body[i+2]==L'4')
                    bodytrans += h4setting;
                if(body[i+2]==L'5')
                    bodytrans += h5setting;
                if(body[i+2]==L'6')
                    bodytrans += h6setting;
            }
            if(body[i+1]==L'd'){
                if(body[i+2]==L'i'){
                    if(body[i+3]==L'v'){
                        bodytrans += divsetting;
                    }
                }
            }
            if(body[i+1]==L'a'){
                int pos1 = body.find(L"href=",i);
                int pos2 = body.find(L"\"",pos1+6);
                wstring href = body.substr(pos1 + 6,pos2 - pos1 - 6);
                //cout << href;
                bodytrans += asetting + href + L">";
            }
            i = body.find(L'>',i);
        }
        else
            bodytrans += body[i];
    }
    //cout << bodytrans;
    wofstream transtest;
    transtest.open("H:\\810C XDF EPUB\\Xepub\\texttrans\\test.txt");
    transtest << bodytrans;
    transtest.close();
    system("pause");
    return 0;
}

wstring getsetting(wstring csssub, wstring settingname){
    wstring buf1;
    wstring fullsetting;
    wstring setting = L"<color";
    if(csssub.find(settingname)!=-1){
            int pos1 = csssub.find(L"{",csssub.find(settingname));
            int pos2 = csssub.find(L"}",pos1 + 1);
            fullsetting = csssub.substr(pos1+1,pos2-pos1-1);
            //cout << fullsetting;
        }
        if(fullsetting.find(L"color")!=-1){
            int pos1 = fullsetting.find(L":",fullsetting.find(L"color"));
            int pos2 = fullsetting.find(L";",pos1+1);
            buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
            wstring buf2 = L"";
            for(int i = 0;i<buf1.size();i++){
                if(buf1[i]!=L' ')
                buf2 += buf1[i];
            }
            setting +=buf2 +L" font";
        }
        else{
            setting += L"default font";
        }
        if(fullsetting.find(L"font-family")!=-1){
            int pos1 = fullsetting.find(L":",fullsetting.find(L"font-family"));
            int pos2 = fullsetting.find(L";",pos1+1);
            buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
            wstring buf2 = L"";
            for(int i = 0;i<buf1.size();i++){
                if(buf1[i]!=L' ')
                buf2 += buf1[i];
            }
            setting +=buf2 +L" size";
        }
        else{
            setting += L"default size";
        }if(fullsetting.find(L"font-size")!=-1){
            int pos1 = fullsetting.find(L":",fullsetting.find(L"font-size"));
            int pos2 = fullsetting.find(L";",pos1+1);
            buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
            wstring buf2 = L"";
            for(int i = 0;i<buf1.size();i++){
                if(buf1[i]!=L' ')
                buf2 += buf1[i];
            }
            setting +=buf2 +L" bold";
        }
        else{
            setting += L"default bold";
        }if(fullsetting.find(L"bold")!=-1){
            setting += L"1 italic";
        }
        else{
            setting += L"0 italic";
        }if(fullsetting.find(L"italic")!=-1){
            setting += L"1 underline";
        }
        else{
            setting += L"0 underline";
        }if(fullsetting.find(L"underline")!=-1){
            setting += L"1 align";
        }
        else{
            setting += L"0 align";
        }if(fullsetting.find(L"align")!=-1){
            int pos1 = fullsetting.find(L":",fullsetting.find(L"align"));
            int pos2 = fullsetting.find(L";",pos1+1);
            buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
            wstring buf2 = L"";
            for(int i = 0;i<buf1.size();i++){
                if(buf1[i]!=' ')
                buf2 += buf1[i];
            }
            setting +=buf2 +L" url";
        }
        else{
            setting += L"default url";
        }
    return setting;//lack of ">"
}
