#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <locale>
#include <wchar.h>
#include <cstdio>
#include <cstdlib>
#include <qstring.h>

using namespace std;
wstring ncx[500][2];//windows组做目录用,name and src
struct Set{
    string color = "default";
    string font = "default";
    string size = "default";
    string bold = "0";
    string italic = "0";
    string underline = "0";
    string align = "default";
};
Set bodydefault;
string wtos(wstring wstr);
wstring stow(string str);
string wtos(wstring wstr){
    QString qstr = QString::fromStdWString(wstr);
    string str = qstr.toStdString();
    return str;
}
wstring stow(string str){
    QString qstr = QString::fromStdString(str);
    wstring wstr = qstr.toStdWString();
    return wstr;
}
string settingdetail(string fullsetting,string settingname);
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
        //cout<<"open wfile err";
    }
    wstring src = L"";
    while(!wfile.eof()){
        getline(wfile,wbuf);
      /*  if(wbuf.length() == 0)
        {
            continue;
        }*/
        src+=wbuf;
        //wcout << src<<endl;
    }
    //wcout << src<<endl;
    wfile.close();
    return src;
}
void getncx(wstring fullncx,int pos,int i){
    if(fullncx.find(L"playOrder",pos) != wstring::npos){
        int postext1 = fullncx.find(L"<text>",fullncx.find(L"playOrder",pos));
        int postext2 = fullncx.find(L"</text>",postext1+6);
        ncx[i][0] = fullncx.substr(postext1+6,postext2-postext1-6);
        int possrc1 = fullncx.find(L"src=",fullncx.find(L"playOrder",pos));
        int possrc2 = fullncx.find(L"\"",possrc1+5);
        ncx[i][1] = fullncx.substr(possrc1+5,possrc2-possrc1-5);
        //wcout << ncx[i][0]<<'\n'<<ncx[i][1];
        if(fullncx.find(L"playOrder",possrc2)!=wstring::npos){
            i++;
            getncx(fullncx,possrc2,i);
        }
        return;
    }
    return;
}

int main() {
    /*setlocale(LC_ALL, "chs");
    ios_base::sync_with_stdio(false); // 缺少的话，wcout wchar_t 会漏掉中文
    wcout.imbue(locale(""));
    wstring u = L"奥尔as123";
    wcout << u;*/
    string ncxpath = "C:\\Users\\lenovo\\Desktop\\Little Women\\OEBPS\\toc.ncx";
    wstring fullncx = wopenfile(ncxpath);
    getncx(fullncx,0,0);
    /*int i = 0;
    while(true){

        if(ncx[i][0]==L""&&ncx[i][1]==L"")
            break;
        else {wcout << ncx[i][0]<< endl<<ncx[i][1]<<endl;
        i++;}
    }//cout << i;*/
    string htmlpath1 = "C:\\Users\\lenovo\\Desktop\\Little Women\\OEBPS\\bano_9781411432574_oeb_c40_r1.html";//原文件地址
    QString qstr = QString::fromStdString(htmlpath1);
    qstr.replace(".html",".txt");
    string htmlpath2 = qstr.toStdString();
    //string txtpath = htmlpath.replace()
    //cout << htmlpath1<<endl <<htmlpath2;
    rename(htmlpath1.c_str(),htmlpath2.c_str());
    wstring wsrc = wopenfile(htmlpath2);
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
    string src = openfile(htmlpath2);
    string sub;
    while(true){
        int pos1 = src.find("link");//find css head
        if(pos1<0)
            break;
        int pos2 = src.find("href=\"",pos1+4);//head of css
        if (pos2<0)
            break;
        int pos3 = src.find(".css",pos2+6);  // tail of css
        sub = src.substr(pos2+6,pos3-pos2-2);//text of body
        if(sub.find(">",pos2)>pos3)
        src.erase(src.begin()+pos1,src.begin()+pos2+1);
            //cout<<sub<<endl;
            break;
    }
    string csspath = "C:\\Users\\lenovo\\Desktop\\Little Women\\OEBPS\\"+sub;
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
    wstring stylechange = L"<stylechange>";
    wstring bodytrans = L"";
    string allsetting = "";
    wstring imgset = L"";
    for(int i = 0; i < body.size();i++){
        if(body[i]=='<'){
            if(body[i+1]==L'p'){
                if(body[i+2]==L'>'){
                bodytrans += L"\\n";
                }
            }
            else if(body[i+1]==L'/'){
                if(body[i+2]==L'b'){
                    if(body[i+3]==L'r'){
                        if(body[i+4]==L'/'){
                            bodytrans += L"\\n";
                            }
                        }
                    }
                }
            else if(body[i+1]==L'h'){
                if(body[i+2]==L'1'){
                    bodytrans += stylechange;
                allsetting += h1setting;}
                else if(body[i+2]==L'2'){
                    bodytrans += stylechange;
                allsetting += h2setting;}
                else if(body[i+2]==L'3'){
                    bodytrans += stylechange;
                allsetting += h3setting;}
                else if(body[i+2]==L'4'){
                    bodytrans += stylechange;
                allsetting += h4setting;}
                else if(body[i+2]==L'5'){
                    bodytrans += stylechange;
                allsetting += h5setting;}
                else if(body[i+2]==L'6'){
                    bodytrans += stylechange;
                allsetting += h6setting;}
            }
            else if(body[i+1]==L'd'){
                if(body[i+2]==L'i'){
                    if(body[i+3]==L'v'){
                        bodytrans += L"\\n"+stylechange;
                        if(body.find(L"class=",i)<body.find(L">",i)){
                            int pos1 = body.find(L"class=",i);
                            int pos2 = body.find(L"\"",pos1+7);
                            wstring wclassname = body.substr(pos1+7,pos2-pos1-7);
                            string classname = "."+wtos(wclassname)+" ";
                            allsetting += getsetting(csssub,classname)+"0>";
                        }
                        else if(body.find(L"style=",i)<body.find(L">",i)){
                            int pos1 = body.find(L"style=",i);
                            int pos2 = body.find(L"\"",pos1+7);
                            wstring wstyle = body.substr(pos1+7,pos2-pos1-7);
                            string style = wtos(wstyle);
                            allsetting += settingdetail(style,"div") + "0>";
                        }
                       else allsetting += divsetting;
                    }
                }
            }
            else if(body[i+1]==L'a'){
                int pos1 = body.find(L"href=",i);
                int pos2 = body.find(L"\"",pos1+6);
                if(body.find(L">",i)>pos1)
                {wstring href = body.substr(pos1 + 6,pos2 - pos1 - 6);
                //cout << href;
                bodytrans += stylechange + L"(" + href + L")";
                allsetting += asetting;}
            }
            else if(body[i+1]==L'i'){
                if(body[i+2]==L'm'){
                    if(body[i+3]==L'g'){
                        bodytrans += stylechange + L"<img>";
                        int pos1 = body.find(L"src=");
                        int pos2 = body.find(L"\"",pos1 + 5);
                        imgset = body.substr(pos1+5,pos2-pos1-5);//wcout<<imgset;
                        if(body.find(L"style=",i)<body.find(L">",i)){
                            int posstyle1 = body.find(L"style=",i);
                            int posstyle2 = body.find(L"\"",posstyle1+7);
                            imgset += body.substr(posstyle1+7,posstyle2-posstyle1-7);
                                        //wcout << imgset;
                        }
                        else if(body.find(L"class=",i)<body.find(L">",i)){
                            int posclass1 = body.find(L"class=",i);
                            int posclass2 = body.find(L"\"",posclass1+7);
                            wstring wclassname = body.substr(posclass1+7,posclass2-posclass1-7);
                            string sclassname = "."+wtos(wclassname)+" ";
                            //cout << sclassname;
                            string fullsetting;
                            if(csssub.find(sclassname)!=string::npos){
                                    int pos1 = csssub.find("{",csssub.find(sclassname));
                                    int pos2 = csssub.find("}",pos1 + 1);
                                    fullsetting = csssub.substr(pos1+1,pos2-pos1-1);
                                    string buf1;
                                    string setting = "height=";
                                    if(fullsetting.find("height")!=string::npos){
                                        int pos1 = fullsetting.find(":",fullsetting.find("height"));
                                        int pos2 = fullsetting.find(";",pos1+1);
                                        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
                                        string buf2 = "";
                                        for(int i = 0;i<buf1.size();i++){
                                            if(buf1[i]!=' ')
                                            buf2 += buf1[i];
                                        }
                                        setting += buf2+"width=";
                                    }
                                    else
                                        setting += "100%width=";
                                    if(fullsetting.find("width")!=string::npos){
                                        int pos1 = fullsetting.find(":",fullsetting.find("width"));
                                        int pos2 = fullsetting.find(";",pos1+1);
                                        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
                                        string buf2 = "";
                                        for(int i = 0;i<buf1.size();i++){
                                            if(buf1[i]!=' ')
                                            buf2 += buf1[i];
                                        }
                                        setting += buf2+"align=";
                                    }
                                    else
                                        setting += "100%align=";
                                    if(fullsetting.find("align")!=string::npos){
                                        int pos1 = fullsetting.find(":",fullsetting.find("align"));
                                        int pos2 = fullsetting.find(";",pos1+1);
                                        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
                                        string buf2 = "";
                                        for(int i = 0;i<buf1.size();i++){
                                            if(buf1[i]!=' ')
                                            buf2 += buf1[i];
                                        }
                                        setting += buf2;
                                    }
                                    else
                                        setting += "middle";
                                    //cout << setting;
                                    imgset += stow(setting);
                                    //wcout << imgset;
                                }
                        }else{
                        if(body.find(L"height=",i)<body.find(L">",i)){
                            int posheight1 = body.find(L"height=",i);
                            int posheight2 = body.find(L"\"",posheight1+8);
                            imgset += body.substr(posheight1+8,posheight2-posheight1-8);
                        }else
                            imgset += L"height:100%";
                        if(body.find(L"width=",i)<body.find(L">",i)){
                            int poswidth1 = body.find(L"width=",i);
                            int poswidth2 = body.find(L"\"",poswidth1+7);
                            imgset += body.substr(poswidth1+7,poswidth2-poswidth1-7);
                        }else
                            imgset += L"width:100%";
                        if(body.find(L"align=",i)<body.find(L">",i)){
                            int posalign1 = body.find(L"align=",i);
                            int posalign2 = body.find(L"\"",posalign1+7);
                            imgset += body.substr(posalign1+7,posalign2-posalign1-7);
                        }else
                            imgset += L"align:middle";
                        }
                    }
                }
            }
            i = body.find(L'>',i);
        }
        else
            bodytrans += body[i];

    }
    //wcout <<bodytrans;
    //cout << allsetting;
    //wcout << imgset;
    QString qimgset = QString::fromStdWString(imgset);//image组要的设定，含src,heigth，width，align四要素
    rename(htmlpath2.c_str(),htmlpath1.c_str());
    /*wofstream test;
    test.open("test.txt");
    test << bodytrans;
    test.close();
    wcout<<wopenfile("test.txt");*/
    //system("pause");
    return 0;
}

string getsetting(string csssub, string settingname){
    string fullsetting;
    if(csssub.find(settingname)!=string::npos){
            int pos1 = csssub.find("{",csssub.find(settingname));
            int pos2 = csssub.find("}",pos1 + 1);
            fullsetting = csssub.substr(pos1+1,pos2-pos1-1);
            //cout << fullsetting;
        }
       string setting = settingdetail(fullsetting,settingname);
       return setting;
}
string settingdetail(string fullsetting,string settingname){
    string buf1;
    string setting = "<color";
    if(fullsetting.find("color")!=string::npos){
        int pos1 = fullsetting.find(":",fullsetting.find("color"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" font";
        if(settingname == "body"){
            bodydefault.color = buf2;}
    }
    else{
        setting += bodydefault.color+" font";
    }
    if(fullsetting.find("font-family")!=string::npos){
        int pos1 = fullsetting.find(":",fullsetting.find("font-family"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" size";
        if(settingname == "body"){
            bodydefault.font = buf2;}
    }
    else{
        setting += bodydefault.font+" size";
    }if(fullsetting.find("font-size")!=string::npos){
        int pos1 = fullsetting.find(":",fullsetting.find("font-size"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" bold";
        if(settingname == "body"){
            bodydefault.size = buf2;}
    }
    else{
        setting += bodydefault.size+" bold";
    }if(fullsetting.find("bold")!=string::npos){
        setting += "1 italic";
        if(settingname == "body"){
            bodydefault.bold = "1";}
    }
    else{
        setting += bodydefault.bold+" italic";
    }if(fullsetting.find("italic")!=string::npos){
        setting += "1 underline";
        if(settingname == "body"){
            bodydefault.italic = "1";}
    }
    else{
        setting += bodydefault.italic+" underline";
    }if(fullsetting.find("underline")!=string::npos){
        setting += "1 align";
        if(settingname == "body"){
            bodydefault.underline = "1";}
    }
    else{
        setting += bodydefault.underline+" align";
    }if(fullsetting.find("align")!=string::npos){
        int pos1 = fullsetting.find(":",fullsetting.find("align"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" url";
        if(settingname == "body"){
            bodydefault.align = buf2;}
    }
    else{
        setting += bodydefault.align+" url";
    }
return setting;//lack of ">"
}
