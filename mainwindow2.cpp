/*
   Name of Project: Traffic Simulator
   Module Name: MainWindow2 Source File
   Last Update: 22/03/23 - added trafficLightSlider_valueChanged function
   Author: Finlay Harris

*/

#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include"simulationscene.h"




MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new SimulationScene); //setting scene object created in SimulationScene class as the scene in the GraphicsView
    //ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
//ADD LAYOUT LIKE HORIZONTAL BOX LAYOUT SO RESIZES IN FULLSCREEN




}

MainWindow2::~MainWindow2()
{
    delete ui;
}


void MainWindow2::on_trafficLightSlider_valueChanged(int value)
{
    int duration1 = 5000;
    int duration2 = 1000;
    SimulationScene* sim = new SimulationScene(duration1+(value*100),duration2+(value*100));
    ui->graphicsView->setScene(sim);

}

