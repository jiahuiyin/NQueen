#include "genetic.h"
#include "QDebug"
Genetic::Genetic(Chessboard *chessboard):BaseAlgorithm(chessboard)
{
    maxFit=chessboard->n*2;
    init();
}

void Genetic::init()
{
    individualNum=chessboard->n/6+2;
    for(int i=0;i<individualNum;i++){
        population.push_back(chessboard->board);
        chessboard->reset();
        int conflictNum=getConflictNum(population.back());
        fitness.push_back(getEvaluation(conflictNum));
    }
   //qDebug()<<1;
}

QVector<int> Genetic::getChild()
{
    int sumFitness=std::accumulate(fitness.begin(),fitness.end(),0);
    int parent1,parent2;
    do{
        double p1=QRandomGenerator::global()->bounded(sumFitness);
        double p2=QRandomGenerator::global()->bounded(sumFitness);

        for(int i=0;i<fitness.size();i++){
            p1-=fitness[i];
            if(p1<0){
                parent1=i;
                break;
            }
        }
        for(int i=0;i<fitness.size();i++){
            p2-=fitness[i];
            if(p2<0){
                parent2=i;
                break;
            }
        }
    }while(parent1==parent2);
    int cutOffStation=QRandomGenerator::global()->bounded(chessboard->n);
    QVector<int>v;
    for(int i=0;i<cutOffStation;i++){
        v.push_back(population[parent1][i]);
    }
    for(int i=cutOffStation;i<chessboard->n;i++){
        v.push_back(population[parent2][i]);
    }
    //变异
    if(QRandomGenerator::global()->generateDouble()<PM){
        int station=QRandomGenerator::global()->bounded(chessboard->n);
        int t=QRandomGenerator::global()->bounded(chessboard->n);
        v[station]=t;
    }
    return v;
}

QVector<QVector<int>> Genetic::getChildren()
{
    int average=std::accumulate(fitness.begin(),fitness.end(),0)/individualNum;
    QVector<QVector<int>>v;
    while(v.size()!=fitness.size()){
        QVector<int>child=getChild();
        int con=getConflictNum(child);
        if(average<=getEvaluation(con)){
            v.push_back(child);
            fitness[v.size()-1]=getEvaluation(con);
       }
    }
    return v;
}
void Genetic::solve()
{
    int step=0;
    while(true){
        for(int i=0;i<fitness.size();i++){
            if(fitness[i]==maxFit){
                chessboard->board=population[i];
                chessboard->solved=true;
                return;
            }
        }
        population=getChildren();
//        for(int i=0;i<fitness.size();i++){
//            fitness[i]=getEvaluation(getConflictNum(population[i]));
//        }
        step++;
    }
}


int Genetic::getEvaluation(int con)
{
    if(con<maxFit)return maxFit-con;
    return 0;
}

