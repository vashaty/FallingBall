#ifndef BASKET_H
#define BASKET_H

#include <QTimer>
#include <QWidget>
#include <QPainter>


class Basket : public QTimer
{
public:
    Basket(QWidget *parent);
    void draw(QPainter *painter);
        int x, y, kx, ky,width, height;

protected:
    virtual void timerEvent(QTimerEvent *e) override;

    QWidget *parent;

};

#endif // BASKET_H
