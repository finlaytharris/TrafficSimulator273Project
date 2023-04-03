/*
   Name of Project: Traffic Simulator
   Module Name: LightWidget Header
   Last Update: 21/03/23 - Example followed from Qt documentation
   Author: Finlay Harris

*/


#ifndef LIGHTWIDGET_H
#define LIGHTWIDGET_H

#include <QWidget>
#include<QPainter>

//code taken & modified from https://doc.qt.io/qt-6/qtstatemachine-statemachine-trafficlight-example.html
class LightWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool on READ isOn WRITE setOn)
public:
    LightWidget(const QColor &color, QWidget *parent = nullptr);

    bool isOn() const;

    void setOn(bool on);

public slots:
    void turnOff();
    void turnOn();

protected:
    void paintEvent(QPaintEvent *);

private:
    QColor m_color;
    bool m_on;
};

#endif // LIGHTWIDGET_H
