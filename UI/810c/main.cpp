#include "mainwindow.h"
#include <QApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    TextLine L;
    L.insert('a');
    Frame f(40,20,600,600,1);
    f.addTextLine(L);
    cout<<f.getText().getLen()<<endl;
    cout<<f.getText().getTextLineList().size()<<endl;
    w.addFrame(f);
    w.show();

    return a.exec();
}
