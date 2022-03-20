#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "ball.h"
#include <memory>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    QTimer timer;

private slots:
    void on_actionAdd_triggered();

    void on_actionRemove_triggered();

    void on_actionClear_triggered();
    void onTimer();

private:
    Ui::MainWindow *ui;
    QList<std::shared_ptr<Ball>> balls;
    void newBall();

    void removeBall();

    void clearBalls();
};
#endif // MAINWINDOW_H
