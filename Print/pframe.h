/*This is frame process class, It can procss frame
 * Author: @Zejian Zhou(Github:JayZejianZhou) @Fan Yang(Github:fyang14)
 */


#ifndef PFRAME_H
#define PFRAME_H

#include <includes.hh>
//#include <frame.h>

class pframe
{
private:
    Frame * frame;// a poiter to point to frame instance
    QPaintDevice * printer;
    Page * page;//a poiter to point to frame instance
public:
    pframe(Frame * frame_in, QPaintDevice * device, Page * page_in);


    void draw();//the overall draw method, distribute draw works


//divided draw method
    void draw_image(QImage image);
    void draw_text(Text mytext);
    void draw_2dGraph();
};

#endif // PFRAME_H
