#ifndef DEFENSIVEAGENT_H_
#define DEFENSIVEAGENT_H_

#include "Agent.h"

using namespace std;

class DefensiveAgent : public Agent{
protected:
    int TestMove(const Board b, int start){
        Board temp=b;
        int moves=temp.board[start];
        int curr=start;
        int Points=0;
        temp.board[start]=0;
        while(moves>0){
            curr+=1;
            curr%=temp.board.size();
            if(Turn==1&&curr==7){}
            else if(Turn==2&&curr==0){}
            else{temp.board[curr]+=1;moves-=1;}
        }
        if(temp.board[curr]==1&&temp.board[temp.board.size()-curr]>0){
            if(Turn==1&&curr==0){}
            else if(Turn==2&&curr==7){}
            else{
                int total=temp.board[curr]+temp.board[temp.board.size()-curr];
                temp.board[curr]=0;
                temp.board[temp.board.size()-curr]=0;
                if(Turn==1){temp.board[0]+=total;}
                else{temp.board[7]+=total;}
            }
        }
        if(Turn==1){
            for(int i=8;i<14;i++){
                int tempPoints=TestEnemyMoves(temp,i);
                if(tempPoints>Points){Points=tempPoints;}
            }
        }
        else{
            for(int i=1;i<7;i++){
                int tempPoints=TestEnemyMoves(temp,i);
                if(tempPoints>Points){Points=tempPoints;}
            }
        }
        return Points;
    }
    int TestEnemyMoves(const Board b,int start){
        Board temp=b;
        int moves=temp.board[start];
        int curr=start;
        int Points=0;
        temp.board[start]=0;
        while(moves>0){
            curr+=1;
            curr%=temp.board.size();
            if(Turn==2&&curr==7){}
            else if(Turn==2&&curr==0){
                Points+=1;
                temp.board[curr]+=1;
                moves-=1;
            }
            else if(Turn==1&&curr==0){}
            else if(Turn==1&&curr==7){
                Points+=1;
                temp.board[curr]+=1;
                moves-=1;
            }
            else{temp.board[curr]+=1;moves-=1;}
        }
        int paired=temp.board.size()-curr;
        if(temp.board[curr]==1&&temp.board[paired]>0){
            if(Turn==2&&curr==0){}
            else if(Turn==1&&curr==7){}
            else{
                if(Turn==2){Points+=(temp.board[paired]+1);}
                else{Points+=(temp.board[paired]+1);}
            }
        }
        return Points;
    }
public:
    DefensiveAgent(int _turn){Turn=_turn;}
    int AgentTurn(const Board b){
        Board temp=b;
        int best=100;
        int points=100;
        if(Turn==1){
            for(int i=1;i<7;i++){
                if(FreeMove(temp,i)){best=i;return best;}
                int tempPoints=TestMove(temp,i);
                if(tempPoints<points&&temp.board[i]>0){
                    points=tempPoints;
                    best=i;
                    if(points==0&&temp.board[i]>0){return best;}
                }
            }
            if(best==100||temp.board[best]==0){
                int a=rand()%6+1;
                while(temp.board[a]==0){a=rand()%6+1;}
                best=a;
            }
        }
        else{
            for(int i=8;i<14;i++){
                if(FreeMove(temp,i)){best=i;return best;}
                int tempPoints=TestMove(temp,i);
                if(tempPoints<points&&temp.board[i]>0){
                    points=tempPoints;
                    best=i;
                    if(points==0&&temp.board[i]>0){return best;}
                }
            }
            if(best==100||temp.board[best]==0){
                int a=rand()%6+8;
                while(temp.board[a]==0){a=rand()%6+8;}
                best=a;
            }
        }
        //cout<<"Player "<<Turn<<" Chose Pit "<<best<<endl;
        return best;
    }

};
#endif
