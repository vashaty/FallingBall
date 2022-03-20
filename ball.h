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

    /*!
     * Promenne, ktere drzi souradnice a soradnice posunu micku
     */
    int x, y, kx, ky;

    /*!
     * Boolean, ktery uchovava zda je micek mimo okno (pod palkou)
     */
    bool isOut = false;

    /*!
     * Boolean, ktery uchovava zda byl micek chycen
     */
    bool catched = false;

protected:
    virtual void timerEvent(QTimerEvent *e) override;

    QWidget *parent;

private:
    Basket *basket;
};

#endif // BALL_H
