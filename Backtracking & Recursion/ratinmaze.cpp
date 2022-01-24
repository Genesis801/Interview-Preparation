#include<bits/stdc++.h>
using namespace std;
void print(int **sol,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----------------------"<<endl;
    return;
}
void mazeHelp(int maze[][20],int n,int **sol,int x,int y){
    if(x==n-1 && y==n-1){
        sol[x][y]=1;
        print(sol,n);
    }
    if(x<0 || x>=n ||y<0 || y>=n || sol[x][y]==1 || maze[x][y]==0){
        return;
    }
    sol[x][y]=1;
    mazeHelp(maze,n,sol,x-1,y);
    mazeHelp(maze,n,sol,x+1,y);
    mazeHelp(maze,n,sol,x,y-1);
    mazeHelp(maze,n,sol,x,y+1);
    sol[x][y]=0;
}
void ratInMaze(int maze[][20],int n){
    int **sol=new int*[n];
    for(int i=0;i<n;i++){
        sol[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        memset(sol[i],0,n*sizeof(int));
    }
    mazeHelp(maze,n,sol,0,0);
}
int main(){
    int n;
    cin>>n;
    int maze[n][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    ratInMaze(maze,n);
}