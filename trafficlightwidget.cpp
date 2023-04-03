/*
   Name of Project: Traffic Simulator
   Module Name: TrafficLightWidget Source File
   Last Update: 22/03/23 - changed to a horizontal box layout
   Author: Finlay Harris

*/


#include "trafficlightwidget.h"

#include<QHBoxLayout>
#include<QTimer>
#include<QWidget>
#include<QtStateMachine/QFinalState>

//code taken & modified from https://doc.qt.io/qt-6/qtstatemachine-statemachine-trafficlight-example.html
//ASK ABOUT WHETHER THIS IS OKAY??
TrafficLightWidget::TrafficLightWidget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *hbox = new QHBoxLayout(this);
    m_red = new LightWidget(Qt::red);
    hbox->addWidget(m_red);
    m_yellow = new LightWidget(Qt::yellow);
    hbox->addWidget(m_yellow);
    m_green = new LightWidget(Qt::green);
    hbox->addWidget(m_green);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    setPalette(pal);
    setAutoFillBackground(true);
}

