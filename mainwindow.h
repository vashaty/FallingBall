#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "ball.h"
#include <memory>
#include <QTimer>
#include "basket.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    QTimer timer;
    QTimer timer2;

private slots:
    void onTimer();
    void onTimer2();

private:
    Ui::MainWindow *ui;
    QList<std::shared_ptr<Ball>> balls;
    Basket *basket = new Basket(this);
    int spawnInterval = 4000;
    void newBall();

    void removeBall();

    void clearBalls();
};
#endif // MAINWINDOW_H
