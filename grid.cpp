#include "grid.h"
Grid::Grid()
{

}

Grid::Grid(int cell_size, int sceneWidth, int sceneHeight)
{
    NUM_CELLS = computeNumberOfCells(sceneWidth) * computeNumberOfCells(sceneHeight);
    int numX = computeNumberOfCells(sceneWidth);
    int numY = computeNumberOfCells(sceneHeight);

    for(int i = 0; i < numX; i++){
        QVector<Cell*> line;
        line.resize(numY);
        for(int j = 0; j < numY; j++){
            line[j] = new Cell(i*cell_size - (int)(sceneWidth / 2), j*cell_size - (int)(sceneHeight / 2));
        }
        cells.push_back(line);
    }
}

Grid::~Grid()
{

}

int Grid::computeNumberOfCells(int axis)
{
    return (int)(axis / CELL_SIZE) + 5 ;
}

Cell *Grid::getCellCoords(int x, int y)
{
    return cells[x][y];
}

Vector2D Grid::getPositionInsideCell(Vector2D &p)
{
    return {p.getX() / CELL_SIZE , p.getY() / CELL_SIZE};
}

void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(QVector<QVector<Cell*>>::iterator it_m = cells.begin(); it_m != cells.end(); ++it_m){
        for(QVector<Cell*>::iterator it_v = it_m->begin(); it_v != it_m->end(); ++it_v){
            (*it_v)->paint(painter);
        }
    }
}

QRectF Grid::boundingRect() const
{
    return QRectF(0, 0, 0, 0);
}
