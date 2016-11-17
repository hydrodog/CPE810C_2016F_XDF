#ifndef MYFONT_H
#define MYFONT_H

#include <string>
#include <QFont>
#include <QColor>
class myFont{
//This class represent a single character and it has its own different style
private:
    QFont t;
    QColor c;
public:
    myFont(const QString & family, int pointSize = -1, int weight = -1, bool italic = false);
    QFont getFont();
    QFont getcolor();
    void setfont();
};


#endif // MYFONT_H
