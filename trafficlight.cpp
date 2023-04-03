/*
   Name of Project: Traffic Simulator
   Module Name: TrafficLight Source File
   Last Update: 22/03/23 - changed to a horizontal box layout
                         - added functionality to change intial state
                         - changed constructor parameters
   Author: Finlay Harris

*/


#include "trafficlight.h"
#include"trafficlightwidget.h"

#include<QHBoxLayout>
#include<QTimer>
#include<QtStateMachine/QFinalState>

//code taken & modified from https://doc.qt.io/qt-6/qtstatemachine-statemachine-trafficlight-example.html
TrafficLight::TrafficLight(int duration1, int duration2, bool setGreen)

{
    m_duration1 = duration1;
    m_duration2 = duration2;
    m_setGreen = setGreen;

    QHBoxLayout *hbox = new QHBoxLayout(this);
    TrafficLightWidget *widget = new TrafficLightWidget;
    widget->setFixedSize(75,45);
    hbox->addWidget(widget);
    hbox->setContentsMargins(QMargins());

    QStateMachine *machine = new QStateMachine(this);
    QState *redGoingYellow = createLightState(widget->redLight(), duration1);
    redGoingYellow->setObjectName("redGoingYellow");
    QState *yellowGoingGreen = createLightState(widget->yellowLight(), duration2);
    yellowGoingGreen->setObjectName("yellowGoingGreen");
    redGoingYellow->addTransition(redGoingYellow, &QState::finished, yellowGoingGreen);
    QState *greenGoingYellow = createLightState(widget->greenLight(), duration1);
    greenGoingYellow->setObjectName("greenGoingYellow");
    yellowGoingGreen->addTransition(yellowGoingGreen, &QState::finished, greenGoingYellow);
    QState *yellowGoingRed = createLightState(widget->yellowLight(), duration2);
    yellowGoingRed->setObjectName("yellowGoingRed");
    greenGoingYellow->addTransition(greenGoingYellow, &QState::finished, yellowGoingRed);
    yellowGoingRed->addTransition(yellowGoingRed, &QState::finished, redGoingYellow);

    machine->addState(redGoingYellow);
    machine->addState(yellowGoingGreen);
    machine->addState(greenGoingYellow);
    machine->addState(yellowGoingRed);

    if(setGreen == false) {
         machine->setInitialState(redGoingYellow);
    }
    else if(setGreen == true) {
        machine->setInitialState(greenGoingYellow);
    }
    machine->start();


}

QState* TrafficLight::createLightState(LightWidget* light, int duration, QState* parent)
{
    QState *lightState = new QState(parent);
    QTimer *timer = new QTimer(lightState);
    timer->setInterval(duration);
    timer->setSingleShot(true);
    QState *timing = new QState(lightState);
    QObject::connect(timing, &QAbstractState::entered, light, &LightWidget::turnOn);
    QObject::connect(timing, &QAbstractState::entered, timer, QOverload<>::of(&QTimer::start));
    QObject::connect(timing, &QAbstractState::exited, light, &LightWidget::turnOff);
    QFinalState *done = new QFinalState(lightState);
    timing->addTransition(timer, &QTimer::timeout, done);
    lightState->setInitialState(timing);
    return lightState;
}



