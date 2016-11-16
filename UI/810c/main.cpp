#include "mainwindow.h"
#include <QApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    TextLine L;
    L.insertString("this is the word I want to get\t");
    L.insertString("another string,wow.");
    TextLine L2;
    L2.insertString("This should be another line");
    Frame f(40,20,600,600,1);
    f.addTextLine(L);
    f.addTextLine(L2);
    cout<<f.getText().getLen()<<endl;
    cout<<f.getText().getTextLineList().size()<<endl;
    w.addFrame(f);
    w.show();

    return a.exec();
}
