#include<bits/stdc++.h>
using namespace std;
/**Time complexity of the following function is: O((n+k)logk)
 * If k<<n then logk part of the time complexity will also be very small hence can be ignored
 * So, in the worst case the time complexity will become O(n), if n is large and k is very small.
 * Space complexity is O(k)
*/
void kSorted(int arr[],int n,int k){
    priority_queue<int> pq;
    int ind=0;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    arr[ind]=pq.top();
    pq.pop();
    ind++;
    for(int i=n-k+1;i<n;i++){
        pq.push(arr[i]);
        arr[ind]=pq.top();
        pq.pop();
        ind++;
    }
    for(int i=ind;i<n;i++){
        arr[i]=pq.top();
        pq.pop();
    }
    return;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    kSorted(arr,n,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } 
}