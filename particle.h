#ifndef PARTICLE_H
#define PARTICLE_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QtGlobal>
#include <QColor>
#include <QDebug>
#include <QList>

#include "vector2d.h"

//const double G = 6.67384e-11;
const double solarMass = 1.9885e30;

//double originalMass = 10;//solarMass / 10;

class Particle
{
private:
    int* QtColours;
    QColor Color;
    int size;
    int r; int b; int g;

    void computeSize();
public:
    Particle();
    Particle(double x, double y);
    Particle(Particle& p);
    Particle(bool fixed);
    Vector2D position;
    double mass;
    Vector2D force;
    Vector2D velocity;
    Vector2D velocity_inst;
    bool fixed = false;
    void paint(QPainter *painter);
    ~Particle();
    friend class MainWindow;
};

#endif // PARTICLE_H
