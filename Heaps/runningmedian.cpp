#include <bits/stdc++.h>
using namespace std;
/*Time complexity is O(nlogn)*/
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;    
    
    for(int i=0;i<n;i++){
        if(max_pq.empty())
    		max_pq.push(arr[i]);
        else
        {
            if(arr[i]>max_pq.top())
                min_pq.push(arr[i]);
            else
                max_pq.push(arr[i]);
        }
        if((max_pq.size()-min_pq.size())>1){
            if(max_pq.size()>min_pq.size()){
                min_pq.push(max_pq.top());
                max_pq.pop();
            }
            else{
                max_pq.push(min_pq.top());
                min_pq.pop();
            }
        }

        int size=max_pq.size()+min_pq.size();
        if(size%2==0){
            int med=(max_pq.top()+min_pq.top())/2;
            cout<<med<<" ";
        }
        else
        {
            if(max_pq.size()>min_pq.size())
                cout<<max_pq.top()<<" ";
            else
                cout<<min_pq.top()<<" ";
        }
    }
}
    int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}