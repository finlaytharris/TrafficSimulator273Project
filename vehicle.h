#ifndef VEHICLE_H
#define VEHICLE_H

#include <QGraphicsPixmapItem>
#include<QPixmap>


class Vehicle:  public QGraphicsPixmapItem
{

public:
    Vehicle(QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;



    void setDirection(qreal x, qreal y); // set the direction of the vehicle
    void setPosition(qreal x, qreal y); // set the position of the vehicle
    void move(); // move the vehicle
    QPixmap generateImage() const;



private:
    qreal direction_x;
    qreal direction_y;
    QTimer* timer;

};

#endif // VEHICLE_H
