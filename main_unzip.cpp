#include <QtCore/QCoreApplication>
#include <QTextCodec>
#include "ZHead.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    QString path = QDir::currentPath();
    QString zip = path + "/" + "第一哲学沉思集.epub";
    QString dir = path + "/" + "123";
    UnZipToDirectory(zip.toStdString().c_str(),dir.toStdString().c_str());

    return 0;
}
