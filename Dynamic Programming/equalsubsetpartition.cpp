#include<bits/stdc++.h>
using namespace std;
int recursiveHelper(int *arr,int n, int W){
    if(n==0 and W==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(W==0)
        return 1;
    if(arr[n-1] > W){
        return recursiveHelper(arr, n-1, W);
    }
    else{
        return recursiveHelper(arr, n-1, W) || recursiveHelper(arr, n-1, W-arr[n-1]);
    }
}
//Recursive solution with exponential complexity
int checkpartitionRec(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    if(sum%2 != 0){
        return 0;
    }
    else{
        return recursiveHelper(arr,n,sum/2);
    }
}

//DP based solution with O(n*W) complexity
int checkpartitionDP(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    if(sum%2 != 0){
        return 0;
    }
    int w=sum/2;
    int dp[n+1][w+1];

    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=0;j<=w;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){

            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][w];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=checkpartitionDP(arr,n);
    if(ans==1){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}