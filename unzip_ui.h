#ifndef EPUB_UNZIP_UI_H
#define EPUB_UNZIP_UI_H

#include <QMainWindow>
#include "ui_epub_unzip_ui.h"

class epub_unzip_ui : public QMainWindow
{
    Q_OBJECT

public:
    epub_unzip_ui(QWidget *parent = 0);
    ~epub_unzip_ui();

protected slots:
    void onBtn1();
    void onBtn2();
    void onBtn3();

private:
    Ui::epub_unzip_uiClass ui;
};

#endif // EPUB_UNZIP_UI_H
