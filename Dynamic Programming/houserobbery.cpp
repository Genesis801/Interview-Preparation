#include<bits/stdc++.h>
using namespace std;
//Recusrive code with exponential complexity
int lootHouses_rec(int *arr, int n){
    if(n<=0){
        return 0;
    }
    int take= lootHouses_rec(arr+2,n-2)+arr[0];
    int not_take= lootHouses_rec(arr+1,n-1);

    return max(take, not_take);
}

//DP based code with linear time complexity
int lootHouses_DP(int *arr,int n){
    if(n==1){
        return arr[0];
    }
    vector<int> dp(n);
    dp[0]=arr[0];
    dp[1]=max(arr[1], dp[0]);

    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1], dp[i-2]+arr[i]);
    }
    return dp[n-1];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    cout<<lootHouses_rec(a,n)<<endl;
    cout<<lootHouses_DP(a,n)<<endl;
}