#include<bits/stdc++.h>
using namespace std;
class MaxPriorityQueue{
    vector<int> pq;
    public:
    MaxPriorityQueue(){

    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty())
            return -1;
        else
            return pq[0];
    }
    void insert(int x){
        pq.push_back(x);

        int childInd=pq.size()-1;
        int parentInd=(childInd-1)/2;

        while(childInd>0 && pq[childInd]>pq[parentInd]){
            swap(pq[childInd],pq[parentInd]);
            
            childInd=parentInd;
            parentInd=(childInd-1)/2;
        }
    }
    int removeMax(){
        if(isEmpty())
            return INT_MIN;
        int x=pq[0];
        int lastInd=pq.size()-1;
        swap(pq[0],pq[lastInd]);
        pq.pop_back();

        int parentInd=0;
        int leftInd=2*parentInd+1;
        int rightInd=2*parentInd+2;

        while(leftInd<=lastInd){
            int maxInd=parentInd;
            
            if(pq[leftInd]>pq[maxInd])
                maxInd=leftInd;
            if(rightInd<=lastInd && pq[rightInd]>pq[maxInd])
                maxInd=rightInd;
            if(maxInd==parentInd)
                break;
            
            swap(pq[parentInd],pq[maxInd]);
            
            parentInd=maxInd;
            leftInd=2*parentInd+1;
            rightInd=2*parentInd+2;
        }
        return x;
    }
};