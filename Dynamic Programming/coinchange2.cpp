#include<bits/stdc++.h>
using namespace std;
//This code gives the minimum coins required to get a given sum.
//Recursive code with exponential time complexity
int coinChange_DP(int *d,int m,int val, vector<vector<int>>dp){
    for(int i=1;i<=m;i++){
        dp[i][0]=0;
    }
    for(int j=1;j<=val;j++){
        dp[0][j]=INT_MAX-1;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=val;j++){
            if(d[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j] , 1+dp[i][j-d[i-1]]);
            }
        }
    }
    if(dp[m][val]==INT_MAX-1){
        return -1;
    }
    else
        return dp[m][val];
}
int main(){
    int m;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    int val;
    cin>>val;
    vector<vector<int>> dp(m+1, vector<int>(val+1));
    //cout<<"Coin change DP: "<<coinChange_mem(a,m,val,dp)<<endl;
    cout<<"Coin change DP: "<<coinChange_DP(a,m,val,dp)<<endl;
}