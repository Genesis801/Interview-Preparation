#include <bits/stdc++.h>
using namespace std;
vector<int> makeRangeArray(int *arr,int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=sum;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else{
                dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    vector<int> res;
    for(int i=0;i<=sum;i++){
        if(dp[n][i]==1){
            res.push_back(i);
        }
    }
    return res;
}
int minSubsetDifference(int *arr, int n){
    int sum=0;vector<int> res;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    res=makeRangeArray(arr,n,sum);
    int s=res.size();
    int mn=INT_MAX;
    for(int i=0;i<=s/2;i++){
        int diff= sum-(2*res[i]);
        mn = min(diff,mn);
    }
    return mn;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minSubsetDifference(arr,n)<<endl;
}