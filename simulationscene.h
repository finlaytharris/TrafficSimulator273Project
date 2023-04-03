/*
   Name of Project: Traffic Simulator
   Module Name: SimulationScene Header
   Last Update: 22/03/23 - added private attributes and changed constructors parameters
   Author: Finlay Harris

*/


#ifndef SIMULATIONSCENE_H
#define SIMULATIONSCENE_H

#include<QGraphicsScene>

class SimulationScene : public QGraphicsScene //inherits graphic scene class - creates a scene for the scene object
{
public:
    SimulationScene(int duration1 = 5000, int duration2 = 1000);

private:
    int m_duration1;
    int m_duration2;
    QTimer* timer;
};

#endif // SIMULATIONSCENE_H
