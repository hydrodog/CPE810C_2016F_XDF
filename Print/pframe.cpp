
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

void pframe::draw_text(Text mytext){
        list<Content> MT = mytext.contentList();
        vector<Content> L;
        list<Content>::iterator i;
        for (i = MT.begin() ;i != MT.end(); ++i){
            L.push_back(*i);
        }
        //get the length of the whole text
        int NumOfContent = mytext.getnumber();

        for(int a = 0; a <= NumOfContent; a++){//the loop of the whole content
           int Y = 0; //define the pos of the y coordinate
           int num2 = L[a].getlength();//get the number of word contained in one content object
           int lineamount = L[a].getlineamount();//get the number of the lines for one content object
           int * P1;
           P1 = L[a].getlinechange();
           QFont pfont = L[a].font();//get the font of the content
           const QColor pcolor = L[a].color();//get the color of the content
           QString str = L[a].getQString();
           int * LC = L[a].getlinechange();

           for (Y = 0; Y <=lineamount; Y++){//the loop of the lines contained in one content
               QString str1;
               for (int bre; bre <= *LC; bre++){
                   str1 += str[bre];
               }//to get the component of the string
               painter.setFont(pfont);
               painter.setPen(pcolor);
               painter.drawText(0, Y, str1);
               str1.clear();
           }
//                   const QRect r(0,Y,2000,2000);
//                   QTextOption option(Qt::AlignLeft);
//                   painter.setFont(pfont);
//                   painter.setPen(pcolor);
//                   painter.drawText(r, str, option);
//                   Y = r.height();
        }
}
