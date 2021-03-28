#ifndef CLIMBHILL_H
#define CLIMBHILL_H
#include "chessboard.h"
#include "basealgorithm.h"

class ClimbHill :public BaseAlgorithm
{
public:
    ClimbHill(Chessboard *chessboard);
    void solve();
    ~ClimbHill(){};
private:
    void chooseBestLocation(int column,int column1);
};

#endif // CLIMBHILL_H
