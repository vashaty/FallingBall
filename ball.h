#ifndef BALL_H
#define BALL_H

#include <QTimer>
#include <QWidget>
#include <QPainter>
#include "basket.h"

class Ball : public QTimer
{
public:
    Ball(QWidget *parent, Basket *basket);
    void draw(QPainter *painter);
//    void setBasket(Basket *basket);
    int x, y, kx, ky;
    bool isOut = false;
    bool catched = false;

protected:
    virtual void timerEvent(QTimerEvent *e) override;

    QWidget *parent;

private:
    Basket *basket;
};

#endif // BALL_H
