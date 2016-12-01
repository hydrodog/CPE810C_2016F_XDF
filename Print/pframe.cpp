
#include "pframe.h"

pframe::pframe(Frame * frame_in, QPaintDevice * device, Page * page_in)
{
    frame=frame_in;//give out the address of frame
    printer = device;// give in the painting device
    page=page_in;
}



void pframe::draw()
{
    if(frame->type()==1) {//image type
        Image image_in = frame->getImage();
        draw_image(image_in.output());//TODO: need to remind
    }
    else if (frame->type()==0) draw_text();
    else if (frame->type()==2) draw_2dGraph();
    else std::cout<<"pframe draw distribution erro. type is:"<<frame->type()<<'\n';
}

void pframe::draw_image(QImage image)
{
    QRectF rec(frame->startX, frame->startY, frame->height, frame->width);
    QPainter paint(printer);//create a new Qpainter instance whcih can print on printer
    paint.drawImage(rec, image);//draw the image

}

void pframe::draw_2dGraph()
{

}
