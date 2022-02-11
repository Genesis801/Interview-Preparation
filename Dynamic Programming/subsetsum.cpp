#include<bits/stdc++.h>
using namespace std;

//Recursive approach
bool subsetsumRec(int *arr,int n, int W){
    if(W==0 && n==0){
        return false;
    }
    if(W==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(arr[n-1]>W){
        return subsetsumRec(arr,n-1,W);
    }
    else{
        return subsetsumRec(arr,n-1,W) || subsetsumRec(arr,n-1, W-arr[n-1]);
    }
}
//DP table based approach with time O(n*W)
bool subsetsumDP(int* arr,int n,int W){
    int dp[n+1][W+1];
    for(int i=1;i<=W;i++){
        dp[0][i]=false;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][W];
}
int main(){
    int n,W;
    cin>>n>>W;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool ans=subsetsumRec(arr,n,W);
    if(ans==true){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}