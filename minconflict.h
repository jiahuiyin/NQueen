#ifndef MINCONFLICT_H
#define MINCONFLICT_H
#include "chessboard.h"
#include "basealgorithm.h"
class MinConflict:public BaseAlgorithm
{
public:
    MinConflict(Chessboard *chessboard);
    void solve();
    ~MinConflict(){};
private:
    int findMinConflict(int column);//返回最小冲突的行数
};

#endif // MINCONFLICT_H
