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