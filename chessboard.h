#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QVector>
#include <QRandomGenerator>
class Chessboard
{
public:
    int n;
    Chessboard(int n);
    void reset();
    QVector<int> board;
    bool solved=false;
};

#endif // CHESSBOARD_H
