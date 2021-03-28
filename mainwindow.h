#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "climbhill.h"
#include "chessboard.h"
#include <QPainter>
#include "minconflict.h"
#include "basealgorithm.h"
#include "genetic.h"
#include <QElapsedTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::MainWindow *ui;
    BaseAlgorithm *base;
    Chessboard *chessboard;
    int n;
};
#endif // MAINWINDOW_H
