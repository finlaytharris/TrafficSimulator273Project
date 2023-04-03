/*
   Name of Project: Traffic Simulator
   Module Name: RoadSegment Header
   Last Update: 10/03/23 - defined class
   Author: Finlay Harris

*/

#ifndef ROADSEGMENT_H
#define ROADSEGMENT_H

#include<QPainter>
#include<QGraphicsItem>

class RoadSegment : public QGraphicsItem
{
public:
    RoadSegment(QGraphicsItem *parent = nullptr, const QRectF &rect = QRectF(-150, -10, 300, 20), qreal rotation = 0);
        //1st param: when construc called with no parameter, no parent set for new widget (i.e it isnt a parent)
        //2nd param: of type rectangle widget, constant- shouldnt change
        //3rd param: setting rotation to 0, qreal = double type (unless on a CPU that uses RISC)

    QRectF boundingRect() const override;  //first virtual function needed for custom QGraphicsItem- returns an estimate of the area painted by the item
                                           //overrise shows function is virtual
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
         //second virtual function needed for custom QGraphicsItem- implements the actual painting


private:
    QRectF m_rect;
    qreal m_rotation;
};

#endif // ROADSEGMENT_H
