#include "minconflict.h"
#include "QDebug"
MinConflict::MinConflict(Chessboard *chessboard):BaseAlgorithm(chessboard){}


void MinConflict::solve()
{
    int n=chessboard->n;
    int MAXSTEP=6*n;
    int step=0;
    int sumStep=0;
    int a=0;
    while(getConflictNum()!=0){
        if(step>MAXSTEP){
            chessboard->reset();
            step=0;
            a++;
            continue;
        }
        chessboard->board[step%n]=findMinConflict(step%n);
        step++;
        sumStep++;
    }
    chessboard->solved=true;
    qDebug()<<"step"<<step;
    qDebug()<<"代数"<<a;
    qDebug()<<"sumstep"<<sumStep;
}

int MinConflict::findMinConflict(int column)
{
    int n=chessboard->board.size();
    QVector<int> rowCon(n,0);
    QVector<int> mainCon(2*n-1,0);
    QVector<int> subCon(2*n-1 ,0);
    for(int i=0;i<n;i++){
        if(i==column)continue;
        rowCon[chessboard->board[i]]++;
        mainCon[chessboard->board[i]+n-i-1]++;
        subCon[chessboard->board[i]+i]++;
    }
    int min=0,minCon=100;
    for(int i=0;i<n;i++){
        int sumCon;
        if((sumCon=(rowCon[i]+mainCon[i+n-column-1]+subCon[i+column]))<=minCon){
            minCon=sumCon;
            min=i;
        }
    }
    return min;
}
