#include "image.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.insertImage();
    w.show();

    return a.exec();
}
