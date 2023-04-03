/*
   Name of Project: Traffic Simulator
   Module Name: RoadMiddle Header
   Last Update: 10/03/23 - defined class
   Author: Finlay Harris

*/

#ifndef ROADMIDDLE_H
#define ROADMIDDLE_H

#include<QPainter>
#include<QGraphicsItem>

class RoadMiddle : public QGraphicsItem
{
public:
    RoadMiddle(QGraphicsItem *parent = nullptr, const QRectF &rect= QRectF(-150, -10, 50, 50));
    QRectF boundingRect() const override;  //first virtual function needed for custom QGraphicsItem- returns an estimate of the area painted by the item
                                           //overrise shows function is virtual
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
         //second virtual function needed for custom QGraphicsItem- implements the actual painting

private:
    QRectF m_rect;

};

#endif // ROADMIDDLE_H
