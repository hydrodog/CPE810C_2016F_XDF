#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "twodgraphics.h"
#include <QtGui>
#include <QtCore>

/*
 @author: Bingyang Wen  12/2/16 "Bulid a drawing envrionment"
 
 */

namespace Ui {
class MainWindow;
}

class twoDGraphics;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(twoDGraphics *twoDGph);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    twoDGraphics *mTwoDGph;
protected:
    void paintEvent(QPaintEvent *);
};

#endif // MAINWINDOW_H
