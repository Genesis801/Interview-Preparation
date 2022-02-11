#include<bits/stdc++.h>
using namespace std;

//Recursive solution with exponential complexity
int knapsack_rec(int* w, int* p, int n, int maxW){
    if(n==0 || maxW==0){
        return 0;
    }
    if(w[0]>maxW){
        return knapsack_rec(w+1,p+1,n-1,maxW);
    }
    int take=p[0]+knapsack_rec(w+1, p+1, n-1, maxW-w[0]);
    int not_take=knapsack_rec(w+1,p+1,n-1,maxW);

    return max(take, not_take);
}
//Memoization solution
int knapsack_mem(int* w, int* p, int n, int maxW,vector<vector<int>> dp){
    if(n==0 || maxW==0){
        return 0;
    }
    if(dp[n][maxW] != -1){
        return dp[n][maxW];
    }
    if(w[n-1]>maxW){
        return dp[n][maxW]=knapsack_rec(w,p,n-1,maxW);
    }
    int take=p[n-1]+knapsack_rec(w, p, n-1, maxW-w[n-1]);
    int not_take=knapsack_rec(w,p,n-1,maxW);

    return dp[n][maxW]=max(take, not_take);
}
//DP based approach
int knapsack_dp(int* w, int* p,int n,int maxW, vector<vector<int>> dp){
    //Initialisation stage
    for(int i=0;i<=maxW;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    //Fill remaining rows left to right
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxW;j++){
            if(w[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j], p[i-1]+dp[i-1][j-w[i-1]]);
            }
        }
    }
    return dp[n][maxW];
}
int main(){
    int n,w;
    cin>>n>>w;
    int weights[n];
    int profits[n];

    for(int i=0;i<n;i++){
        cin>>weights[i];
        cin>>profits[i];
    }
    cout<<knapsack_rec(weights,profits,n,w)<<endl;
    
    vector<vector<int>> ans(n+1);
    for(int i=0;i<n+1;i++){
        vector<int> a(w+1);
        for(int j=0;j<w+1;j++){
            a[j]=-1;
        }
        ans[i]=a;
    }
    cout<<"knapsack DP: "<<knapsack_dp(weights,profits,n,w,ans)<<endl;
    cout<<"knapsack Mem: "<<knapsack_mem(weights,profits,n,w,ans)<<endl;
}