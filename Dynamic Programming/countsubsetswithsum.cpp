#include <bits/stdc++.h>
using namespace std;

int countSubsets(int *a,int n, int w){
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=w;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(a[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j] + dp[i-1][j-a[i-1]];
            }
        }
    }
    return dp[n][w];
}
int main(){
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<countSubsets(a,n,s)<<endl;
}