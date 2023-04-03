/*
   Name of Project: Traffic Simulator
   Module Name: Intersection Header
   Last Update: 11/03/23 - changed to inherit from QGraphicsItem rather than GraphicsScene in order to
                                correctly display on GraphicsScene
    Author: Finlay Harris

*/

#ifndef INTERSECTION_H
#define INTERSECTION_H

#include<QGraphicsItem>

#include"roadmiddle.h"
#include"roadsegment.h"



class Intersection :  public QGraphicsItem
{
public:
    Intersection(QGraphicsItem *parent = nullptr);



    // Inherited from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QRectF m_boundingRect;
    RoadSegment *horizontalRoad1;
    RoadSegment *horizontalRoad2;
    RoadSegment *verticalRoad1;
    RoadSegment *verticalRoad2;
    RoadMiddle *roadMiddle;

};
#endif // INTERSECTION_H
