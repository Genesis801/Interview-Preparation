#include<bits/stdc++.h>
using namespace std;
bool hasPath(vector<vector<int>> edges, int n, int s, int e){
    queue<int> q;
    vector<bool> visited(n,false);
    q.push(s);
    visited[s]=true;

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(edges[curr][i]==1){
                if(visited[i]==true)
                    continue;
                if(i==e)
                    return true;
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return false;
}
int main(){
    int n,e;
    cin>>n>>e;

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
    int start,end;
    cin>>start>>end;

    if(hasPath(edges,n,start,end)==true)
        cout<<"true";
    else{
        cout<<"false";
    }
}