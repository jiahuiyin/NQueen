#include "chessboard.h"
#include <QDebug>
Chessboard::Chessboard(int n)
{
    this->n=n;
    for(int i=0;i<n;i++){
        board.push_back(i);
    }
    reset();
}

void Chessboard::reset()
{
    int n=board.size();
    for(int i=0;i<n;i++){
        int rand=QRandomGenerator::global()->bounded(n);
        std::swap(board[i],board[rand]);
    }
}
