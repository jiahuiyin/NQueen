#ifndef GENETIC_H
#define GENETIC_H
#include "chessboard.h"
#include "basealgorithm.h"
class Genetic:public BaseAlgorithm
{
public:
    Genetic(Chessboard *chessboard);
    void solve();
    ~Genetic(){};
private:
    int individualNum;
    int maxFit;
    const double PM=1;//变异概率
    QVector<int> fitness;
    QVector<QVector<int>> population;
    void init();
    QVector<int> getChild();
    QVector<QVector<int>> getChildren();
    int getEvaluation(int con);
};

#endif // GENETIC_H
