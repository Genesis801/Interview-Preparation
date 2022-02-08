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
int main(){
    string s,t;
    cin>>s>>t;
    cout<<"Edit Distance Recursive: "<<moves(s,t)<<endl;
    int m=s.size();
    int n=s.size();

}