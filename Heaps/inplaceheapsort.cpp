#include <bits/stdc++.h>
using namespace std;
void insert(int arr[],int i,int x){
    arr[i]=x;
    
    int child=i;
    int parent=(i-1)/2;
    while(child>0 && arr[child]<arr[parent]){
        
        //swap(arr[child],arr[parent]);
        int t=arr[child];
        arr[child]=arr[parent];
        arr[parent]=t;
        
        child=parent;
        parent=(child-1)/2;
    }
}
void remove(int arr[],int i){
    int x=arr[0];
    arr[0]=arr[i];
    arr[i]=x;
    
    int last=i;
    int parent=0;
    int left=2*parent+1;
    int right=2*parent+2;
    
    while(left<last){
        int minInd=parent;

        if(arr[left]<arr[minInd])
            minInd=left;
        if(right<last && arr[right]<arr[minInd])
            minInd=right;
        
        if(minInd==parent)
            break;
        
        //swap(arr[parent],arr[minInd]);
        int t=arr[parent];
        arr[parent]=arr[minInd];
        arr[minInd]=t;
        
        parent=minInd;
        left=2*parent+1;
        right=2*parent+2;
    }
}
void heapSort(int arr[], int n) {
    // Write your code
    for(int i=1;i<n;i++){
        insert(arr,i,arr[i]);
    }
    for(int i=n-1;i>=0;i--){
        remove(arr,i);
    }
}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}