#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "particle.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainScene = new QGraphicsScene(this);
    ui->mainGraphicsView->setScene(mainScene);
    mainScene->setBackgroundBrush(QBrush(QColor(176, 176, 176, 255), Qt::SolidPattern));

    scene = new QGraphicsScene(this);
    ui->particleCanvas->setScene(scene);
   // ui->particleCanvas->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scene->setBackgroundBrush(QBrush(QColor(255, 248, 255, 255), Qt::SolidPattern));

    getViewDimensions();
    grid = new Grid(50, sceneWidth,sceneHeight);
    scene->addItem(grid);
    particles = new UpdateParticles();

    particles->sceneWidth = sceneWidth;
    particles->sceneHeight = sceneHeight;
    //grid->NUM_CELLS = computeNumberOfCells(sceneWidht) * computeNumberOfCells(sceneHeight);

    qDebug() << "Number of cells" << grid->NUM_CELLS;

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), scene, SLOT(update()));
    timer->start(5);

    qDebug() << "Height:" << sceneWidth;
    qDebug() << "Height:" << sceneHeight;
    scene->addItem(particles);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getViewDimensions()
{
    sceneWidth = ui->particleCanvas->width();
    sceneHeight = ui->particleCanvas->height();
}

void MainWindow::on_addParticle_btn_clicked()
{
    addParticle(getRandomAxis(sceneWidth), getRandomAxis(sceneHeight));
}

void MainWindow::addParticle(int xCoord, int yCoord)
{
    Particle* p = new Particle(xCoord, yCoord);

    particles->particleArray.push_back(p);
}

QPointF MainWindow::getMousePosition()
{
    QList<QGraphicsView *> view = this->scene->views();
    //qDebug() << view[0];
    QPointF point = view[0]->mapToParent(QCursor::pos());
    return point;
}

int MainWindow::getRandomAxis(int axisSize)
{
    return (qrand() % axisSize) - axisSize / 2;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QPointF point = ui->particleCanvas->mapToScene(e->pos());
    qDebug() << "Point 2" << point.x() << point.y();
    addParticle(point.x(), point.y());
    this->scene->update();
}

void MainWindow::on_addHighMassParticle_btn_clicked()
{
    Particle* p = new Particle(true);
    particles->particleArray.push_back(p);
}
