/*
   Name of Project: Traffic Simulator
   Module Name: LightWidget Source File
   Last Update: 21/03/23 - Example followed from Qt Documentation
   Author: Finlay Harris

*/

#include "lightwidget.h"

//code taken & modified from https://doc.qt.io/qt-6/qtstatemachine-statemachine-trafficlight-example.html
LightWidget::LightWidget(const QColor &color, QWidget *parent)
    :QWidget(parent), m_color(color), m_on(false) {}

bool LightWidget::isOn() const
{
    return m_on;
}

void LightWidget::setOn(bool on)
{
    if (on == m_on)
       return;
    m_on = on;
    update();

}

void LightWidget::turnOff()
{
    setOn(false);
}
void LightWidget::turnOn()
{
    setOn(true);
}

void LightWidget::paintEvent(QPaintEvent *)
{
    if (!m_on)
        return;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(m_color);
    painter.drawEllipse(0, 0, width(), height());
}
