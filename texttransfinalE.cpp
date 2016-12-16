#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <locale>//wcout Chinese may use it
#include <wchar.h>
#include <cstdio>
#include <cstdlib>
#include <qstring.h>

using namespace std;
wstring ncx[500][2];//for windows' menu ,name and src
//for body set initialization
struct Set{
    string color = "default";
    string font = "default";
    string size = "default";
    string bold = "0";
    string italic = "0";
    string underline = "0";
    string align = "default";
};
Set bodydefault;//bodyset is the basement, covered by other set
string wtos(wstring wstr);//wstring to string
wstring stow(string str);//string to wstring
void getncx(wstring fullncx,int pos,int i);//for windows' menu，read ncx file，get name and src，save in ncx[500][2]
string settingdetail(string fullsetting,string settingname);
//fullsetting is what setting in the source， settingname is the name of the setting，return a string for text team
string getsetting(string cssfile, string settingname);
//cssfile is what in the file ".css"，settingname is as former，return a string that the setting of the tag in the style text team asked
wstring wopenfile(string path);//read the file in wstring way，return a wstring
string openfile(string path);//read the file in string way，return a string
string wtos(wstring wstr){
    QString qstr = QString::fromStdWString(wstr);
    string str = qstr.toStdString();
    return str;
}//QString in middle
wstring stow(string str){
    QString qstr = QString::fromStdString(str);
    wstring wstr = qstr.toStdWString();
    return wstr;
}
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
        if(buf.length() == 0)//skip the null
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
void getncx(wstring fullncx,int pos,int i){//in ncx file，there is playOrder="number"，and then the name after <text>，link after src=""。
    if(fullncx.find(L"playOrder",pos) != wstring::npos){//if playOrder is found
        int postext1 = fullncx.find(L"<text>",fullncx.find(L"playOrder",pos));
        int postext2 = fullncx.find(L"</text>",postext1+6);
        ncx[i][0] = fullncx.substr(postext1+6,postext2-postext1-6);//save the name in ncx array
        int possrc1 = fullncx.find(L"src=",fullncx.find(L"playOrder",pos));
        int possrc2 = fullncx.find(L"\"",possrc1+5);
        ncx[i][1] = fullncx.substr(possrc1+5,possrc2-possrc1-5);//save the src
        //wcout << ncx[i][0]<<'\n'<<ncx[i][1];//see what is in ncx
        if(fullncx.find(L"playOrder",possrc2)!=wstring::npos){//if there is playOrder later，go on
            i++;//next row of ncx array
            getncx(fullncx,possrc2,i);//recursion
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
    //In test, without them the code can still work
    //path of the ncx file. Because epub has only one ncx file，we can find the "ncx" file in the array we gotten in getfiles.cpp
    string ncxpath = "C:\\Users\\lenovo\\Desktop\\Little Women\\OEBPS\\toc.ncx";
    wstring fullncx = wopenfile(ncxpath);//read ncx file in wstring way
    getncx(fullncx,0,0);//save name and sr in ncx[500][2] for windows team
    /*int i = 0;
    while(true){

        if(ncx[i][0]==L""&&ncx[i][1]==L"")
            break;
        else {wcout << ncx[i][0]<< endl<<ncx[i][1]<<endl;
        i++;}
    }//cout << i;*/
    //output ncx array for test
    string htmlpath1 = "C:\\Users\\lenovo\\Desktop\\Little Women\\OEBPS\\bano_9781411432574_oeb_c40_r1.html";
    //path of the html file user wanted to read， windows team may give it
    /*QString qstr = QString::fromStdString(htmlpath1);
    qstr.replace(".html",".txt");
    string htmlpath2 = qstr.toStdString();
    //string txtpath = htmlpath.replace()
    //cout << htmlpath1<<endl <<htmlpath2;
    rename(htmlpath1.c_str(),htmlpath2.c_str());*/
    //change the name of source，in former test html file made some mistakes, transform to txt.Now it is ik.
    wstring wsrc = wopenfile(htmlpath1);//read the html file in wstring way
    wstring body;//body in html source，<body>. the circulation cuts it out
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
    //wcout<<body<<endl;//test body
    string src = openfile(htmlpath1);//read html in string
    string sub;//the path in the source link to the css file. the circulation gets it.
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
    string csspath = "C:\\Users\\lenovo\\Desktop\\Little Women\\OEBPS\\"+sub;//path of the css file
    //this path can also be gotten in another way. find the sub in the array from getfiles.cpp.
    string csssub =openfile(csspath);//read css file in string
    //cout << csssub<<endl;
    string bodysetting = getsetting(csssub,"body")+"0>";//give Set bodydefault the value as default setting
    //find the setting of the tag in source html file
    string h1setting = getsetting(csssub,"h1")+"0>";
    string h2setting = getsetting(csssub,"h2")+"0>";
    string h3setting = getsetting(csssub,"h3")+"0>";
    string h4setting = getsetting(csssub,"h4")+"0>";
    string h5setting = getsetting(csssub,"h5")+"0>";
    string h6setting = getsetting(csssub,"h6")+"0>";
    string divsetting = getsetting(csssub,"div")+"0>";
    string asetting = getsetting(csssub,"a ")+"1>";//the string returned by getsetting is url at last，if there is a link, 1， or 0.
    //cout << h1setting;
    wstring stylechange = L"<stylechange>";//the symbol of every tag changing in source，one of the special symbols text team asked.
    wstring bodytrans = L"";//the body part given to text team in the style they asked，in wstring
    string allsetting = "";//the setting of body part given to text team in the style they asked，in string
    wstring imgset = L"";//the setting of image given to image team in the style，they need qstring
    for(int i = 0; i < body.size();i++){//Judge for the every wchar_t in the body
        if(body[i]=='<'){
            if(body[i+1]==L'p'){
                if(body[i+2]==L'>'){//if it is <P>， give \n
                bodytrans += L"\\n";
                }
            }
            else if(body[i+1]==L'/'){
                if(body[i+2]==L'b'){
                    if(body[i+3]==L'r'){
                        if(body[i+4]==L'/'){//if it is </br>， give\n
                            bodytrans += L"\\n";
                            }
                        }
                    }
                }
            else if(body[i+1]==L'h'){//if it is h1-h6，bodytrans add a stylechange symbol， allsetting the setting
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
                    if(body[i+3]==L'v'){//if there is <div
                        bodytrans += L"\\n"+stylechange;//change line and stylechange symbol
                        if(body.find(L"class=",i)<body.find(L">",i)){//if this <div> has a name，get the name
                            int pos1 = body.find(L"class=",i);
                            int pos2 = body.find(L"\"",pos1+7);
                            wstring wclassname = body.substr(pos1+7,pos2-pos1-7);
                            string classname = "."+wtos(wclassname)+" ";
                            allsetting += getsetting(csssub,classname)+"0>";//allsetting adds the setting of the name in css file
                        }
                        else if(body.find(L"style=",i)<body.find(L">",i)){//if the setting is behind the <div in html file
                            int pos1 = body.find(L"style=",i);
                            int pos2 = body.find(L"\"",pos1+7);
                            wstring wstyle = body.substr(pos1+7,pos2-pos1-7);//cut style out
                            string style = wtos(wstyle);
                            allsetting += settingdetail(style,"div") + "0>";//deal with the style setting as text team wanted
                        }
                       else allsetting += divsetting;//it is just <div>
                    }
                }
            }
            else if(body[i+1]==L'a'){
                int pos1 = body.find(L"href=",i);
                int pos2 = body.find(L"\"",pos1+6);
                if(body.find(L">",i)>pos1)//if it is <a ,link
                {wstring href = body.substr(pos1 + 6,pos2 - pos1 - 6);//the link href
                //cout << href;
                bodytrans += stylechange + L"(" + href + L")";
                allsetting += asetting;}
            }
            else if(body[i+1]==L'i'){
                if(body[i+2]==L'm'){
                    if(body[i+3]==L'g'){//if it is <img
                        bodytrans += stylechange + L"<img>";//the symbol of image, tell frame team there is an image
                        int pos1 = body.find(L"src=");
                        int pos2 = body.find(L"\"",pos1 + 5);
                        imgset = body.substr(pos1+5,pos2-pos1-5);//wcout<<imgset;//the src of the image
                        if(body.find(L"style=",i)<body.find(L">",i)){//if the setting of the image is as a style in the source
                            int posstyle1 = body.find(L"style=",i);
                            int posstyle2 = body.find(L"\"",posstyle1+7);
                            imgset += body.substr(posstyle1+7,posstyle2-posstyle1-7);
                                        //wcout << imgset;
                        }
                        else if(body.find(L"class=",i)<body.find(L">",i)){//if the setting is not in source，and it has its own name
                            int posclass1 = body.find(L"class=",i);
                            int posclass2 = body.find(L"\"",posclass1+7);
                            wstring wclassname = body.substr(posclass1+7,posclass2-posclass1-7);//its own name
                            string sclassname = "."+wtos(wclassname)+" ";
                            //cout << sclassname;
                            string fullsetting;//the full setting in the css file
                            if(csssub.find(sclassname)!=string::npos){//if the name is found in the css file
                                    int pos1 = csssub.find("{",csssub.find(sclassname));
                                    int pos2 = csssub.find("}",pos1 + 1);
                                    fullsetting = csssub.substr(pos1+1,pos2-pos1-1);//cut out the setting
                                    string buf1;//中间缓冲
                                    string setting = "height=";//deal with it
                                    if(fullsetting.find("height")!=string::npos){//find heigth setting
                                        int pos1 = fullsetting.find(":",fullsetting.find("height"));
                                        int pos2 = fullsetting.find(";",pos1+1);
                                        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
                                        string buf2 = "";
                                        for(int i = 0;i<buf1.size();i++){//delete blank
                                            if(buf1[i]!=' ')
                                            buf2 += buf1[i];
                                        }
                                        setting += buf2+"width=";
                                    }
                                    else
                                        setting += "100%width=";
                                    if(fullsetting.find("width")!=string::npos){//find width
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
                                    if(fullsetting.find("align")!=string::npos){//find align
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
                                    imgset += stow(setting);//the setting image setting needed
                                    //wcout << imgset;
                                }
                        }else{//or look for the setting in the source
                        if(body.find(L"height=",i)<body.find(L">",i)){
                            int posheight1 = body.find(L"height=",i);
                            int posheight2 = body.find(L"\"",posheight1+8);
                            imgset += body.substr(posheight1+8,posheight2-posheight1-8);
                        }else//default
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
            i = body.find(L'>',i);//end of the judgment, and jump to the ">", in the next circulation, judge the digit next ">"
        }
        else
            bodytrans += body[i];//if it is not in the tag, add it

    }
    //wcout <<bodytrans;//test the body for text team
    //cout << allsetting;//test the setting for text team
    //wcout << imgset;//test the setting for image team
    QString qimgset = QString::fromStdWString(imgset);//image team asked a qstring， including src,heigth，width，align
    //rename(htmlpath2.c_str(),htmlpath1.c_str());//it is corresponding to the former, now no use.
    /*wofstream test;
    test.open("test.txt");
    test << bodytrans;
    test.close();
    wcout<<wopenfile("test.txt");*/
    //test for chinese source, in terminal utf-8 can not output normal.
    //system("pause");
    return 0;//end
}

string getsetting(string csssub, string settingname){
    string fullsetting;
    if(csssub.find(settingname)!=string::npos){//get thesetting of the tag in the css file
            int pos1 = csssub.find("{",csssub.find(settingname));
            int pos2 = csssub.find("}",pos1 + 1);
            fullsetting = csssub.substr(pos1+1,pos2-pos1-1);
            //cout << fullsetting;
        }
       string setting = settingdetail(fullsetting,settingname);//call for settingdetail，get the setting dealt with
       return setting;
}
string settingdetail(string fullsetting,string settingname){
    string buf1;
    string setting = "<color";
    if(fullsetting.find("color")!=string::npos){//if there is color
        int pos1 = fullsetting.find(":",fullsetting.find("color"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);//cut out color setting
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){//delete blank
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" font";//add the setting
        if(settingname == "body"){//the first call is for body，give the vaule to bodydefault as the default
            bodydefault.color = buf2;}
    }
    else{//if there is not color，add the bodydefault
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
        setting +=buf2 +" url";//lack of "1" or "0" and ">". if there is a link, it is "1", or "0".
        if(settingname == "body"){
            bodydefault.align = buf2;}
    }
    else{
        setting += bodydefault.align+" url";
    }
return setting;//lack of ">"
}
