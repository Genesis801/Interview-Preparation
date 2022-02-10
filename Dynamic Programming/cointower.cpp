/**
 * Whis and Beerus are playing a new game today. 
 * They form a tower of N coins and make a move in alternate turns.
 * Beerus plays first. In one step, the player can remove either 1, X, or Y 
 * coins from the tower. The person to make the last move wins the game.
 * 
 * Example:
 * IP: 4 2 3 OP: Whis
 * IP: 10 2 4 OP: Beerus
 */
#include<bits/stdc++.h>
using namespace std;

string coinTower_dp(int n, int x, int y, int* dp){
    dp[1]=1;dp[x]=1;dp[y]=1;
    int a,b,c;
    for(int i=2;i<=n;i++){
        if(i==x || i==y){
            continue;
        }
        a=dp[i-1]^1;
        if(i-x>0){
            b=dp[i-x]^1;
        }
        if(i-y>0){
            c=dp[i-y]^1;
        }
        dp[i]=a || b || c;
    }
    if(dp[n]==0){
        return "whis";
    }
    else{
        return "Beerus";
    }
}
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<"DP: "<<coinTower_dp(n,x,y,dp)<<endl;
}