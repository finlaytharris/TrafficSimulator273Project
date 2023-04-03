/*
   Name of Project: Traffic Simulator
   Module Name: RoadMiddle Source File
   Last Update: 10/03/23 - defined all 3 methods
   Author: Finlay Harris

*/

#include "roadmiddle.h"

RoadMiddle::RoadMiddle(QGraphicsItem *parent, const QRectF &rect)
                        : QGraphicsItem(parent)
                        , m_rect(rect)
{
     m_rect = rect;

}

QRectF RoadMiddle::boundingRect() const
{
    return m_rect;
}


void RoadMiddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // setting the pen color and width
    QPen pen(Qt::darkGray, 1);

    // drawing the road intersection square
    painter->setPen(pen);
    painter->setBrush(Qt::darkGray);
    painter->drawRect(m_rect);
}
