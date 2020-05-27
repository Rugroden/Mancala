#ifndef AGGRESSIVEAGENT_H_
#define AGGRESSIVEAGENT_H_

#include "Agent.h"

using namespace std;

class AggressiveAgent : public Agent{
protected:
    int TestMove(const Board b, int start){
        Board temp=b;
        int moves=temp.board[start];
        int curr=start;
        int points=0;
        temp.board[start]=0;
        while(moves>0){
            curr+=1;
            curr%=temp.board.size();
            if(Turn==1&&curr==7){}
            else if(Turn==1&&curr==0){
                points+=1;
                temp.board[curr]+=1;
                moves-=1;
            }
            else if(Turn==2&&curr==0){}
            else if(Turn==2&&curr==7){
                points+=1;
                temp.board[curr]+=1;
                moves-=1;
            }
            else{temp.board[curr]+=1;moves-=1;}
        }
        int paired=temp.board.size()-curr;
        if(temp.board[curr]==1&&temp.board[paired]>0){
            if(Turn==1&&curr==0){}
            else if(Turn==2&&curr==7){}
            else{
                if(Turn==1){points+=(temp.board[paired]+1);}
                else{points+=(temp.board[paired]+1);}
            }
        }
        return points;
    }
public:
    AggressiveAgent(int _turn){Turn=_turn;}

    int AgentTurn(const Board b){
        Board temp=b;
        int best=100;
        int points=0;
        if(Turn==1){
            for(int i=1;i<7;i++){
                if(FreeMove(temp,i)){best=i;break;}
                int tempPoints=TestMove(temp,i);
                if(tempPoints>points){
                    points=tempPoints;
                    best=i;
                }
            }
            if(best==100){
                int a=rand()%6+1;
                while(b.board[a]==0){a=rand()%6+1;}
                best=a;
            }
        }
        else{
            for(int i=8;i<14;i++){
                if(FreeMove(temp,i)){best=i;break;}
                int tempPoints=TestMove(temp,i);
                if(tempPoints>points){
                    points=tempPoints;
                    best=i;
                }
            }
            if(best==100){
                int a=rand()%6+8;
                while(b.board[a]==0){a=rand()%6+8;}
                best=a;
            }
        }
        //cout<<"Player "<<GetTurn()<<" chose pit: "<<best<<endl;//PRINT
        return best;
    }
};
#endif
