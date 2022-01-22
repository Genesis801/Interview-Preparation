#include <bits/stdc++.h>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>> input) {
    // Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<input.size();i++){
        
        for(int j=0;j<input[i].size();j++){
            pq.push(input[i][j]);
        }
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main() {
    int k;
    cin >> k;

    vector<vector<int> > input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> current;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current.push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}