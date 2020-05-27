#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "DefensiveAgent.h"
#include "AggressiveAgent.h"

using namespace std;
bool StillPlaying(const Board b){
    int y=0;int z=0;
    for(int i=1;i<7;i++){y+=b.board[i];}
    if(y==0){return false;}
    for(int i=8;i<14;i++){z+=b.board[i];}
    if(z==0){return false;}
    return true;
}
void Move(Board &b,int start, int &turn){
    int moves=b.board[start];
    int curr=start;
    b.board[start]=0;
    while(moves>0){
        curr+=1;
        curr%=b.board.size();
        if(turn==1&&curr==7){}
        else if(turn==2&&curr==0){}
        else{b.board[curr]+=1;moves-=1;}
    }
    if(b.board[curr]==1&&b.board[b.board.size()-curr]>0){
        if(turn==1&&curr==0){}
        else if(turn==2&&curr==7){}
        else{
            //cout<<"Player "<<turn<<" Got to steal from pit: "<<curr<<endl;
            //cout<<b<<endl;//PRINT
            int total=b.board[curr]+b.board[b.board.size()-curr];
            b.board[curr]=0;
            b.board[b.board.size()-curr]=0;
            if(turn==1){b.board[0]+=total;}
            else{b.board[7]+=total;}
        }
    }
    if(turn==1&&curr==0){return;}
    else if(turn==2&&curr==7){return;}
    else{if(turn==2){turn=1;}else{turn=2;}}
}

int main(){
    ofstream fout;fout.open("wins.txt");
    AggressiveAgent Player1(1);
    AggressiveAgent Player2(2);
//    DefensiveAgent Player1(1);
//    DefensiveAgent Player2(2);
    int simulations=1;
    int p1,p2,ties;
    p1=p2=ties=0;
    srand(time(NULL));
    cout<<"How many simulations do I run? ";cin>>simulations;
    for(int i=0;i<simulations;i++){
        Board b;
        int turn=1;
        fout<<b<<endl;//PRINT
        while(StillPlaying(b)){
            fout<<"Player "<<turn<<"'s turn"<<endl;
            if(turn==1){Move(b,Player1.AgentTurn(b),turn);}
            else if(turn==2){Move(b,Player2.AgentTurn(b),turn);}
            else{turn=1;}
            fout<<b<<endl;//PRINT
        }
        int p1tot,p2tot;
        p1tot=p2tot=0;
        for(int j=0;j<14;j++){
            while(j<7){p1tot+=b.board[j];j++;}
            while(j<14){p2tot+=b.board[j];j++;}
        }
        if(p1tot<p2tot){p2+=1;}
        else if(p2tot<p1tot){p1+=1;}
        else{ties+=1;}
    }
    cout<<"Player1's wins: "<<p1<<endl;
    cout<<"Player2's wins: "<<p2<<endl;
    cout<<"Ties: "<<ties<<endl;
    cin.ignore();
    return 0;
}
