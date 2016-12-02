#ifndef IMAGE_H
#define IMAGE_H

#include <QDialog>

#include <QImage>
#include <QPixmap>
#include <QPaintEvent>

namespace Ui {
class image;
}

class image : public QDialog
{
    Q_OBJECT

public:
    explicit image(QWidget *parent = 0);
    ~image();
    int getWidth();
    int getHeight();
    QImage getImage();

private slots:
    void on_pushButton_open_clicked();

    void on_spinBox_width_editingFinished();

    void on_spinBox_height_editingFinished();

    void on_pushButton_save_clicked();

    void on_spinBox_rotate_editingFinished();

    void on_spinBox_scale_editingFinished();
protected:

    void paintEvent(QPaintEvent *e);

private:
    Ui::image *ui;

    QString imagename;
    QString imagesavename;

    int width_flag=0;
    int saveas_flag=0;
    int height_flag=0;
    int rotate_flag=0;

    int width=0;
    int height=0;
    int rotate=0;
    int time=1;


};

#endif // IMAGE_H
