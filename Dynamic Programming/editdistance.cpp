#include<bits/stdc++.h>
using namespace std;
//Recursive solution with time complexity O(3^n)
int moves(string s,string t){
    //Base case
    if(s.size()==0){
        return t.size();
    }
    if(t.size()==0){
        return s.size();
    }
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    //Check if first characters are equal or not
    if(s[0]==t[0]){
        return moves(s.substr(1), t.substr(1));
    }
    else{
        int i = 1 + moves(s.substr(1), t);
        int d = 1 + moves(s, t.substr(1));
        int r = 1 + moves(s.substr(1), t.substr(1));

        return min(i, min(d,r)); 
    }
}
//Memoization based approach
int moves_mem(string s,string t,vector<vector<int>> ans){
    //Base case
    int m=s.size();
    int n=t.size();
    if(m==0){
        ans[m][n]=t.size();
        return t.size();
    }
    if(n==0){
        ans[m][n]=s.size();
        return s.size();
    }
    if(s.size()==0 || t.size()==0){
        ans[m][n]=0;
        return 0;
    }
    if(ans[m][n] != -1){
        return ans[m][n];
    }
    //Check if first characters are equal or not
    if(s[0]==t[0]){
        ans[m][n] = moves_mem(s.substr(1), t.substr(1),ans);
        return ans[m][n];
    }
    else{
        int i = 1 + moves_mem(s.substr(1), t,ans);
        int d = 1 + moves_mem(s, t.substr(1),ans);
        int r = 1 + moves_mem(s.substr(1), t.substr(1),ans);

        ans[m][n]= min(i, min(d,r)); 
        return ans[m][n];
    }
}
//DP based approach with time complexity O(m*n)
int moves_DP(string s,string t, vector<vector<int>> ans){
    int m=s.size();
    int n=t.size();

    //Fill first row
    for(int i=0;i<=n;i++){
        ans[0][i]=i;
    }
    //Fill first column
    for(int j=0;j<=m;j++){
        ans[j][0]=j;
    }
    //Fill the rest of the cells

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            //check if the characters matches from the ending
            if(s[m-i]==t[n-j]){
                ans[i][j]=ans[i-1][j-1];
            }
            else{
                ans[i][j]= 1+ min(ans[i-1][j-1], min(ans[i][j-1], ans[i-1][j]));
            }
        }
    }
    return ans[m][n];
}
int main(){
    string s,t;
    cin>>s>>t;
    //cout<<"Edit Distance Recursive: "<<moves(s,t)<<endl;
    int m=s.size();
    int n=t.size();

    vector<vector<int>> ans(m+1);
    for(int i=0;i<m+1;i++){
        vector<int> a(n+1);
        for(int j=0;j<n+1;j++){
            a[j]=-1;
        }
        ans[i]=a;
    }
    cout<<"Edit Distance Memoization: "<<moves_mem(s,t,ans)<<endl;
    cout<<"Edit Distance DP: "<<moves_DP(s,t,ans)<<endl;
}