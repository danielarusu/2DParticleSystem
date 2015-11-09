#include "particle.h"

void Particle::computeSize()
{
    if(mass >= 1 && mass <=200)
    {
        size = 20;
    }
    else if(mass > 200 && mass < 550)
    {
        size = 50;
    }
}

Particle::Particle(){
   position.setX(0.0);
   position.setY(0.0);
   mass = 5;
   r = 1; g = 1; b = 0;

   computeSize();
}

Particle::Particle(double x, double y){
    position.setX(x);
    position.setY(y);
    //mass = qrand()%(4*(int)solarMass);
    mass = qrand()%500 + 10;
    //r = 0; g = 0; b = 0;
    r = qrand()%200;
    g = qrand()%200;
    b = qrand()%200;
    //velocity.setX((qrand() % 1000) / 100);
    //velocity.setY((qrand() % 1000) / 100);

    computeSize();
}

Particle::Particle(Particle &p){
    position.setX(p.position.getX());
    position.setY(p.position.getY());
}

Particle::Particle(bool fixed)
{
    this->fixed = fixed;
    this->mass = 10000;
    this->size = 90;
    this->position.setX(1.0);
    this->position.setY(1.0);
    r = 255; g = 165; b = 0;
}

Particle::~Particle(){
}

void Particle::paint(QPainter *painter)
{
    QPen paintPen(QColor(r, g, b, 255));
    QBrush paintBrush(QColor(r, g, b, 255));

    paintPen.setWidth(1);
    painter->setPen(paintPen);
    painter->setBrush(paintBrush);
    painter->drawEllipse(position.getX(), position.getY(), size, size);

    velocity.add(velocity_inst);

//    qDebug() << this;
//    qDebug() << " X = " << velocity_inst.getX();
//    qDebug() << " Y = " << velocity_inst.getY();

//    if(velocity.magnitude() > 20){
//        velocity.normalise();
//        velocity *= 20;
//    }

    if (!fixed)
    {
        position.add(velocity);
    }

    force.clear();
    velocity_inst.clear();
}

