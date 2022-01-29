#include<bits/stdc++.h>
using namespace std;
/**
 * @Brute Force solution
 * 
 long staircase(int n){
    if(n<0)
        return 0;
    if(n==0){
        return 1;
    }
    return staircase(n-1)+staircase(n-2)+staircase(n-3);
}*/
long helper(int n,vector<int>& ans){
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<=n;i++){
        //int x=i-2,y=i-3;

        ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
    }
    return ans[n];
}
long staircase(int n){
    vector<int> ans(n+1,-1);
    return helper(n,ans);
}
int main(){
    int n;
    cin>>n;
    cout<<staircase(n)<<endl;
}