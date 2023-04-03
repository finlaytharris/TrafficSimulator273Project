#include "vehicle.h"
#include <QTimer>
#include<QPainter>
#include<QTimer>

Vehicle::Vehicle(QGraphicsItem *parent)
                 : QGraphicsPixmapItem(parent)
             {
                setTransformOriginPoint(10,5);
                setFlag(QGraphicsItem::ItemIsMovable);
                setOffset(10,5);
                setPixmap(generateImage().scaled(50,50,Qt::KeepAspectRatio,
                                                         Qt::TransformationMode::SmoothTransformation));

                timer = new QTimer();
                timer->setInterval(50); // Update every 50 milliseconds
                connect(timer, &QTimer::timeout,this , &Vehicle::move);
                timer->start();


}

QRectF Vehicle::boundingRect() const
{
    return QRectF(100,500,100,100);
}

QPainterPath Vehicle::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Vehicle::setDirection(qreal x, qreal y){
    direction_x = x;
    direction_y = y;
}
void Vehicle::setPosition(qreal x, qreal y){
    setPos(x, y);
}
void Vehicle::move(){
    setPos(x()+direction_x, y()+direction_y);
}

QPixmap Vehicle::generateImage() const
{
    switch (rand()%6) {
    case 0:
        return QPixmap(":/resources/car1.png");
    case 1:
        return QPixmap(":/resources/car2.png");
    case 2:
        return QPixmap(":/resources/car3.png");
    case 3:
        return QPixmap(":/resources/lorry.png");
    case 4:
        return QPixmap(":/resources/bus.png");
    case 5:
        return QPixmap(":/resources/motorbike.png");
    default:
        return QPixmap(":/resources/car1.png");

    }

}
