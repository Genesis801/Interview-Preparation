#include<bits/stdc++.h>
using namespace std;
vector<int> BFS(vector<vector<int>> edges, int n,int s, vector<int>& visited){
    queue<int> q;
    q.push(s);
    visited[s]=1;
    vector<int> res;

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        res.push_back(curr);

        for(int i=0;i<n;i++){
            if(edges[curr][i]==1){
                if(visited[i]==1)
                    continue;
                q.push(i);
                visited[i]=1;
            }
        }
    }
    return res;
}
void getComponent(vector<vector<int>> edges, int n){
    vector<int> visited(n,0);
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(visited[i]==0){
            vector<int> res;
            res=BFS(edges,n,i,visited);
            ans.push_back(res);
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n,e;
    cin>> n>> e;

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
    getComponent(edges,n);
}