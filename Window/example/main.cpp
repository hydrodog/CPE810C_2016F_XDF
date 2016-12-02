#include "mainwindow.h"
#include <QApplication>

/**
 * @brief qMain
 * default main.cpp made with project to run MainWindow
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
