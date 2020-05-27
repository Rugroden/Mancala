#ifndef AGENT_H_
#define AGENT_H_

#include "Board.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

class Agent{
protected:
    int Turn=0;
    bool FreeMove(const Board b, int start){
        Board temp=b;
        int moves=temp.board[start];
        int curr=start;
        if(Turn==1){
            for(moves;moves>0;moves--){
                if(curr==7){moves+=1;}
            }
            if(curr==0){return true;}
            return false;
        }
        else{
            for(moves;moves>0;moves--){
                if(curr==0){moves+=1;}
            }
            if(curr==7){return true;}
            return false;
        }
    }
public:
    int GetTurn(){return Turn;}
};
#endif
