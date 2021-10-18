// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int> m;
        for(auto ele: nums){
            m[ele]++;
        }
        
        for(auto ele: m){
            pq.push({ele.second, ele.first});
        }
        
        vector<int> v;
        while(k--){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};

// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/submissions/

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        map<char, int> m;
        for(auto ele:s){
            m[ele]++;
        }
        
        for(auto ele: m){
            pq.push({ele.second, ele.first});
        }
        string ans="";
        while(!pq.empty())
        {
            auto n=pq.top();
            while(n.first--){
                ans+=n.second;
            }
            pq.pop();
        }
        return ans;
    }
};

// 1636. Sort Array by Increasing Frequency
// https://leetcode.com/problems/sort-array-by-increasing-frequency/

struct compare{
     bool operator()(pair<int,int> p1,pair<int,int> p2){
        if (p1.first==p2.first){
            return p1.second<p2.second;
        }
        else{
            return p1.first>p2.first;
        }
    }
    };

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue <pair<int,int>, vector<pair<int,int>>, compare > pq;
        map<int, int> m;
        for(auto ele:nums){
            m[ele]++;
        }
        
        for(auto ele: m){
            pq.push({ele.second, ele.first});
        }
       vector<int> ans;
        while(!pq.empty())
        {
            auto n=pq.top();
            while(n.first--){
                ans.push_back(n.second);
            }
            pq.pop();
        }
        return ans;
    }
};

// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int, int>> m;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<s.size();i++){
            char ele=s[i];
            m[ele].first++;
            m[ele].second=i;
        }
        for(auto ele:m){
            if(ele.second.first==1)
                pq.push(ele.second.second);
        }
        
        if(pq.empty())
            return -1;
        return pq.top();
    }
};

// 1497. Check If Array Pairs Are Divisible by k
// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> m;
        for(auto ele: arr)
        {
            int rem=ele%k;
            rem=(rem+k)%k;
            m[rem]++;
        }
        for(auto ele: arr)
        {
            int rem=ele%k;
            rem=(rem+k)%k;
            
            if(rem==0)
            {
                int freq=m[rem];
                if(freq%2!=0)
                    return false;
            }
            else if(2*rem==k){
                int freq=m[rem];
                if(freq%2!=0) return false;
            }
            else
            {
                int f1=m[rem];
                int f2=m[k-rem];
                
                if(f1!=f2) return false;
            }
        }
        return true;
    }
};

// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

// approach 1  
// TC : Nlog(N)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;// min heap
        for(auto i : nums) pq.push(i);
        while(pq.size() > k) pq.pop(); 
        return pq.top();
    }
};

// approach 2 
// TC : Nlog(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};

// optimal sol 
// 


// Kth smallest element
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int size=(r-l)+1;
        priority_queue<int>pq;// min heap
        for(int i=0;i<size;i++)
            pq.push(arr[i]);
        while(pq.size() > k) pq.pop(); 
        return pq.top();
    }
};


// 378. Kth Smallest Element in a Sorted Matrix
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& points, int k) {
       
        priority_queue <int > p;
        for(int i=0;i<points.size();i++)
        {
            for(int j=0;j<points[0].size();j++)
            {
                p.push(points[i][j]);
            }
        }
        while(p.size()!=k)
        {
            p.pop();
        }
        return p.top();
    }
};

// better sol

class Solution {
public:
    int kthSmallest(vector<vector<int>>& points, int k) {
       
        priority_queue <int > p;
        for(int i=0;i<points.size();i++)
        {
            for(int j=0;j<points[0].size();j++)
            {
                p.push(points[i][j]);
                if(p.size()>k) p.pop();
            }
        }
       
        return p.top();
    }
};


// best sol
// Time: O(K * logK)
// Space: O(K)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // {ele, i,j}
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++)
            pq.push({matrix[i][0],i,0});
        
        int r=0,c=0;
        int ans=0;
        while(k--)
        {
            auto ele=pq.top();
            pq.pop();
            r=ele[1];
            c=ele[2];
            ans=ele[0];
            if(c+1<n)
                pq.push({matrix[r][c+1],r,c+1});
        }
        return ans;
    }
};

// 703. Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto ele:nums)
        {
            pq.push(ele);
            if(pq.size()>K)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

// TC : O(nlogK)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        map<int,int> m;
        for(auto ele: nums){
            m[ele]++;
        }
        
        for(auto ele: m){
            pq.push({ele.second, ele.first});
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<int> v;
       
        while(pq.size()!=0)
        {
            int num=pq.top().second;
            v.push_back(num);
            pq.pop();
        }
        return v;
    }
};

// 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/submissions/

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

// optimised


class Compare{
    public:
    bool operator()(const vector<int>& v1, const vector<int>& v2){
        return (v1[0]*v1[0] +v1[1]*v1[1]) < (v2[0]*v2[0] +v2[1]*v2[1]); 
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> v;
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
       
        for(auto ele: points)
        {
            pq.push(ele);
            if(pq.size()> k)
            {
                pq.pop();
            }
        }
        
        while(!pq.empty())
        {
            auto ele=pq.top();
            v.push_back(ele);
            pq.pop();
        }
        return v;
    }
};

// 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/

class cmp{
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) const{
        //return a.first > b.first || (a.first == b.first && a.second < b.second);
        if(a.first ==b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto ele: words)
        {
            m[ele]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        vector<string> ans;
        
        for(auto ele: m)
        {
            pq.push({ele.second, ele.first});
            if(pq.size()>k)
                pq.pop();
        }
        
        while(!pq.empty())
        {
            ans.insert(ans.begin(),pq.top().second);
            pq.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};