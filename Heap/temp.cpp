// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq; // min heap 
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};

// 1985. Find the Kth Largest Integer in the Array
// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
// Brute force method

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(stoi(nums[i]));
            if(pq.size()>k)
                pq.pop();
        }
        return to_string(pq.top());
    }
};

// Optimised Method 

class Solution {
public:
    
    class comparator{
        public:
        bool operator()(const string &a,const string &b){
            if(a.length()==b.length())
                return a>b;
            return a.length()>b.length();
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, comparator>pq; // min heap custom
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()> k)
                pq.pop();
        }
        return pq.top();
    }
};

// K largest elements 
// https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1#

class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int,vector<int>, greater<int>> pq;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        for(int i=k-1;i>=0;i--)
        {
            v.push_back(pq.top());
            pq.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

// 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/
class Compare{
    public:
    bool operator()(const vector<int>&v1, const vector<int>&v2)
    {
        return (v1[0] * v1[0] + v1[1] * v1[1]) > (v2[0] * v2[0] + v2[1] * v2[1]);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <vector<int>, vector<vector<int>>, Compare > p;
        
        for(auto ele:points)
            p.push(ele);
        
        vector<vector<int>> v;
        
        while(k--)
        {
            v.push_back(p.top());
            p.pop();
        }
        return v;
    }
};

// Nearly Sorted Algorithm 
// https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0#

#include<bits/stdc++.h>
using namespace std;

vector<int>  sortKsorted(vector<int>&v, int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>ans;
    for(auto ele: v)
    {
        pq.push(ele);
        if(pq.size()>k)
        {
            ans.push_back(ele);
            pq.pop();
        }
    }
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int data;
            cin>>data;
            v.push_back(data);
        }
        int k;
        cin>>k;
        
        vector<int> ans = sortKsorted(v,k);
        for(auto ele: ans)
            cout<<ele<<" ";
        cout<<endl;
    }
    return 0;
}

// K closest elements
// https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1

class Solution{   
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
       priority_queue<pair<int,int>> pq;
       for(auto ele: arr)
       {
           pq.push({abs(ele-x),ele});
           
           if(pq.size()>k)
           {
               pq.pop();
           }
       }
       vector<int> ans;
       while(!pq.empty())
       {
           ans.push_back(pq.top().second);
           pq.pop();
       }
      sort(ans.begin(),ans.end());
       
       return ans;
        
    }
};
