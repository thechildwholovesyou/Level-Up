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



//
// https://leetcode.com/problems/implement-queue-using-stacks/

// POP operation costly 

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
         while(!s1.empty())
        {
            s2.push(s1.top());
             s1.pop();
        }
        int x=s2.top();
        s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
    
    int peek() {
         while(!s1.empty())
        {
            s2.push(s1.top());
             s1.pop();
        }
        int x=s2.top();
        
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
    
    bool empty() {
        if(s1.size()==0) return true;
        return false;
    }
};

// push operaion costly 

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s1.empty()){
            int x=s1.top();
            s2.push(x);
            s1.pop();
        }
        s2.push(x);
        while(!s2.empty()){
            int x=s2.top();
            s1.push(x);
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x=s1.top();
        s1.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (s1.size()==0);
    }
};

