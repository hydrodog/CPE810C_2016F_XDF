

#ifndef function_hpp
#define function_hpp

#include <stdio.h>

#endif /* function_hpp */
#include<fstream>
#include<string>
using namespace std;


// basic functions contained for image and 2Dgraph
void line(double x1, double y1, double x2, double y2);
void rect(double x, double y, double w, double h);
void fillrect(double x, double y, double w, double h);
void triangle(double x1, double y1, double x2, double y2, double x3, double y3);
void filltriangle(double x1, double y1, double x2, double y2, double x3, double y3);
void circle(double x, double y, double r);
void fillcircle(double x, double y, double r);
void ellipse(double x, double y, double r1, double r2);
void fillellipse(double x, double y, double r1, double r2);
void polyline(int n);
void star(double x, double y, double s);
void fillstar(double x, double y, double s);
void graphictext();
void setcolor(double r, double g, double b);
void setgray(double n);

