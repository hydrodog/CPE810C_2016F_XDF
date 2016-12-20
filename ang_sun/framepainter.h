#ifndef FRAMEPAINTER_H
#define FRAMEPAINTER_H

#include <QFrame>

typedef struct Image
{
    QImage m_image;
    QString m_inputPath;
    QPoint m_pos;
}Image;

class FramePainter : public QFrame
{
    Q_OBJECT
public:
    explicit FramePainter(QWidget *parent = 0);

    void resetImage();
    void exportImage(const QString &path);
    void insertImage(const QString &path, const QPoint &point);
    void setWidthHeight(int width, int height);
    void scaleImage(float value);
    void rotateImage(float value);

    QPoint getPoint(int index) const;
    QList<QPoint> getPoints() const;

private:
    virtual void paintEvent(QPaintEvent *event) override;

    QList<Image> m_images;

};

#endif // FRAMEPAINTER_H
