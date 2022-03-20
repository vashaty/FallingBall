#include "basket.h"

Basket::Basket(QWidget *parent):parent(parent)
{
    QRect rect = parent->rect();
    x = rect.width()/2+40;
    y = rect.height();
    width = 80;
    height = 20;

//    kx = rand()%5;
//    ky = 1;

////    start(10);


}

void Basket::draw(QPainter *painter)
{
    painter->drawRect(x,y,width,height);
}

void Basket::timerEvent(QTimerEvent *e)
{
//    QRect rect = parent->rect();
//    if(x<0 || x > rect.width()) kx *= -1;

////    if(y<0 || y > rect.height()) ky *= -1;

//    x+=kx;
//    y+=ky;

//    parent->update();

}

