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