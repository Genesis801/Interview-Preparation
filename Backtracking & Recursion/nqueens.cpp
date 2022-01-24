#include<bits/stdc++.h>
using namespace std;
int board[11][11];
bool isPossible(int n, int row,int col){
    //check for same column
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1)
            return false;
    }
    //check for upper left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1)
            return false;
    }
    //check for upper right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j]==1)
            return false;
    }
    return true;
    
}
void nQueenHelper(int n,int row){
    //if all rows are complete that case that is the base case
    if(row==n){
        //print the current solution board
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"---------------------------"<<endl;
        return;
    }
    for(int j=0;j<n;j++){
        if(isPossible(n,row,j)){
            board[row][j]=1;
            nQueenHelper(n,row+1);
            board[row][j]=0;
        }

    }
    return;
}
void nQueens(int n){
    memset(board, 0,11*11*sizeof(int));

    nQueenHelper(n,0);
}
int main(){
    nQueens(8);
    return 0;
}