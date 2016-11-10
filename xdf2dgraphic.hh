/*file name: xdfFrame.hh
 * description: this class is used to print 2d graphics like line and circle.
 * Author: Fan Yang, Zejian Zhou*/

#ifndef 2DGRAPHIC_HH
#define 2DGRAPHIC_HH


class TdGraphics{
private:
public:
    TdGraphics();//constructor doesn't need to do anything
    void drawLine(int x, int y);//draw line method
    void drawCircle(int x, int y, int r);//draw circle
    void drawPoint(int x, int y);//draw point
};

#endif // 2DGRAPHIC_HH
