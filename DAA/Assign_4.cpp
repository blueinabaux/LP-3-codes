#include <bits/stdc++.h>
using namespace std;


bool isSafe(int row, int col,vector<string> &board, int n){
    int preRow = row;
    int preCol = col;

    // Left upper diagonal
    while(row>=0 && col>=0){
        if(board[row][col] == 'Q'){
            return false;
        }
        row--;
        col--;
    }

    // Left column
    row = preRow;
    col = preCol;
    while(col>=0){
        if(board[row][col] == 'Q'){
            return false;
        }
        col--;
    }

    // Left lower diagonal
    row = preRow;
    col = preCol;
    while(row<n && col>=0){
        if(board[row][col] == 'Q'){
            return false;
        }
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){

    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row, col,board, n)){
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);

            // Backtrack
            board[row][col] = '.';
        }
        
    }


}

int main(){

    int n;
    cout<<"Enter the size of chessboard: ";
    cin>>n;

    // Board
    vector<string> board(n);

    // Answer
    vector<vector<string>> ans;

    string s(n, '.');
    for(int i=0;i<n;i++){
        board[i] = s;
    }

    solve(0, board, ans, n);

    for (auto row: ans){
        for(auto val: row){
            cout<<val<<endl;
        }
        cout<<endl;
    }


    return 0;
}