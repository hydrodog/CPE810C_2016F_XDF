#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QPixmap>
#include <QPaintEvent>


class Image{
private:
   QString m_filename;
   QImage m_image;
   static Image m_copy;
public:
   Image(QString filename):m_filename(filename){}
   ~Image(){}
   bool load(){
       bool load;
       load=m_image.load(m_filename);
       if(load)
           return true;
       else
           return false;
   }
//   void scaled(int width,int height){
//       m_image=m_image.scaled(width,height);
//   }//change the scale of the image
//   void scaled(double scale){
//       int width=m_image.width()*scale;
//       int height=m_image.height()*scale;
//       m_image=m_image.scaled(width,height);
//   }
//   void transformed(double degrees){
//       QMatrix rotate;
//       m_image=m_image.transformed(rotate.rotate(degrees));
//   }//rotate the image
//   bool save(QString filename){
//       bool save;
//       save=m_image.save(filename);
//       if(save)
//           return true;
//       else
//           return false;
//   }//save the image
//   friend void copy(Image image){
//       m_copy.m_filename=image.m_filename;
//   }//copy the image
//   friend void cut(Image& image){
//       m_copy.m_filename=image.m_filename;
//       ~image();
//   }//cut the image
//   friend Image paste(){
//       return Image(m_copy.m_filename);
//   }//paste the image
   QImage output(){
       return m_image;
   }
//   qint64 key(){
//       return m_image.cacheKey();
//   }
};

#endif // IMAGE_H
