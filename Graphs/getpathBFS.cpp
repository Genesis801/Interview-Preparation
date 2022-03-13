#include<bits/stdc++.h>
using namespace std;
bool BFS(vector<vector<int>> edges, int n,int src, int dest,unordered_map<int,int>& mp){
    queue<int> q;
    vector<int> visited(n,0);
    
    q.push(src);
    visited[src]=1;

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(edges[curr][i]==1){
                if(visited[i]==1)
                    continue;
                mp[i]=curr;
                if(i==dest){
                    return true;
                }
                q.push(i);
                
                visited[i]=1;
            }
        }
    }
    return false;
}
void getPathBFS(vector<vector<int>> edges, int n, int src, int dest){
    unordered_map<int,int> mp;
    if(BFS(edges,n,src,dest,mp)==true)
    {
        int curr=dest;
        while(curr!=src){
            cout<<curr<<" ";
            curr=mp[curr];
        }
        cout<<src<<" ";
    }
}
int main(){
    int n,e;
    cin>>n >> e;

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
    int src,dest;
    cin>>src>>dest;

    getPathBFS(edges,n,src,dest);
}