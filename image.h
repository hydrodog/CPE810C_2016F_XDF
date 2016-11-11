#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString imageName;
    QTextImageFormat format;
    qreal height;
    qreal width;
public slots:
    void insertImage();
    void setWidth();
    void setHeight();
};

#endif // MAINWINDOW_H
