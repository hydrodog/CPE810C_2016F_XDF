#ifndef TOD_H
#define TOD_H


#include <QtWidgets/QtWidgets>
#include "twodgraphics.h"
#include <QtGui>
#include <QtCore>

namespace Ui {
class ToD;
}

class ToD : public QDialog
{
    Q_OBJECT

public:
    explicit ToD(QWidget *parent = 0);
    ToD(twoDGraphics *twoDGph);
    ~ToD();

private:
    Ui::ToD *ui;
    twoDGraphics *mTwoDGph;
protected:
    void paintEvent(QPaintEvent *);
};

#endif // TOD_H
