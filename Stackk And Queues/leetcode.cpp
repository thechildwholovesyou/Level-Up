// 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/
// BY MAKING PUSH OPERATION COSTYLY O(N) AND POP OPERAION IN O(1)

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
       return q1.empty(); 
    }
};


// By making pop operation costly 

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
       q1.push(x); 
    }
    
    int pop() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();
        q1.pop();
        swap(q1,q2);
        return x;
    }
    
    int top() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();
        q1.pop();
        q2.push(x);
        swap(q1, q2);
        return x;
    }
    
    bool empty() {
       return q1.size()==0; 
    }
};

// using only 1 queue

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int size= q.size();
        q.push(x);
        while(size--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

