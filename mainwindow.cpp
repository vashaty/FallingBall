#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&timer, &QTimer::timeout,this, &MainWindow::onTimer);
    timer.setSingleShot(false);
    timer.start(4000);
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
}

void MainWindow::on_actionAdd_triggered()
{
    balls.append(std::shared_ptr<Ball>(new Ball(this)));
}

void MainWindow::on_actionRemove_triggered()
{
    balls.removeFirst();
    update();
}

void MainWindow::on_actionClear_triggered()
{
    balls.clear();
    update();
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
