#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&timer, &QTimer::timeout,this, &MainWindow::onTimer);
    timer.setSingleShot(false);
    timer.start(1000);

    QObject::connect(&timer2, &QTimer::timeout,this, &MainWindow::onTimer2);
    timer2.setSingleShot(false);
    timer2.start(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter ptr(this);
    ptr.fillRect(rect(), QBrush(QColor(Qt::white)));
    ptr.setPen(Qt::black);
    ptr.setBrush(QBrush(QColor(Qt::blue)));

    for (auto sp:balls) {
        sp->draw(&ptr);
    }

    ptr.setPen(Qt::white);
    ptr.setBrush(QBrush(QColor(Qt::red)));

    basket->draw(&ptr);

}


void MainWindow::newBall()
{
    balls.append(std::shared_ptr<Ball>(new Ball(this)));
}

void MainWindow::removeBall()
{
    balls.removeFirst();
    update();
}

void MainWindow::clearBalls()
{
    balls.clear();
    update();
}

void MainWindow::onTimer(){
    newBall();
}

void MainWindow::onTimer2(){
    if(!balls.isEmpty() && balls.first()->isOut == true)
        removeBall();
}
