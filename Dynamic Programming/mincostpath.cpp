#include<bits/stdc++.h>
using namespace std;
/* Brute force recursive approach with time complexity O(3^n).
int minCostPath(vector<vector<int>>& a,int i,int j,int m,int n){
    if(i>=m || j>=n){
        return INT_MAX;
    }
    if(i==m-1 && j==n-1){
        return a[i][j];
    }
    int right=minCostPath(a,i,j+1,m,n);
    int down=minCostPath(a,i+1,j,m,n);
    int diagonal=minCostPath(a,i+1,j+1,m,n);
    return a[i][j]+ min(diagonal,min(right,down));
}*/
/*Memoization based approach with Time complexity O(m*n)*/
int minCostPath(vector<vector<int>>& a,int i,int j,int m,int n,vector<vector<int>> out){
    if(i>=m || j>=n){
        return INT_MAX;
    }
    if(i==m-1 && j==n-1){
        return a[i][j];
    }
    //check if already answer exist or not
    if(out[i][j]!=-1){
        return out[i][j];
    }
    int r=minCostPath(a,i,j+1,m,n,out);
    int d=minCostPath(a,i+1,j,m,n,out);
    int diag=minCostPath(a,i+1,j+1,m,n,out);

    int ans=a[i][j]+ min(diag,min(r,d));
    out[i][j]=ans;
    return ans;
}
/*Bottom Up DP based approach O(m*n) */
int minCostPath_DP(vector<vector<int>>& a,int m,int n,vector<vector<int>> out){
    out[m-1][n-1]=a[m-1][n-1];

    //Fill last row right to left
    for(int i=n-2;i>=0;i--){
        out[m-1][i]=out[m-1][i+1]+a[m-1][i];
    }
    //Fill last column bottom to top
    for(int i=m-2;i>=0;i--){
        out[i][n-1]=out[i+1][n-1]+a[i][n-1];
    }
    //Fill the remaining cells
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            out[i][j]= min(out[i][j+1], min(out[i+1][j+1],out[i+1][j])) + a[i][j];
        }
    }
    return out[0][0];
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m);
    for(int i=0;i<m;i++){
        vector<int> a(n);
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            a[j]=x;
        }
        arr[i]=a;
    }
    vector<vector<int>> out(m);
    for (int i = 0; i < m; i++)
    {
        vector<int> a(n);
        for(int j=0;j<n;j++){
            a[j]=-1;
        }
        out[i]=a;
    }
    int ans=minCostPath(arr,0,0,m,n,out);
    cout<<"DP: "<<minCostPath_DP(arr,m,n,out)<<endl;
    cout<<"Mem: "<<ans<<endl;
    return 0;
}