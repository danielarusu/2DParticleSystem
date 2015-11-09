#include "cell.h"

Cell::Cell()
{
    xCoord = 0.0;
    yCoord = 0.0;
}

Cell::Cell(int x, int y)
{
    this->xCoord = x;
    this->yCoord = y;
}

Cell::~Cell()
{

}

void Cell::paint(QPainter *painter)
{
    QPen paintPen(QColor(0, 0, 0, 20));
    QBrush paintBrush(QColor(0, 0, 0, 20));

    paintPen.setWidth(1);
    painter->setPen(paintPen);
    painter->drawRect(xCoord, yCoord, 50, 50);

}

