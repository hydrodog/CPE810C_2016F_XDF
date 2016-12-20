#ifndef POSINPUTDIALOG_H
#define POSINPUTDIALOG_H

#include <QDialog>

namespace Ui {
class PosInputDialog;
}

class PosInputDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PosInputDialog(QWidget *parent = 0);
    ~PosInputDialog();

signals:
    void setPostion(int x, int y);

public slots:
    void setPostionClicked();

private:
    Ui::PosInputDialog *ui;

};

#endif // POSINPUTDIALOG_H
