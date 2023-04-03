/*
   Name of Project: Traffic Simulator
   Module Name: TrafficLight Header
   Last Update: 22/03/23 - changed constructor to include duration variables & private attributes were added
   Author: Finlay Harris

*/


#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QWidget>
#include<QtStateMachine/QStateMachine>

#include"lightwidget.h"

//code taken & modified from https://doc.qt.io/qt-6/qtstatemachine-statemachine-trafficlight-example.html
class TrafficLight : public QWidget
{
public:
    TrafficLight(int duration1 = 6000, int duration2 = 1000, bool setGreen = false);
    QState* createLightState(LightWidget* light, int duration, QState* parent = nullptr);

private:
    int m_duration1;
    int m_duration2;
    bool m_setGreen;

};

#endif // TRAFFICLIGHT_H
