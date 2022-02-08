#include<bits/stdc++.h>
using namespace std;
int balanced(int n){
    if(n<=1){
        return 1;
    }
    unsigned int mod=1000000007;
    int l=balanced(n-1);
    int r=balanced(n-2);

    int ans=(l*l + 2*l*r)%mod;
    return ans;
}
int main(){
    int n;
    cout<<"Enter height:"<<endl;
    cin>>n;
    cout<<balanced(n)<<endl;
} 