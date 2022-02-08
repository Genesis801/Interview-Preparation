#include<bits/stdc++.h>
using namespace std;

//Recursive solution with time complexity O(2^n)
int lcs_rec(string s,string t){
    //base case
    if(s[0]=='\0' || t[0]=='\0')
        return 0;
    //check if the first characters are same or not
    if(s[0]==t[0]){
        return 1+ lcs_rec(s.substr(1),t.substr(1));
    }
    else{
        int a=lcs_rec(s.substr(1),t);
        int b=lcs_rec(s, t.substr(1));
        int c=lcs_rec(s.substr(1),t.substr(1));//This step is redundant in this approach

        return max(a, b);
    }
}
//Memoization based solution with time complexity O(m*n)
int lcs_mem(string s,string t, vector<vector<int>> out){
    //base case
    if(s.size()==0 || t.size()==0)
        return 0;
    //if already value is computed
    int i=s.size();int j=t.size();
    if(out[i][j]!=-1){
        return out[i][j];
    }
    //check if the first characters are same or not
    if(s[0]==t[0]){
        out[i][j]= 1+ lcs_mem(s.substr(1),t.substr(1),out);
        return out[i][j];
    }
    else{
        int a=lcs_mem(s.substr(1),t,out);
        int b=lcs_mem(s, t.substr(1),out);
        int c=lcs_mem(s.substr(1),t.substr(1),out);//This step is redundant in this approach

        out[i][j] = max(a, max(b,c));
        return out[i][j];
    }
}
//DP based solution
int lcs_DP(string s,string t, vector<vector<int>>& out){
    //For first row all columns will be zero
    int m=s.size();int n=t.size();
    for(int i=0;i<=n;i++){
        out[0][i]=0;
    }
    //For first column all rows will be zero
    for(int i=0;i<=m;i++){
        out[i][0]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i-1]==t[n-j-1]){
                out[i][j]= 1 + out[i-1][j-1];
            }
            else{
                out[i][j]= max(out[i][j-1], max(out[i-1][j-1], out[i-1][j]));
            }
        }
    }
    return out[m][n];
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<"LCS Recursive: "<<lcs_rec(s,t)<<endl;
    
    vector<vector<int>> out(s.size()+1);
    for(int i=0;i<s.size()+1;i++){
        vector<int> a(t.size()+1);
        for(int j=0;j<t.size()+1;j++){
            a[j]=-1;
        }
        out[i]=a;
    }
    //cout<<"LCS Memoization: "<<lcs_mem(s,t,out)<<endl;
    cout<<"LCS DP: "<<lcs_DP(s,t,out)<<endl;
}