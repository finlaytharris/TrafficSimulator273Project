/*
   Name of Project: Traffic Simulator
   Module Name: MainWindow Header
   Last Update: 02/03/23 - changed names of the two buttons on the ui- updated the functions accordingly
    Author: Finlay Harris

*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"mainwindow2.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); //constructor & destructor
    ~MainWindow();


private slots:

    void on_StartButton_clicked(); //slots for buttons on ui

    void on_QuitButton_clicked();


private:
    Ui::MainWindow *ui;
    MainWindow2 *mainWindow2;
};
#endif // MAINWINDOW_H
