// Program to implement a stack using arrays
#include<bits/stdc++.h>
using namespace std;
void push(vector<int>& stack, int x){
    stack.push_back(x);
    return;
}
void pop(vector<int>&stack){
    stack.pop_back();
    return;
}
int main(){
    vector<int> stack;
    char ch = 'y';
    do{
        cout<<"1. Push\n2. Pop\n3. Top\n4. Size"<<endl;
        int n;
        cin>>n;
        switch (n)
        {
        case 1:
            int x;
            cin>>x;
            push(stack,x);
            break;
        case 2:
            if(stack.size()==0)
            {    
                cout<<"Stack Underflow"<<endl;
                break;
            }
            pop(stack);
            break;
        case 3:
            cout<<stack[stack.size()-1]<<endl;
            break;
        case 4:
            cout<<stack.size()<<endl;
        default:
            break;
        }
        cout<<"press n if you want to stop."<<endl;
        cin>>ch;
    }while(ch=='y');
}