/*
   Name of Project: Traffic Simulator
   Module Name: MainWndow Source File
   Last Update: 21/03/23 - Removed the connect methods as causing a bug of calling a function twice
   Author: Finlay Harris

*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/backgorund.png"); //setting pix equal to resource file path of image for menu
    int w = ui->label_img->width();
    int h = ui->label_img->height();
    ui->label_img->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio)); //resizing and applying to label added to mainWindow

}

MainWindow::~MainWindow() //destructor
{
    delete ui;
}

void MainWindow::on_StartButton_clicked() //function for when start button is clicked
{
    hide(); //hides the first main window
    mainWindow2 = new MainWindow2(this);
    mainWindow2->show(); //shows new mainWindow2 object
}


void MainWindow::on_QuitButton_clicked() //function for when quit button is clicked
{
    this->close(); //closes current window
}

