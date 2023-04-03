/*
   Name of Project: Traffic Simulator
   Module Name: MainWindow2 Header
   Last Update: 22/03/23 - added function defintion for when trafficLightSLider is moved
    Author: Finlay Harris

*/

#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include<QGraphicsScene>


namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private slots:
    void on_trafficLightSlider_valueChanged(int value);

private:
    Ui::MainWindow2 *ui;
    QGraphicsScene *scene; //creating a scene object

};

#endif // MAINWINDOW2_H
