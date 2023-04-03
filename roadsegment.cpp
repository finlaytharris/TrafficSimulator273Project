/*
   Name of Project: Traffic Simulator
   Module Name: RoadSegment Source File
   Last Update: 10/03/23 - defined all 3 methods
   Author: Finlay Harris

*/


#include "roadsegment.h"


RoadSegment::RoadSegment(QGraphicsItem *parent,const QRectF &rect, qreal rotation)
                         : QGraphicsItem(parent)
                         , m_rect(rect)
                         , m_rotation(rotation)
                     {
                         // set bounding rectangle and rotation of the road segment
                         m_rect = rect;
                         setRotation(rotation);




}


QRectF RoadSegment::boundingRect() const
{
    return m_rect;
}

void RoadSegment::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);


    // drawing the road rectangle
    painter->setBrush(Qt::darkGray);
    painter->drawRect(m_rect);

    // drawing the center line
    QPen pen2(Qt::white, 2);
    pen2.setDashPattern({2, 2}); //makes it a dashed line
    painter->setPen(pen2);

   if (m_rotation == 0) { // draws and postions the white dashed lines
        painter->drawLine(QPointF(m_rect.left(), m_rect.center().y()), QPointF(m_rect.right(), m_rect.center().y()));
    } else {
        painter->drawLine(QPointF(m_rect.center().x(), m_rect.top()), QPointF(m_rect.center().x(), m_rect.bottom()));
    }

    painter->restore();
}

