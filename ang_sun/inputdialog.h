#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT
public:
    explicit InputDialog(QWidget *parent = 0);
    ~InputDialog();

signals:
    void setWidthHeight(int width, int height);

public slots:
    void setWidthHeightClicked();

private:
    Ui::InputDialog *ui;

};

#endif // INPUTDIALOG_H
