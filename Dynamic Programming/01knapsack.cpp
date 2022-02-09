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
//DP based approach
int knapsack_dp(int* w, int* p,int n,int maxW, vector<vector<int>> dp){
    //Fill last row
    for(int i=0;i<=maxW;i++){
        dp[n][i]=0;
    }
    //Fill remaining rows left to right
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=maxW;j++){
            if(w[i]>j){
                dp[i][j]=dp[i+1][j];
            }
            else{
                dp[i][j]= max(dp[i+1][j], p[i]+dp[i+1][j-w[i]]);
            }
        }
    }
    return dp[0][maxW];
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
}