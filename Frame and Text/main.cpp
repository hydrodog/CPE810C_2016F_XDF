#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    //zqx's test are as follow
    wifstream in;
    in.open(("testfile1.txt"));
    wstring testwords;
    wstring allwords;
    while(getline(in,testwords)){
        allwords=allwords+testwords;
    }
    //wcout<<allwords;
    const wstring allwords1=allwords;
    in.close();
    Text test1;
    test1.getText(allwords1);
    test1.dealContentmessage();
    return 0;
}
