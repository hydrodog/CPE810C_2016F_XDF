#ifndef MYFONT_H
#define MYFONT_H

#include <string>
#include <QFont>
#include <QColor>
class myFont{
//This class represent a single character and it has its own different style
private:
    QFont font;
    QColor c;
public:
    myFont();
    QFont getFont();
    QColor getColor();
    void setFont();
};


#endif // MYFONT_H


