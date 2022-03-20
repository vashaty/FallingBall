#include "basket.h"

Basket::Basket(QWidget *parent):parent(parent)
{
    QRect rect = parent->rect();
    width = 150;
    height = 20;
    x = rect.width()/2;
    y = rect.height();

}

void Basket::draw(QPainter *painter)
{
    painter->drawRect(x,y,width,height);
}


