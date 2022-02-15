#include<bits/stdc++.h>
using namespace std;
int countSubsets(int *arr,int n,int sum){
    int dp[n+1][sum+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=sum;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1] > j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]= dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n,d;
    cin>>n>>d;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int target=(sum+d)/2;
    cout<<countSubsets(arr,n,target)<<endl;
}