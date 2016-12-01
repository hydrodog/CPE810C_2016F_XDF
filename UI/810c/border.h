#ifndef BORDER_HH__
#define BORDER_HH__
#include <QColor>
class Border{
//Contains the different distance to four edges
private:
    int m_leftEdge,m_rightEdge,m_topEdge,m_downEdge;
    QColor m_color;
public:
    Border(int height, int width);

    void clear();//Reset all value to defalut one

    int leftEdge(){return m_leftEdge;}
    int rightEdge(){return m_rightEdge;}
    int topEdge(){return m_topEdge;}
    int downEdge(){return m_downEdge;}

    void leftEdge(int left){m_leftEdge=left;}
    void rightEdge(int right){m_rightEdge=right;}
    void topEdge(int top){m_topEdge=top;}
    void downEdge(int down){m_downEdge=down;}
    void color(QColor c){m_color=c;}
};
#endif // BORDER_H