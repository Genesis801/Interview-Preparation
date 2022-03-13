#include<bits/stdc++.h>
using namespace std;

/**DFS Traversal*/
void printDFS(int **edges, int n,int start, vector<bool>& visited){
    cout<<start<<" ";
    visited[start]=true;

    for(int i=0;i<n;i++){
        if(i==start){
            continue;
        }
        if(edges[start][i]==1){
            if(visited[i]){
                continue;
            }
            else{
                printDFS(edges,n,i,visited);
            }
        }
    }
}
/**For non-connected graph*/
void DFS(int **edges,int n){
    
}
int main(){
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=edges[s][f]=1;      
    }
    vector<bool> visited(n,false);
    int starting_vertex=0;
    printDFS(edges,n,starting_vertex, visited);
}
