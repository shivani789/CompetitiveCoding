#include<bits/stdc++.h>
using namespace std;
template<typename T>
class QueueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
public:
    QueueUsingArray(int s)
    {
        data=new T[s];
        firstIndex=-1;
        nextIndex=0;
        capacity=s;
        size=0;
    }
    int getSize(){
        return size;
    }
    bool IsEmpty(){
        return size==0;
    }
    void enqueue(T element)
    {
        if(size==capacity)
        {
            cout<<"Queue Full"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;
        size++;
        if(firstIndex==-1)
            firstIndex=0;
    }
    T front(){
        if(IsEmpty())
        {
            cout<<"Queue Full"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue(){
        if(IsEmpty())
        {
            cout<<"Queue Full"<<endl;
            return 0;
        }
        T ans=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        if(size==0)
        {
            firstIndex=-1;
            nextIndex=0;
        }

        return ans;
    }
};
int main()
{
    QueueUsingArray<int> s(5);
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    s.enqueue(50);
    s.enqueue(60);
    s.enqueue(70);
    cout<<s.front()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.IsEmpty()<<endl;
}
