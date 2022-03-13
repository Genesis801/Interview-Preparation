#include<bits/stdc++.h>
using namespace std;

bool BFS(vector<vector<int>> edges, int n){
    queue<int> q;
    vector<int> visited(n,0);

    q.push(0);
    visited[0]=1;

    while(!q.empty()){
        int curr=q.front();
        q.pop();

        for(int i=0;i<n;i++){
            if(edges[curr][i]==1){
                if(visited[i]==1){
                    continue;
                }
                q.push(i);
                visited[i]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0)
            return false;
    }
    return true;
}
int main(){
    int n,e;
    cin>>n>>e;

    vector<vector<int>> edges(n);
    for(int i=0;i<n;i++){
        vector<int> node(n,0);
        edges[i]=node;
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=edges[s][f]=1;
    }
    if(BFS(edges,n)==true){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}