#ifndef UPDATEPARTICLES_H
#define UPDATEPARTICLES_H

#include <QVector>
#include <QMainWindow>
#include <QDebug>

#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QVector>
#include <QList>
#include <QTimer>

#include "particle.h"
const double G = 0.001;// 6.67384e-6;
class UpdateParticles : public QGraphicsItem
{
public:
    UpdateParticles();
    ~UpdateParticles();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    QRectF boundingRect(void) const;
    friend class MainWindow;
private:
    float gravity(Particle& p1, Particle& p2);
    QVector<Particle*> particleArray;
    QVector<Particle*>::iterator it;
    QGraphicsScene* scene;

    int sceneWidth;
    int sceneHeight;
};

#endif // UPDATEPARTICLES_H
