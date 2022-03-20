#ifndef BASKET_H
#define BASKET_H

#include <QTimer>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>


class Basket : public QTimer
{
public:
    Basket(QWidget *parent);
    void draw(QPainter *painter);

    /*!
     * Promenne, ktere drzi souradnice, sirku a vysku kose
     */
    int x, y, width, height;

    /*!
     * Vzdalenost posunu kose
     */
    int moveStep = 20;

protected:
    QWidget *parent;


};

#endif // BASKET_H
