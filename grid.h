#ifndef GRID_H
#define GRID_H

#include <QtGlobal>
#include <QVector>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "cell.h"

class Grid : public QGraphicsItem
{
public:
    Grid();
    Grid(int cell_size, int sceneWidth, int sceneHeight);
    ~Grid();

    static const int CELL_SIZE = 50;
    int NUM_CELLS;

    int sceneWidth;
    int sceneHeight;
private:
    int computeNumberOfCells(int axis);
    QVector<QVector<Cell*>> cells;
    Cell* getCellCoords(int x, int y);
    Vector2D getPositionInsideCell(Vector2D& p);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    QRectF boundingRect(void) const;
};

#endif // GRID_H
