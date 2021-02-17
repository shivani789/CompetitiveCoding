#include<bits/stdc++.h>
using namespace std;
class stack_array{
    int *data;
    int nextIndex;
    int capacity;
public:
    stack_array(int totalSize){
        data = new int[totalSize];
        nextIndex=0;
        capacity=totalSize;
    }
    int size(){
        return nextIndex;
    }
    bool IsEmpty(){
        return nextIndex==0;
    }
    void push(int element){
        if(nextIndex==capacity)
            return;
        data[nextIndex]=element;
        nextIndex++;
    }
    int pop(){
        if(IsEmpty()){
            cout<<"Stack is empty";
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top(){
        return data[nextIndex-1];
    }

};
int main()
{
    stack_array s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.IsEmpty()<<endl;
}
