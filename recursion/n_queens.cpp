#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<string> board, int n){
    int dupli_row = row;
    int dupli_col = col;

    // Check for leftRow
    while(col>=0){
        if(board[row][col] == 'Q') return false;
        --col;
    }

    col = dupli_col;
    // Check for upperDiagonal
    while(row>=0  && col>=0){
        if(board[row][col] == 'Q') return false;
        --row; --col;
    }
    
    row = dupli_row;
    col = dupli_col;
    // Check for lowerDiagonal
    while(row<n && col>=0){
        if(board[row][col] == 'Q') return false;
        ++row; --col;
    }

    return true;
}

void permutation_queens(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int i = 0; i < n;++i){
        if(isValid(i,col,board,n)){
            board[i][col] = 'Q';
            permutation_queens(col+1,board,ans,n);
            board[i][col] = '.';
        }
    }
}

int main(){
    int n = 10;
    vector<string> board(n);
    vector<vector<string>> ans;
    string s(n,'.');

    for(int i = 0; i < n; ++i){
        board[i] = s;
    }

    // for(int i = 0; i < n; ++i){
    //     cout << board[i] << "\n";
    // }
    // cout << endl;

    permutation_queens(0,board,ans,n);

    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    cout << ans.size();
    return 0;
}