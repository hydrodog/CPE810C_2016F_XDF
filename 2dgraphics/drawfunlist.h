#ifndef DRAW_FUNLIST_HH__
#define DRAW_FUNLIST_HH__

#include "Shape.h"
#include "ExceptionDraw.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <QtGui>
#include <QtCore>
#include <QWidget>

/*
 @author: Seito Ryu  20/11/16
 @Purpose: Set all QT draw methods and initialize operator:method set
 */
/**
 TODO: implement basic and complicated QT methods
*/
class DrawFunList{
private:
  std::map<std::string, void (DrawFunList::*)(const std::vector<double>&, const int&)> mapDrw;
  void draw1(const std::vector<double>& operands, const int& currentIndex);
  void draw2(const std::vector<double>& operands, const int& currentIndex);
  void draw3(const std::vector<double>& operands, const int& currentIndex);
  void draw4(const std::vector<double>& operands, const int& currentIndex);
  void draw5(const std::vector<double>& operands, const int& currentIndex);
  void draw6(const std::vector<double>& operands, const int& currentIndex);
  void draw7(const std::vector<double>& operands, const int& currentIndex);
  QPainterPath path;
  QPen pen;
  QBrush brush;

public:
    DrawFunList();
    ~DrawFunList();
    void draw(const std::string& currentOperator, const std::vector<double>& operands, const int& currentIndex);
    QPainterPath getPath();
    QPainter getPen();
    QPainter getBrush();
};

#endif
