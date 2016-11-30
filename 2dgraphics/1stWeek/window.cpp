#include "window.h"
#include "ui_window.h"
#include<Qpainter>
Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}
void Window::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //draw pen, decide line and boundary attributes
    painter.setPen(QPen(Qt::red));

    //fill color in shape
    painter.setBrush(QBrush(Qt::blue));

    //paint a rectangle
    painter.drawRect(100,100,150,150);

    //paint a line in two ways.
    painter.drawLine(50,50,500,50);
    painter.drawLine(QPoint(50,50),QPoint(50,500));

    //paint a pie.
    QRectF pie_rectangle(10.0, 20.0, 80.0, 60.0);
    int startAngle = 30 * 16;
    int spanAngle = 120 * 16;
    painter.drawPie(pie_rectangle, startAngle, spanAngle);

    //paint a point
    painter.drawPoint(800,800);

    //draws a polygon.
    static const QPointF polygon_points[4] = {
        QPointF(300.0,300.0),
        QPointF(250.0,350.0),
        QPointF(280.0, 370.0),
        QPointF(310.0, 330.0)
    };
    painter.drawPolygon(polygon_points, 4);

    //draw polylines
    static const QPointF polyline_points[3] = {
        QPointF(410.0, 480.0),
        QPointF(420.0, 410.0),
        QPointF(480.0, 430.0),
    };
    painter.drawPolyline(polyline_points, 3);

    //draw a rect with rounded corners.
    QRectF rec_rectangle(510.0, 520.0, 580.0, 560.0);
    painter.drawRoundedRect(rec_rectangle, 40.0, 25.0);

    //paint a picture, but useless,another group do this.
    QPixmap pix("20161107045949781.jpg");
    painter.drawPixmap(600,100,pix);

    //write words, useless too.
    QFont font;
    font.setFamily("Tohama");
    font.setPointSize(50);
    painter.setFont(font);
    painter.drawText(600,520,"I Love C++");

}
