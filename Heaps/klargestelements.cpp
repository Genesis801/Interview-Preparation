#include <bits/stdc++.h>
using namespace std;
vector<int> kSmallest(int arr[],int n,int k){
    priority_queue<int,vector<int>, greater<int>> pq;//Min priority queue
    vector<int> ans(k);

    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    for(int i=k-1;i>=0;i--){
        ans[i]=pq.top();
        pq.pop();
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> res;
    res=kSmallest(arr,n,k);
    for(int i=0;i<k;i++){
        cout<<res[i]<<" ";
    } 
}