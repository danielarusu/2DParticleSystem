#ifndef CELL_H
#define CELL_H

#include <QtGlobal>
#include <QVector>
#include <QGraphicsItem>
#include <QPainter>

#include "particle.h"

class Cell
{
    friend class Grid;
public:
    Cell();
    Cell(int x, int y);
    ~Cell();
    int xCoord;
    int yCoord;
private:
    QVector<Particle*> particles;
    void addParticle(Particle& p);
    void deleteParticle(Particle& p);
    void paint(QPainter *painter);

};

#endif // CELL_H
