#include<bits/stdc++.h>
using namespace std;
/*Brute Force solution
int minSteps(int n){
    if(n<=1)
        return 0;
    int x=INT_MAX,y=INT_MAX,z=INT_MAX;
    x=minSteps(n-1);
    if(n%2==0)
        y=minSteps(n/2);
    if(n%3==0)
        z=minSteps(n/3);
    return 1+min(x,min(y,z));
}*/

/** DP based solution*/
int helper(int n,vector<int>& ans){
    ans[0]=1;ans[1]=1;ans[2]=1;ans[3]=1;
    for(int i=4;i<=n;i++){
        int x=ans[i-1];
        int y=INT_MAX,z=INT_MAX;
        if(i%2==0)
            y=ans[i/2];
        if(i%3==0)
            z=ans[i/3];
        ans[i]=1+min(x,min(y,z));
    }
    return ans[n];
}
int minSteps(int n){
    if(n<=1)
        return 0;
    vector<int> ans(n+1,-1);
    return helper(n,ans);
}
int main(){
    int n;
    cin>>n;
    cout<<minSteps(n)<<endl;
}