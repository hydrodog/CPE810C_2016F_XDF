#ifndef BORDER_HH__
#define BORDER_HH__

class Border{
//Contains the different distance to four edges
private:
    double leftEdge,rightEdge,topEdge,downEdge;
    int color;
public:
    Border(double height, double width);
    void Setcolor(int i);
    void clear();//Reset all value to defalut one


};
#endif // BORDER_H
