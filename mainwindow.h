#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>

#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QColor>
#include <QPointF>
#include <QVector>
#include <QList>
#include <QTimer>

#include "particle.h"
#include "vector2d.h"
#include "updateparticles.h"
#include "grid.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addParticle_btn_clicked();
    void mousePressEvent(QMouseEvent * e);
    void on_addHighMassParticle_btn_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsScene *mainScene;
    UpdateParticles* particles;
    Grid* grid;

    void addParticle(int xCoord, int yCoord);
    void getViewDimensions();

    QPointF getMousePosition();
    int getRandomAxis(int axisSize);

    int sceneWidth;
    int sceneHeight;
};

#endif // MAINWINDOW_H
