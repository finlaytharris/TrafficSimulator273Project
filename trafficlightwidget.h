/*
   Name of Project: Traffic Simulator
   Module Name: TrafficLightWidget Header
   Last Update: 21/03/23 - Example followed from Qt Documentation
   Author: Finlay Harris

*/


#ifndef TRAFFICLIGHTWIDGET_H
#define TRAFFICLIGHTWIDGET_H


#include<QtStateMachine/QStateMachine>
#include"lightwidget.h"

//code taken from https://doc.qt.io/qt-6/qtstatemachine-statemachine-trafficlight-example.html
class TrafficLightWidget : public QWidget
{
public:
    TrafficLightWidget(QWidget *parent = nullptr);


    LightWidget *redLight() const
        { return m_red; }
    LightWidget *yellowLight() const
        { return m_yellow; }
    LightWidget *greenLight() const
        { return m_green; }

private:
    LightWidget *m_red;
    LightWidget *m_yellow;
    LightWidget *m_green;
};
#endif // TRAFFICLIGHTWIDGET_H
