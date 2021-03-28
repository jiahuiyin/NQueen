#include "basealgorithm.h"

BaseAlgorithm::BaseAlgorithm(Chessboard *chessboard)
{
    this->chessboard=chessboard;
}


int BaseAlgorithm::getConflictNum()
{
//    int num=0;
//    int n=chessboard->board.size();
//    for(int i=0;i<n;i++){
//        for(int j=i+1;j<n;j++){
//            if(chessboard->board[i]==chessboard->board[j]||std::abs(i-j)==std::abs(chessboard->board[i]-chessboard->board[j])){
//                num++;
//            }
//        }
//    }
//    return num;
//    int ret=0;
//    int n=chessboard->board.size();
//    QVector<int> rowCon(n,0);
//    QVector<int> mainCon(2*n-1,0);
//    QVector<int> subCon(2*n-1 ,0);
//    for(int i=0;i<n;i++){
//        if(++rowCon[chessboard->board[i]]>1){
//            ret++;
//        }
//        if(++mainCon[chessboard->board[i]+n-i-1]>1){
//            ret++;
//        }
//        if(++subCon[chessboard->board[i]+i]>1){
//            ret++;
//        }
//    }
//    return ret;
    return getConflictNum(chessboard->board);
}
int BaseAlgorithm::getConflictNum(QVector<int>&v)
{
    int ret=0;
    int n=v.size();
    QVector<int> rowCon(n,0);
    QVector<int> mainCon(2*n-1,0);
    QVector<int> subCon(2*n-1 ,0);
    for(int i=0;i<n;i++){
        if(++rowCon[v[i]]>1){
            ret++;
        }
        if(++mainCon[v[i]+n-i-1]>1){
            ret++;
        }
        if(++subCon[v[i]+i]>1){
            ret++;
        }
    }
    return ret;
}
