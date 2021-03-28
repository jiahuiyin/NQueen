#ifndef BASEALGORITHM_H
#define BASEALGORITHM_H
#include "chessboard.h"


class BaseAlgorithm
{
public:
    BaseAlgorithm(Chessboard *chessboard);
    virtual void solve()=0;
    virtual ~BaseAlgorithm(){};
protected:
    Chessboard *chessboard;
    int getConflictNum();
    int getConflictNum(QVector<int>&v);
};

#endif // BASEALGORITHM_H
