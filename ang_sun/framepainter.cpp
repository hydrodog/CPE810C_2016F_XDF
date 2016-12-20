#include "framepainter.h"

#include <QDebug>
#include <QPainter>

FramePainter::FramePainter(QWidget *parent)
    : QFrame(parent)
{

}

void FramePainter::resetImage()
{
    if(!m_images.isEmpty())
    {
        for(int i=0; i<m_images.count(); ++i)
        {
            Image image = m_images[i];
            if(!image.m_inputPath.isEmpty() && !image.m_image.load(image.m_inputPath))
            {
                qDebug() << "Input Error!";
                return;
            }
            update();
        }
    }
}

void FramePainter::exportImage(const QString &path)
{
    grab(rect()).save(path);
}

void FramePainter::insertImage(const QString &path, const QPoint &point)
{
    Image image;
    image.m_pos = point;
    image.m_inputPath = path;
    image.m_image.load(path);
    m_images << image;

    update();
}

void FramePainter::setWidthHeight(int width, int height)
{
    for(int i=0; i<m_images.count(); ++i)
    {
        Image *image = &m_images[i];
        image->m_image = image->m_image.scaled(width, height);
    }
    update();
}

void FramePainter::scaleImage(float value)
{
    for(int i=0; i<m_images.count(); ++i)
    {
        Image *image = &m_images[i];
        image->m_image = image->m_image.scaled(image->m_image.width()*value,
                                               image->m_image.height()*value,
                                               Qt::KeepAspectRatio);
    }
    update();
}

void FramePainter::rotateImage(float value)
{
    for(int i=0; i<m_images.count(); ++i)
    {
        QMatrix rotate;
        Image *image = &m_images[i];
        image->m_image = image->m_image.transformed(rotate.rotate(value), Qt::SmoothTransformation);
    }
    update();
}

QPoint FramePainter::getPoint(int index) const
{
    if(index < 0 || index >= m_images.count())
    {
        return QPoint();
    }

    return m_images[index].m_pos;
}

QList<QPoint> FramePainter::getPoints() const
{
    QList<QPoint> pts;
    foreach(const Image &image, m_images)
    {
        pts << image.m_pos;
    }
    return pts;
}

void FramePainter::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    for(int i=0; i<m_images.count(); ++i)
    {
        const Image &image = m_images[i];
        if(!image.m_image.isNull())
        {
            painter.drawImage(image.m_pos, image.m_image);
        }
    }
}
