#ifndef BALL_H
#define BALL_H

#include <QTimer>
#include <QWidget>
#include <QPainter>

class Ball : public QTimer
{
public:
    Ball(QWidget *parent);
    void draw(QPainter *painter);

protected:
    virtual void timerEvent(QTimerEvent *e) override;

    int x, y, kx, ky;
    QWidget *parent;
};

#endif // BALL_H
