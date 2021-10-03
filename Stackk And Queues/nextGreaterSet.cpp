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
}

// next smaller on right 

