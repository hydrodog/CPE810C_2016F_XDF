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
wstring ncx[500][2];//windows组做目录用,name and src
//为body设定做初始化
struct Set{
    string color = "default";
    string font = "default";
    string size = "default";
    string bold = "0";
    string italic = "0";
    string underline = "0";
    string align = "default";
};
Set bodydefault;//为了达到body的设定被其余所有覆盖的效果，获取default设定
string wtos(wstring wstr);//wstring 转化为 string
wstring stow(string str);//string 转化为 wstring
void getncx(wstring fullncx,int pos,int i);//为了windows组的目录，读取ncx文件的内容，提取章节名和链接，存在ncx[500][2]里
string settingdetail(string fullsetting,string settingname);
//fullsetting是对一段文字的所有截取取出未处理的原设定，settingname是这段文字的标签名，返回一个string形式的text组要求的设定
string getsetting(string cssfile, string settingname);
//cssfile是从".css"文件里读取的全文，settingname同上，返回该标签的css文件里的处理过的设定，string形式
wstring wopenfile(string path);//以wstring形式读取文件全文，返回wstring
string openfile(string path);//以string形式读取文件全文，返回string
string wtos(wstring wstr){
    QString qstr = QString::fromStdWString(wstr);
    string str = qstr.toStdString();
    return str;
}//QString中转
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
        if(buf.length() == 0)//跳过空行
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
void getncx(wstring fullncx,int pos,int i){//ncx文件格式，先有playOrder="number"，接着章节名<text>，链接文件地址src=""。
    if(fullncx.find(L"playOrder",pos) != wstring::npos){//如果找到了playOrder字段
        int postext1 = fullncx.find(L"<text>",fullncx.find(L"playOrder",pos));
        int postext2 = fullncx.find(L"</text>",postext1+6);
        ncx[i][0] = fullncx.substr(postext1+6,postext2-postext1-6);//将章节名储存
        int possrc1 = fullncx.find(L"src=",fullncx.find(L"playOrder",pos));
        int possrc2 = fullncx.find(L"\"",possrc1+5);
        ncx[i][1] = fullncx.substr(possrc1+5,possrc2-possrc1-5);//储存文件地址
        //wcout << ncx[i][0]<<'\n'<<ncx[i][1];//验证ncx储存内容
        if(fullncx.find(L"playOrder",possrc2)!=wstring::npos){//如果在后文中仍有playOrder字段，则继续
            i++;//ncx数组下一行
            getncx(fullncx,possrc2,i);//递归
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
    //上段可无视，实测不加也没问题
    //传进来的ncx文件地址，因epub文件内一定有且仅有一个ncx文件，可对getfiles.cpp中获得的文件地址数组一一比对"ncx"，找到匹配的文件地址
    string ncxpath = "C:\\Users\\lenovo\\Desktop\\Little Women\\OEBPS\\toc.ncx";
    wstring fullncx = wopenfile(ncxpath);//wstring形式读取ncx文件
    getncx(fullncx,0,0);//储存信息进ncx[500][2]，给windows组做目录调用
    /*int i = 0;
    while(true){

        if(ncx[i][0]==L""&&ncx[i][1]==L"")
            break;
        else {wcout << ncx[i][0]<< endl<<ncx[i][1]<<endl;
        i++;}
    }//cout << i;*/
    //输出ncx数组，验证信息无误
    string htmlpath1 = "C:\\Users\\lenovo\\Desktop\\Little Women\\OEBPS\\bano_9781411432574_oeb_c40_r1.html";
    //操作者想读的原文件地址，需要windows组传入
    /*QString qstr = QString::fromStdString(htmlpath1);
    qstr.replace(".html",".txt");
    string htmlpath2 = qstr.toStdString();
    //string txtpath = htmlpath.replace()
    //cout << htmlpath1<<endl <<htmlpath2;
    rename(htmlpath1.c_str(),htmlpath2.c_str());*/
    //以上一段替换文件名后缀的代码，之前测试中有过html文件读取出错，转化为txt才行的问题，目前无此必要。留着备用。
    wstring wsrc = wopenfile(htmlpath1);//wstring形式读取指定的html文件
    wstring body;//html里的正文部分，原文<body>标签。下面循环是截取它。
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
    //wcout<<body<<endl;//验证body内容
    string src = openfile(htmlpath1);//string形式读取一遍html文件
    string sub;//html文件里指向的css文件相对地址。下循环截取之。
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
    string csspath = "C:\\Users\\lenovo\\Desktop\\Little Women\\OEBPS\\"+sub;//即原html文件所在目录地址加相对地址，即绝对地址。
    //此步理论上也可截取出sub后，直接在getfiles.cpp里获取的文件地址数组里比对得到地址
    string csssub =openfile(csspath);//string形式的css文件全部内容
    //cout << csssub<<endl;
    string bodysetting = getsetting(csssub,"body")+"0>";//为Set bodydefault赋值
    //为各种html默认的标签截取赋值
    string h1setting = getsetting(csssub,"h1")+"0>";
    string h2setting = getsetting(csssub,"h2")+"0>";
    string h3setting = getsetting(csssub,"h3")+"0>";
    string h4setting = getsetting(csssub,"h4")+"0>";
    string h5setting = getsetting(csssub,"h5")+"0>";
    string h6setting = getsetting(csssub,"h6")+"0>";
    string divsetting = getsetting(csssub,"div")+"0>";
    string asetting = getsetting(csssub,"a ")+"1>";//getsetting返回的string最后是url，如为超链接则为1，否则为0。
    //cout << h1setting;
    wstring stylechange = L"<stylechange>";//便于后续body的处理，text组要求的特殊标记之一，每当遇到html标签变化，则加上以作提示。
    wstring bodytrans = L"";//处理后给text组的正文部分内容，应要求为wstring形式
    string allsetting = "";//处理后给text组的正文部分内容的设定，应要求为string形式，顺序与正文一一对应
    wstring imgset = L"";//图片组要求的图片设定，后续转化为QString形式
    for(int i = 0; i < body.size();i++){//对正文逐个判定
        if(body[i]=='<'){
            if(body[i+1]==L'p'){
                if(body[i+2]==L'>'){//如果是<P>，处理为\n
                bodytrans += L"\\n";
                }
            }
            else if(body[i+1]==L'/'){
                if(body[i+2]==L'b'){
                    if(body[i+3]==L'r'){
                        if(body[i+4]==L'/'){//如果是</br>，处理为\n
                            bodytrans += L"\\n";
                            }
                        }
                    }
                }
            else if(body[i+1]==L'h'){//若为h1-h6，bodytrans加上stylechange标记，allsetting加上对应的设定
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
                    if(body[i+3]==L'v'){//当出现<div时
                        bodytrans += L"\\n"+stylechange;//换行符以及转换标记
                        if(body.find(L"class=",i)<body.find(L">",i)){//如果<div>内有专属命名，提取名字
                            int pos1 = body.find(L"class=",i);
                            int pos2 = body.find(L"\"",pos1+7);
                            wstring wclassname = body.substr(pos1+7,pos2-pos1-7);
                            string classname = "."+wtos(wclassname)+" ";
                            allsetting += getsetting(csssub,classname)+"0>";//设定部分加上在css文件里该名字对应的设定
                        }
                        else if(body.find(L"style=",i)<body.find(L">",i)){//如果设定是写在html文件<div后面
                            int pos1 = body.find(L"style=",i);
                            int pos2 = body.find(L"\"",pos1+7);
                            wstring wstyle = body.substr(pos1+7,pos2-pos1-7);//提取style全文
                            string style = wtos(wstyle);
                            allsetting += settingdetail(style,"div") + "0>";//按text组要求处理style内容
                        }
                       else allsetting += divsetting;//如果以上皆不是，则按单纯的<div>处理
                    }
                }
            }
            else if(body[i+1]==L'a'){
                int pos1 = body.find(L"href=",i);
                int pos2 = body.find(L"\"",pos1+6);
                if(body.find(L">",i)>pos1)//如果是超链接标记
                {wstring href = body.substr(pos1 + 6,pos2 - pos1 - 6);//超链接地址
                //cout << href;
                bodytrans += stylechange + L"(" + href + L")";
                allsetting += asetting;}
            }
            else if(body[i+1]==L'i'){
                if(body[i+2]==L'm'){
                    if(body[i+3]==L'g'){//如果是<img图片
                        bodytrans += stylechange + L"<img>";//约定的表示图片的标记
                        int pos1 = body.find(L"src=");
                        int pos2 = body.find(L"\"",pos1 + 5);
                        imgset = body.substr(pos1+5,pos2-pos1-5);//wcout<<imgset;//图片的文件链接地址
                        if(body.find(L"style=",i)<body.find(L">",i)){//如果图片设定在html里以style形式声明
                            int posstyle1 = body.find(L"style=",i);
                            int posstyle2 = body.find(L"\"",posstyle1+7);
                            imgset += body.substr(posstyle1+7,posstyle2-posstyle1-7);
                                        //wcout << imgset;
                        }
                        else if(body.find(L"class=",i)<body.find(L">",i)){//如果图片设定不在html，而它有专属名称
                            int posclass1 = body.find(L"class=",i);
                            int posclass2 = body.find(L"\"",posclass1+7);
                            wstring wclassname = body.substr(posclass1+7,posclass2-posclass1-7);//图片区域名
                            string sclassname = "."+wtos(wclassname)+" ";
                            //cout << sclassname;
                            string fullsetting;//css内该图片的全设定
                            if(csssub.find(sclassname)!=string::npos){//若css文件内找到了对应的设定名
                                    int pos1 = csssub.find("{",csssub.find(sclassname));
                                    int pos2 = csssub.find("}",pos1 + 1);
                                    fullsetting = csssub.substr(pos1+1,pos2-pos1-1);//提取全设定
                                    string buf1;//中间缓冲
                                    string setting = "height=";//css内处理后的设定
                                    if(fullsetting.find("height")!=string::npos){//找到height设定
                                        int pos1 = fullsetting.find(":",fullsetting.find("height"));
                                        int pos2 = fullsetting.find(";",pos1+1);
                                        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
                                        string buf2 = "";
                                        for(int i = 0;i<buf1.size();i++){//去空格
                                            if(buf1[i]!=' ')
                                            buf2 += buf1[i];
                                        }
                                        setting += buf2+"width=";
                                    }
                                    else
                                        setting += "100%width=";
                                    if(fullsetting.find("width")!=string::npos){//找width设定
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
                                    if(fullsetting.find("align")!=string::npos){//找align设定
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
                                    imgset += stow(setting);//图片组需要的设定
                                    //wcout << imgset;
                                }
                        }else{//以上都不符合，则在html里寻找直接设定
                        if(body.find(L"height=",i)<body.find(L">",i)){
                            int posheight1 = body.find(L"height=",i);
                            int posheight2 = body.find(L"\"",posheight1+8);
                            imgset += body.substr(posheight1+8,posheight2-posheight1-8);
                        }else//默认
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
            i = body.find(L'>',i);//结束上述判定后，则判断对象跳至">"，下次循环至标签后
        }
        else
            bodytrans += body[i];//如果不是标签内内容，则直接读

    }
    //wcout <<bodytrans;//验证给text组的正文处理结果
    //cout << allsetting;//验证给text组的设定处理结果
    //wcout << imgset;//验证给image组的图片设定处理结果
    QString qimgset = QString::fromStdWString(imgset);//image组要的设定，含src,heigth，width，align四要素，转化为QString
    //rename(htmlpath2.c_str(),htmlpath1.c_str());//与之前开头的一次改文件名对应还原，现在应该可以无视
    /*wofstream test;
    test.open("test.txt");
    test << bodytrans;
    test.close();
    wcout<<wopenfile("test.txt");*/
    //写文件法测试中文的处理结果，控制台显示utf-8编码有误
    //system("pause");
    return 0;//程序结束
}

string getsetting(string csssub, string settingname){
    string fullsetting;
    if(csssub.find(settingname)!=string::npos){//提取对应标签在css文件内的设定全文
            int pos1 = csssub.find("{",csssub.find(settingname));
            int pos2 = csssub.find("}",pos1 + 1);
            fullsetting = csssub.substr(pos1+1,pos2-pos1-1);
            //cout << fullsetting;
        }
       string setting = settingdetail(fullsetting,settingname);//调用settingdetail，获得处理后的设定
       return setting;
}
string settingdetail(string fullsetting,string settingname){
    string buf1;
    string setting = "<color";
    if(fullsetting.find("color")!=string::npos){//若原设定中有color
        int pos1 = fullsetting.find(":",fullsetting.find("color"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);//截取color设定
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){//去空格
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" font";//写入设定
        if(settingname == "body"){//第一个运行的是body，为bodydefault赋值，并作为其余设定的默认值
            bodydefault.color = buf2;}
    }
    else{//若原文件无相关设定，则以bodydefault为准。后面部分同理
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
        setting +=buf2 +" url";//不封口，若有超链接则接"1"，否则"0"。加">"封口。
        if(settingname == "body"){
            bodydefault.align = buf2;}
    }
    else{
        setting += bodydefault.align+" url";
    }
return setting;//lack of ">"未封口。
}
