#include "ball.h"

Ball::Ball(QWidget *parent, Basket *basket):parent(parent)
{
    this->basket = basket;
    QRect rect = parent->rect();
    x = rect.width()/2;
    y = 0;

    kx = rand()%10-5;
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

    if(y == rect.height()) isOut = true;

    if (y == basket->y){
        for(int i = basket->x; i <= basket->x+basket->width; i++){
            if(i == x && y == basket->y){
                catched = true;
                break;
            }
        }
    }

    x+=kx;
    y+=ky;

    parent->update();

}
