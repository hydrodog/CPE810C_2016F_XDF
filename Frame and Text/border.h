#ifndef BORDER_H__
#define BORDER_H__

class Border{
//This class contains the different distance to four edges
private:
    double left,right,top,down;
    int color;
public:
    Border(double height, double width);

    void clear();//Reset all value to defalut one


};

#endif // BORDER_H
