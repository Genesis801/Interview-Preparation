#include<bits/stdc++.h>
using namespace std;
//This code gives the number of ways a certain sum can be acheived using some denominations
//Recursive code with exponential time complexity
int coinChange(int* d,int m,int value){
    if(value==0)
        return 1;
    if(value<0 || (m<=0 && value>0))
        return 0;
    return coinChange(d,m-1,value) + coinChange(d,m,value-d[m-1]);
}
//Memoization based approach
int coinChange_mem(int *d,int m,int val, vector<vector<int>>& dp){
    if(val==0){
        dp[m][val]=1;
        return dp[m][val];
    }
    if(m==0){
        return 0;
    }
    if(dp[m][val] != -1){
        return dp[m][val];
    }
    if(d[m-1]<=val){
        dp[m][val]=coinChange_mem(d,m-1,val,dp)+coinChange_mem(d,m,val-d[m-1],dp);
        return dp[m][val];
    }
    else{
        return dp[m][val]=coinChange_mem(d,m-1,val,dp);
    }

}
int coinChange_DP(int *d,int m,int val, vector<vector<int>>dp){
    for(int i=0;i<=m;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=val;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=val;j++){
            if(d[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-d[i-1]];
            }
        }
    }
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
    cout<<"Coin change recursive: "<<coinChange(a,m,val)<<endl;
    vector<vector<int>> dp(m+1, vector<int>(val+1));
    //cout<<"Coin change DP: "<<coinChange_mem(a,m,val,dp)<<endl;
    cout<<"Coin change DP: "<<coinChange_DP(a,m,val,dp)<<endl;
}