#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&timer, &QTimer::timeout,this, &MainWindow::onTimer);
    timer.setSingleShot(false);
    timer.start(spawnInterval);

    QObject::connect(&timer2, &QTimer::timeout,this, &MainWindow::onTimer2);
    timer2.setSingleShot(false);
    timer2.start(1);
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
    balls.append(std::shared_ptr<Ball>(new Ball(this,basket)));
}

//void MainWindow::removeBall()
//{
//    balls.removeFirst();
//    update();
//}

//void MainWindow::clearBalls()
//{
//    balls.clear();
//    update();
//}

void MainWindow::onTimer(){
    newBall();
}

void MainWindow::onTimer2(){
    for (const std::shared_ptr<Ball> &sp:balls) {
        if(sp->catched){
            ui->label_2->setText(QString::number(ui->label_2->text().toInt()+1));
            if((ui->label_2->text().toInt() % 2) == 0 && ui->label_2->text().toInt() != 0){
                if(spawnInterval>500){
                    spawnInterval /= 2;
                    timer.start(spawnInterval);
                }
            }
        }
        if(sp->catched || sp->isOut){
            balls.remove(balls.indexOf(sp));
            break;
        }

    }

//    if(!balls.isEmpty() && balls.first()->isOut == true)
//        removeBall();
//    if(!balls.isEmpty() && balls.first()->catched == true){
//        removeBall();

//        ui->label_2->setText(QString::number(ui->label_2->text().toInt()+1));
//        if((ui->label_2->text().toInt() % 2) == 0 && ui->label_2->text().toInt() != 0){
//            spawnInterval /= 2;
//            timer.start(spawnInterval);
//        }
//    }

}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Left:
        if(basket->x-basket->moveStep >= 0){
            basket->x-=basket->moveStep;
            update();
        }
        break;
    case Qt::Key_Right:
        if(basket->x+basket->moveStep+basket->width <= 800){
            basket->x+=basket->moveStep;
            update();
        }
        break;
    }
}
