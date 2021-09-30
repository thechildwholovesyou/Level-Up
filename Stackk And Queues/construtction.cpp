#include<bits/stdc++.h>
using namespace std;
class Stack{
    private:
    vector<int> v;
    public: 
    void push(int data)
    {
        v.push_back(data);
    }
    bool empty(){
        return v.size()==0;
    }
    void pop(){
        if(!empty){
            v.pop_back();
        }
    }
    int top(){
        return v[v.size()-1];
    }
};
int main()
{
    Stack s;
    for(int i=0;i<6;i++)
    {
        s.push(i*i);
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}

// construction using arrays 

#include<bits/stdc++.h>
using namespace std;
#define max 100

class Stack{
    public:
    int top;
    int arr[max];

    void push(int data){
        if(top==max){
            cout<<"Stack overflow"<<endl;
            return;
        }
        else
        {
            top++;
            arr[top]=data;
        }
    }
    void peek(){
        if(top==-1){
            cout<<"Stack underflowed"<<endl;
            return;
        }
        cout<<arr[top];
    }
    void pop(){
        if(top==-1){
            cout<<"Stack underflowed"<<endl;
            return;
        }
        else{
            cout<<arr[top]<<endl;
            top--;
        }
    }
    bool empty(){
        if(top==0) return true;
        else
        return false;
    }
    Stack(){
        top=-1;
    }
};

int main()
{
    Stack s;
    for(int i=0;i<6;i++){
        s.push(i*i);
    }

    while(!s.empty()){
        s.pop();
    }
    return 0 ;
}