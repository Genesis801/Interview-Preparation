#include<vector>
using namespace std;
class MinPriorityQueue{
    vector<int> pq;
    public:
        MinPriorityQueue(){

        }
        bool isEmpty(){
            return pq.size()==0;
        }
        int getSise(){
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
            while(childInd>0 && pq[childInd]<pq[parentInd]){
                swap(pq[childInd],pq[parentInd]);

                childInd=parentInd;
                parentInd=(childInd-1)/2;
            }
        }
        int removeMin(){
            if(isEmpty())
                return -1;
            int x=pq[0];
            int lastInd=pq.size()-1;
            swap(pq[0],pq[lastInd]);
            pq.pop_back();

            int parentInd=0;
            int leftChild=2*parentInd+1;
            int rightChild=2*parentInd+2;
            
            while(leftChild<=lastInd){
                int minInd=parentInd;

                if(pq[leftChild]<pq[minInd])
                    minInd=leftChild;
                if(rightChild<=lastInd && pq[rightChild]<pq[minInd])
                    minInd=rightChild;
                if(minInd==parentInd)
                    break;

                swap(pq[parentInd],pq[minInd]);
                
                parentInd=minInd;
                leftChild=2*parentInd+1;
                rightChild=2*parentInd+2;
            }
            return x;
        }
};