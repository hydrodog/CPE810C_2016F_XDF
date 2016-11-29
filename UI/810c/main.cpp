#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include<fstream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    TextLine L;
    Content c;
    string k="AA啊中文测试";
    cout<<k;
    //c.getmessage(k);

    L.insertString("String one\n");
    L.insertString("another string,wow.");
    TextLine L2;
    L2.insertString("This should be another line");
    Frame f(40,20,600,600,1);
    //f.addContent(c);
    f.addTextLine(L);
    f.addTextLine(L2);  
    cout<<f.text().len()<<endl;
    cout<<f.text().textLineList().size()<<endl;
    w.addFrame(f);
    w.show();
    //zqx's test are as follow
    wifstream in("testfile1.txt");
    wstring words;
    try {
        in.is_open();
    }
    catch(int) {
        cout<<"Opening file error!"<<endl;
    }
    const int LINE_LENGTH = 200;
    wchar_t str[LINE_LENGTH];
    in.getline(str,LINE_LENGTH);
    cout<<str<<endl;
    return a.exec();
}
