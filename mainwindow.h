#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "ball.h"
#include <memory>
#include <QTimer>
#include "basket.h"
#include <QKeyEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyReleaseEvent(QKeyEvent *e) override;

protected:
    void paintEvent(QPaintEvent *event) override;

    /*!
     * Casovac pro vytvareni novych micku
     */
    QTimer timer;

    /*!
     * Casovac pro kontrolu a mazani micku (zda jej hrac chytil, pricteni bodu)
     */
    QTimer timer2;

private slots:

    /*!
     * Funkce casovace pro vytvareni novych micku
     */
    void onTimer();

    /*!
     * Funkce casovace pro kontrolu a mazani micku (zda jej hrac chytil, pricteni bodu)
     */
    void onTimer2();

private:
    Ui::MainWindow *ui;

    /*!
     * List, ktery v sobe drzi ukazatele na micky
     */
    QList<std::shared_ptr<Ball>> balls;

    /*!
     * Ukazatel kose (palky)
     */
    Basket *basket = new Basket(this);

    /*!
     * Interval, ve kterem se budou vytvaret micky
     */
    int spawnInterval = 4000;

    /*!
     * Vytvori novy micek
     */
    void newBall();

//    void removeBall();

//    void clearBalls();
};
#endif // MAINWINDOW_H
