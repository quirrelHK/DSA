#include<bits/stdc++.h>
using namespace std;

void permutation_queens(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int i = 0; i < n; ++i){
        if(leftRow[i]==0 && upperDiagonal[n-1 + col-i]==0 && lowerDiagonal[i+col] == 0){
            board[i][col] = 'Q';
            leftRow[i] = 1;
            upperDiagonal[n-1 + col-i] = 1;
            lowerDiagonal[i+col] = 1;
            permutation_queens(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
            board[i][col] = '.';
            leftRow[i] = 0;
            upperDiagonal[n-1 + col-i] = 0;
            lowerDiagonal[i+col] = 0;
        }
    }

}

int main(){
    int n = 12;
    vector<string> board(n);
    vector<vector<string>> ans;
    string s(n,'.');
    vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);

    for(int i = 0; i < n; ++i){
        board[i] = s;
    }
    permutation_queens(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);

    
     for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    cout << ans.size();
    return 0;
}