#ifndef MAINWINDOW_HH__
#define MAINWINDOW_HH__

#include <QMainWindow>
#include "frame.h"

//Generate by Qt automatically
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void addFrame(Frame f);//Could be a list of frame, one frame for test first
private slots:
    void on_actionFont_triggered();

    void on_actionColor_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
