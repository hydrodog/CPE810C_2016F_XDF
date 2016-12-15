#include "epub_unzip_ui.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if !(QT_VERSION >= 0x050000)
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());	
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
#endif

    epub_unzip_ui w;
    w.show();
    return a.exec();
}
