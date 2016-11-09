#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>

#include <QMainWindow>

static const int NoOpenFile = 1;
static const int HaveOpenFile = 2;
static const int NoState = 0;
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

    void on_actionOpen_file_triggered();

    void on_actionSave_as_triggered();

    void on_actionSave_file_triggered();

    void on_actionNew_file_triggered();

    void on_actionDigital_signature_triggered();

private:

    Ui::MainWindow *ui;
    QString fileName;
    static int fileState;

};
#endif // MAINWINDOW_H
