#include "climbhill.h"
#include <qdebug.h>
ClimbHill::ClimbHill(Chessboard *chessboard):BaseAlgorithm(chessboard){}

void ClimbHill::chooseBestLocation(int column,int column1)
{
    int pConflict=getConflictNum();
    std::swap(chessboard->board[column],chessboard->board[column1]);
    if(getConflictNum()>pConflict){
        std::swap(chessboard->board[column],chessboard->board[column1]);
    }
}

void ClimbHill::solve()
{
    int n=chessboard->n;
    int MAXSTEP=n*n*n;
    int step=0;
    int sumStep=0;
    int column=0,column1=0;
    while(getConflictNum()!=0){
        column1++;
        if(column1==n){column1=0;column++;}
        if(column==n){column1=1;column=0;}
        if(column!=column1)
        chooseBestLocation(column,column1);
        if(step>MAXSTEP){
            chessboard->reset();

            step=0;
            continue;
        }
        step++;
        sumStep++;
    }
    chessboard->solved=true;
    qDebug()<<sumStep;
    qDebug()<<step;
}






