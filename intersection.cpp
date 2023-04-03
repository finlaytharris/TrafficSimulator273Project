/*
   Name of Project: Traffic Simulator
   Module Name: Intersection Source File
   Last Update: 11/03/23 - Changed the positions of the roads
   Author: Finlay Harris

*/

#include "intersection.h"

Intersection::Intersection(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    {
            // create the first horizontal road
            horizontalRoad1 = new RoadSegment(this, QRectF(0, 0, 250, 80), 0);
            horizontalRoad1->setPos(-16, 255); // move the horizontal road to the left and center vertically
            horizontalRoad1->setParentItem(this);

            // create the first vertical road
            verticalRoad1 = new RoadSegment(this, QRectF(0, 0, 80, 255), M_PI/2);
            verticalRoad1->setRotation(180); // set rotation to 90 degrees
            verticalRoad1->setPos(312, 255); // move the vertical road up and center horizontally
            verticalRoad1->setParentItem(this);

            // create the second horizontal road
            horizontalRoad2 = new RoadSegment(this, QRectF(0, 0, 250, 80), 0);
            horizontalRoad2->setPos(310, 255); // move the horizontal road to the right and center vertically
            horizontalRoad2->setParentItem(this);

            // create the second vertical road
            verticalRoad2 = new RoadSegment(this, QRectF(0, 0, 80, 255), M_PI/2);
            verticalRoad2->setRotation(180); // set rotation to 90 degrees
            verticalRoad2->setPos(312, 588); // move the vertical road down and center horizontally
            verticalRoad2->setParentItem(this);

            // create the square in the middle for the intersection area
            roadMiddle = new RoadMiddle(this, QRectF(0, 0, 80, 80));
            roadMiddle->setPos(230, 255); // center the road middle at the intersection
            roadMiddle->setParentItem(this);
    }

}


QRectF Intersection::boundingRect() const
{
     return m_boundingRect;
}

void Intersection::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter); // to get rid of warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

}


