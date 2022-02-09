#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int* arr, int n) {
    vector<int> dp(n,1);
    
    for(int i=1;i<n;i++){
        
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]){
                int res=dp[j]+1;
                if(res > dp[i])
                	dp[i] = res;
            }
            else{
                continue;
            }
        } 
    }
    int m=-1;
    for(int i=0;i<n;i++){
        m=max(m,dp[i]);
    }
    return m;
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}