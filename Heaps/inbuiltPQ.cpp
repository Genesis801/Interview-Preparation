#include <queue>
#include <iostream>
using namespace std;
int main(){
    priority_queue<int,vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(6);
    pq.push(16);
    pq.push(2);
    pq.push(12);

    cout<<"Size: "<<pq.size()<<endl;
    cout<<"Min: "<<pq.top()<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}