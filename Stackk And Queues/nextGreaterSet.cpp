// next greater element to right 

vector<int> ngor (vector<int>&arr)
{
    int n=arr.size();
    vector<int> ans(n, n);
    stack<int> s;
    s.push(-1);
    for(int i=0;i<n;i++)
    {
        while(s.top()!=-1 and arr[st.top()]< st.top())
        {
            ans[s.pop()]=i;
        }
        s.push(i);
    }
    return ans;
}

// next greater on left  

vector<int> ngol (vector<int>&arr)
{
    int n=arr.size();
    vector<int> ans(n, -1);
    stack<int> s;
    s.push(-1);
    for(int i=n-1;i>=0;i++)
    {
        while(s.top()!=-1 and arr[st.top()]< st.top())
        {
            ans[s.pop()]=i;
        }
        s.push(i);
    }
    return ans;
}

// next smaller on right

vector<int> ngor (vector<int>&arr)
{
    int n=arr.size();
    vector<int> ans(n, -1);
    stack<int> s;
    s.push(-1);
    for(int i=0;i<n;i++)
    {
        while(s.top()!=-1 and arr[st.top()]> st.top())
        {
            ans[s.pop()]=i;
        }
        s.push(i);
    }
    return ans;
}

// ------------------------ LEETCODE --------------------//

//503. Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
    int n=arr.size();
    vector<int> ans(n, -1);
    stack<int> s;
    s.push(-1);
    for(int i=0;i<n*2;i++)
    {
        while(s.top()!=-1 and arr[s.top()]< arr[i%n])
        {
            ans[s.top()]=arr[i%n];
            s.pop();
        }
        s.push(i%n);
    }
    return ans;
    }
};

// Stock span problem 
// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       // Your code here
       vector<int> ans(n);
       stack<int> s;
       
       s.push(-1);
       for(int i=0;i<n;i++)
       {
           while(s.top()!=-1 and arr[s.top()]<=arr[i])
           {
               s.pop();
           }
           ans[i]=i-s.top();
           s.push(i);
       }
       return ans;
       
    }
};

// 901. Online Stock Span
// https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    stack<pair<int,int>> s;
    int day=0;
    StockSpanner() {
        s.push({-1,-1});
    }
    
    int next(int price) {
        while(s.top().first!=-1 and s.top().second <=price)
            s.pop();
        int span=day-s.top().first;
        s.push({day++, price});
        return span;
    }
};

// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    stack<char> st;
    bool isValid(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(st.empty() or s[i]=='(' or s[i]=='{' or s[i]=='[')
                st.push(s[i]);
            else if(s[i]==')' and st.top()=='(')
                st.pop();
            else if(s[i]==']' and st.top()=='[')
                st.pop();
            else if(s[i]=='}' and st.top()=='{')
                st.pop();
            else
                st.push(s[i]);
        }
        if(st.empty()) return true;
        return false;
    }
};

// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans(temperatures.size(), 0);
        for(int i=0;i<temperatures.size();i++)
        {
            while(!s.empty() and temperatures[s.top()]<temperatures[i])
            {
                ans[s.top()]= i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};

// 735. Asteroid Collision
// https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        stack<int> s;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>0)
            {
                s.push(arr[i]);
                continue;
            }
            while(s.size()!=0 and s.top()>0 and s.top()<abs(arr[i]))
                s.pop();
            if(s.size()!=0 and s.top()==abs(arr[i])) s.pop();
            else if(s.size()==0  or s.top()<0){
                s.push(arr[i]);
            }
            else
            {
                // nothing to do 
            }
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
         reverse(ans.begin(),ans.end());
        return ans;
    }
};

// 946. Validate Stack Sequences
// https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0;
        for(auto ele: pushed)
        {
            s.push(ele);
            while(!s.empty() and s.top()==popped[i])
            {
                s.pop();
                i++;
            }
        }
        if(!s.size()) return true;
        return false;
    }
};

// 856. Score of Parentheses
// https://leetcode.com/problems/score-of-parentheses/
// ye wala sol clear nhi h abhi mera
class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<int> s;
        int curr=0;
        for(auto ele: str)
        {
            if(ele=='(')
            {
                s.push(curr);
                curr=0;
            }
            else
            {
                curr+=s.top()+ max(curr, 1);
                s.pop();
            }
        }
        return curr;
    }
};