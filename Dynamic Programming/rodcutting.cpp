#include <bits/stdc++.h>
using namespace std;
//Recursive solution
int rodCut(int *wt,int *p,int n, int W){
    if(n==0 || W==0)
        return 0;
    if(wt[n-1] > W){
        return rodCut(wt,p,n-1,W);
    }
    else{
        int take = p[n-1]+rodCut(wt,p,n,W-wt[n-1]);
        int not_take = rodCut(wt,p,n-1,W);
        return max(not_take, take);
    }
}
//DP solution
int rodCut_DP(int *wt,int *p,int n){
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=1;j<=n;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(wt[i-1] > j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], p[i-1]+ dp[i][j-wt[i-1]]);
            }
        }
    }
    return dp[n][n];
}
int main(){
    int n;
    cin>>n;
    int wt[n];
    int p[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
        cin>>p[i];
    }
    cout<<"Recursive: "<<rodCut(wt,p,n,n)<<endl;
    cout<<"DP: "<<rodCut_DP(wt,p,n)<<endl;
}