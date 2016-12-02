#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void resetImage();
    void insertImage();
    void exportImage();
    void setWidthHeight();
    void setWidthHeight(int width, int height);
    void scaleImage();
    void rotateImage();

private:
    Ui::MainWindow *ui;
    QImage m_orImage;
    QString m_inputPath;

};

#endif // MAINWINDOW_H
