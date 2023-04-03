/*
   Name of Project: Traffic Simulator
   Module Name: SimulationScene Source File
   Last Update: 22/03/23 -traffic lights added to scene
   Author: Finlay Harris

*/


#include "simulationscene.h"
#include"intersection.h"
#include"trafficlight.h"
#include"vehicle.h"

#include<QGraphicsProxyWidget>
#include <QList>
#include<QTimer>


SimulationScene::SimulationScene(int duration1, int duration2) //: QGraphicsScene(parent)
{
            m_duration1 = duration1;
            m_duration2 = duration2;
            // set the scene size
            setSceneRect(10, 0, 500, 560);

            // add the intersection item to the scene
            Intersection* intersection = new Intersection();
            intersection->setZValue(-100);
            addItem(intersection);

            // creates 4 instances of a traffic light
            TrafficLight* t1 = new TrafficLight(duration1, duration2,false);
            TrafficLight* t2 = new TrafficLight(duration1, duration2,true);
            TrafficLight* t3 = new TrafficLight(duration1, duration2,true);
            TrafficLight* t4 = new TrafficLight(duration1, duration2,false);

            // defining list of traffic light
            //QList<QGraphicsProxyWidget> trafficLights;

            // sets each traffic light as a proxy widget to allow for traffic light to be added to graphics scene
            QGraphicsProxyWidget *proxyItem1 = new QGraphicsProxyWidget;
            proxyItem1->setWidget(t1);
            proxyItem1->setPos(150, 205);
            proxyItem1->setZValue(0);
            //trafficLights.append(proxyItem1);
            addItem(proxyItem1);

            QGraphicsProxyWidget *proxyItem2 = new QGraphicsProxyWidget;
            proxyItem2->setWidget(t2);
            //trafficLights.append(proxyItem2);
            proxyItem2->setPos(320, 205);
            proxyItem2->setZValue(0);
            addItem(proxyItem2);

            QGraphicsProxyWidget *proxyItem3 = new QGraphicsProxyWidget;
            proxyItem3->setWidget(t3);
            proxyItem3->setPos(150, 340);
            proxyItem3->setZValue(0);
            //trafficLights.append(proxyItem3);
            addItem(proxyItem3);

            QGraphicsProxyWidget *proxyItem4 = new QGraphicsProxyWidget;
            proxyItem4->setWidget(t4);
            proxyItem4->setPos(320, 340);
            proxyItem4->setZValue(0);
           // trafficLights.append(proxyItem4);
            addItem(proxyItem4);

//            timer = new QTimer(this);
//            timer->setInterval(50); // Update every 50 milliseconds
//            connect(timer, &QTimer::timeout,this , &Vehicle::move);
//            timer->start();

            //add the vehicle item to the scene
            Vehicle *test= new Vehicle;
            test->setPosition(210,40);
            //test->setRotation(180);
            test->setZValue(100);
            addItem(test);
}

