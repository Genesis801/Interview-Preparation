#include<bits/stdc++.h>
using namespace std;
bool DFS(vector<vector<int>> edges, int n,int s,int dest, vector<int>& visited,vector<int>& ans){
    ans.push_back(s);
    visited[s]=1;
    if(s==dest){
        return true;
    }
    for(int i=0;i<n;i++){
        if(s==i)
            continue;
        if(edges[s][i]==1){
            if(visited[i]==1){
                continue;
            }
            return DFS(edges,n,i,dest,visited,ans);
        }
    }
    return false;
}
void getPath(vector<vector<int>> edges, int n, int src, int d){
    vector<int> visited(n,0);
    vector<int> ans;
    if(DFS(edges,n,src,d,visited,ans)==true)
    {
        int l=ans.size();
        for(int i=l-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
    }
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
    int src,dest;
    cin>>src>>dest;
    getPath(edges,n,src,dest);
}