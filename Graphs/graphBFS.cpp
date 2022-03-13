#include<bits/stdc++.h>
using namespace std;
/**BFS Traversal of a graph*/
void printBFS(vector<vector<int>>& edges, int n, queue<int>& q, vector<int>& visited){
    if(q.size()==0){
        return;
    }
    int curr=q.front();
    cout<<curr<<" ";
    visited[curr]=1;
    q.pop();

    for(int i=0;i<n;i++){
        if(edges[curr][i]==1){
            if(visited[i]==1)
                continue;
            q.push(i);
            visited[i]=1;
        }
    }
    printBFS(edges,n,q,visited);
}
/**For BFS traversal of non-connected components*/
void BFS(vector<vector<int>>& edges, int n){
    vector<int> visited(n,0);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            q.push(i);
            printBFS(edges,n,q,visited);
        }
    }
}
int main(){
    int n,e;
    cin>> n>> e;

    vector<vector<int>> edges(n);
    for(int i=0;i<n;i++){
        vector<int> edge(n,0);
        edges[i]=edge;
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=edges[s][f]=1;
    }
    
    BFS(edges,n);
}