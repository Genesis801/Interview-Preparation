#include <bits/stdc++.h>
using namespace std;
//Recursive solution
int unboundedknapsack(int *wt,int *p,int n, int W){
    if(n==0 || W==0)
        return 0;
    if(wt[n-1] > W){
        return unboundedknapsack(wt,p,n-1,W);
    }
    else{
        int take = p[n-1]+unboundedknapsack(wt,p,n,W-wt[n-1]);
        int not_take = unboundedknapsack(wt,p,n-1,W);
        return max(not_take, take);
    }
}
//DP solution
int unboundedknapsack_DP(int *wt,int *p,int n,int W){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=1;j<=W;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1] > j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], p[i-1]+ dp[i][j-wt[i-1]]);
            }
        }
    }
    return dp[n][W];
}
int main(){
    int n,W;
    cin>>n>>W;
    int wt[n];
    int p[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
        cin>>p[i];
    }
    cout<<"Recursive: "<<unboundedknapsack(wt,p,n,W)<<endl;
    cout<<"DP: "<<unboundedknapsack_DP(wt,p,n,W)<<endl;
}