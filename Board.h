#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
#include <vector>

using namespace std;

class Board{
protected:
public:
    vector<int> board;
    Board(){
        for(int i=0;i<14;i++){
            if(i!=0&&i!=7){board.push_back(4);}
            else{board.push_back(0);}
        }
    }

    void printReference(){
        cout<<"        <----Player One"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"|   | 6 | 5 | 4 | 3 | 2 | 1 |   |"<<endl;
        cout<<"| 7 |-----------------------| 0 |"<<endl;
        cout<<"|   | 8 | 9 | 10| 11| 12| 13|   |"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"        Player Two ---->"<<endl;
    }
    friend ostream& operator<< (ostream& os, const Board& b){
        os<<"---------------------------------"<<endl;
        os<<"|   | "<<b.board[6]<<" | "<<b.board[5]<<" | "<<b.board[4]<<" | "<<b.board[3]<<" | "<<b.board[2]<<" | "<<b.board[1]<<" |   |"<<endl;
        os<<"| "<<b.board[7]<<" |-----------------------| "<<b.board[0]<<" |"<<endl;
        os<<"|   | "<<b.board[8]<<" | "<<b.board[9]<<" | "<<b.board[10]<<" | "<<b.board[11]<<" | "<<b.board[12]<<" | "<<b.board[13]<<" |   |"<<endl;
        os<<"---------------------------------"<<endl;
    }
};
#endif
