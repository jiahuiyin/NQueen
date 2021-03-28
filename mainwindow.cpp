#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("N皇后问题");
    chessboard=nullptr;
    n=0;
    ui->spinBox->setValue(8);
    ui->comboBox->addItem("爬山法");
    ui->comboBox->addItem("最小冲突");
    ui->comboBox->addItem("遗传算法");
    chessboard=new Chessboard(8);
    base=nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    int length=20;
    for(int i=0;i<=n;i++){
       painter.setPen(QPen(Qt::blue, 3));
       painter.drawLine(100+i*length,100,100+i*length,100+n*length);
       painter.drawLine(100,100+i*length,100+n*length,100+i*length);
       if(i==n)break;
       painter.setPen(QPen(Qt::red, 3));
       painter.setBrush(QBrush(Qt::red));
       if(chessboard!=nullptr&&chessboard->solved==true)
       painter.drawEllipse(106+i*length,106+length*chessboard->board[i],10,10);

    }
    painter.end();
}

void MainWindow::on_pushButton_clicked()
{
    if(chessboard!=nullptr)delete chessboard;
    n=ui->spinBox->value();
    chessboard=new Chessboard(n);
    if(n>15)
    setFixedSize(200+20*n,200+20*n);
    update();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(base!=nullptr)delete base;
    if(chessboard->solved==true)
    on_pushButton_clicked();
    switch (ui->comboBox->currentIndex()) {
    case 0:
        base=new ClimbHill(chessboard);
        break;
    case 1:
        base=new MinConflict(chessboard);
        break;
    case 2:
        base=new Genetic(chessboard);
        break;
    }
    QElapsedTimer t;
    t.start();
    base->solve();
    QString s=QString("时间：")+QString::number(t.elapsed())+QString("ms");
    ui->label_3->setText(s);
    update();
}
