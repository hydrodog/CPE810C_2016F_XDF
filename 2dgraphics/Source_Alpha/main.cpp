#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <vector>
#include <iostream>
#include "shape.h"
#include "drawfunlist.h"
#include "exceptionoptdic.h"
#include "exceptiontwodg.h"
#include "operatordictrie.h"
#include "twodgraphics.h"

/*
 @author: 2D_Graphic Group  12/2/2016
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    #if 0
    MainWindow w;
    w.show();


  twoDGraphics* twoDGph;
#endif
  //read operator.dat file from config folder in the current directory,
  twoDGraphics* twoDGph = new twoDGraphics("C:\EE810_Project","test.txt");
  //set test data: set each shape info seperately
  //1st shape:
  std::string opter1 = "m";
  std::vector<double> opnds1;
  opnds1.push_back(12.21);
  opnds1.push_back(34.43);
  twoDGph->setShape(opter1, opnds1);
  //2nd shape:
  std::string opter2 = "l";
  std::vector<double> opnds2;
  opnds2.push_back(56.65);
  opnds2.push_back(78.87);
  twoDGph->setShape(opter2, opnds2);

  MainWindow m(twoDGph);

    m.show();

    return a.exec();
}
