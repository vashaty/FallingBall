#include "ball.h"

Ball::Ball(QWidget *parent):parent(parent)
{
    QRect rect = parent->rect();
    x = rect.width()/2;
    y = 0;

    kx = 1;
    ky = 1;

    start(10);


}

void Ball::draw(QPainter *painter)
{
    painter->drawEllipse(x,y,20,20);
}

void Ball::timerEvent(QTimerEvent *e)
{
    QRect rect = parent->rect();
    if(x<0 || x > rect.width()) kx *= -1;

//    if(y<0 || y > rect.height()) ky *= -1;

//    x+=kx;
    y+=ky;

    parent->update();

}
