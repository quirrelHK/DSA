#include<bits/stdc++.h>
using namespace std;

bool isSolvable(vector<string>,int,int,char);
bool solve(vector<string> &board){
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[i].size(); ++j){

            if(board[i][j] == '.'){

                for(char c='1'; c<='9'; ++c){

                    if(isSolvable(board,i,j,c)){
                        board[i][j] = c;

                        if(solve(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}


bool isSolvable(vector<string> board, int row, int col, char c){
    for(int i = 0; i < 9; ++i){
        if(board[row][i] == c)
            return false;

        if(board[i][col] == c)
            return false;

        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)
            return false;
    }
    return true;
}

int main(){
    int n = 9;
    vector<string> board;
    // string s(n,'.');

    // for(int i = 0; i < 9; ++i){
    //     board[i] = s;
    // }
    board = {{"53..7...."},{"6..195..."},{".98....6."},{"8...6...3"},{"4..8.3..1"},{"7...2...6"},{".6....28."},{"...419..5"},{"....8..79"}};

    solve(board);

     for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[i].size(); ++j){
            cout << board[i][j];
            if((j+1)%3==0) cout << " ";
        }
        if((i+1)%3==0) cout << endl;
        cout << endl;
     }
    return 0;
}