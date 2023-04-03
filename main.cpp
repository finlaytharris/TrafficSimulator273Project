/*
   Name of Project: Traffic Simulator
   Module Name: Main Source File
   Last Update: n/a (Qt automatically produces this)
   Author: Qt

*/

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
