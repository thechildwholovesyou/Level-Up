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

// 1642. Furthest Building You Can Reach
// https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution {
public:
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<heights.size()-1;i++)
        {
            int diff=heights[i+1]-heights[i];
            if(diff>0)
                pq.push(diff);
            if(pq.size()>ladders)
            {
                bricks-=pq.top();
                pq.pop();
            }
            if(bricks<0)
                return i;
        }
        return heights.size()-1;
    }
};

// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/
// uisng min heap 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto ele: nums)
            pq.push(ele);
        
        int cnt=1;
        int maxCnt=0;
        int prev=pq.top();
        pq.pop();
        while(pq.size()!=0)
        {
          
            int curr= pq.top();
            pq.pop();
            
            if(abs(prev-curr)==1 or abs(prev-curr)==0)
            {
                if(abs(prev-curr)==1) cnt++;
            }
            else
                cnt=1;
            maxCnt=max(maxCnt, cnt);
            prev=curr;
        }
        return maxCnt;
    }
};

// using sets 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto ele: nums)
            pq.push(ele);
        
        int cnt=1;
        int maxCnt=0;
        int prev=pq.top();
        pq.pop();
        while(pq.size()!=0)
        {
          
            int curr= pq.top();
            pq.pop();
            
            if(abs(prev-curr)==1 or abs(prev-curr)==0)
            {
                if(abs(prev-curr)==1) cnt++;
            }
            else
                cnt=1;
            maxCnt=max(maxCnt, cnt);
            prev=curr;
        }
        return maxCnt;
    }
};

// 632. Smallest Range Covering Elements from K Lists
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int n=nums.size();
        // {ele,r,c}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
         
        
        int maxValue = -(int)1e9;
        
        for(int i = 0; i < n;i++){
            pq.push({nums[i][0], i,0});
            maxValue = max(maxValue, nums[i][0]);
        }
        
        int range = (int)1e9, sp = -1, ep = -1;
        while(pq.size() == n){
            
            vector<int> temp=pq.top();
            pq.pop();
            int r = temp[1], c = temp[2], val = nums[r][c];
            
            if(maxValue - val < range){
                range = maxValue - val;
                sp = val;
                ep =  maxValue;
            }
            
            c++;
            if(c < nums[r].size()){
                pq.push({nums[r][c],r,c});
                maxValue = max(maxValue, nums[r][c]);
            }
        }
        
        vector<int> v{sp,ep};
        return v;
        
    }
};


// 1218. Longest Arithmetic Subsequence of Given Difference
// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

// using LIS : dp , giving TLE

class Solution {
public:
    int lengthOfLIS_memo(int curr, int prev, vector<int>&nums, vector<vector<int>>&dp,int diff)
    {
        if(curr==nums.size())
            return 0;
        
        if(prev!=-1 and dp[prev][curr]!=0)
            return dp[prev][curr];
        
        int op1=0;
        
        if(prev==-1 or (nums[curr]-nums[prev]==diff))
        {
            op1=lengthOfLIS_memo(curr+1, curr, nums, dp,diff)+1;
        }
        int op2= lengthOfLIS_memo(curr+1, prev, nums, dp,diff);
        
        
        if(prev!=-1)
            dp[prev][curr]=max(op1,op2);
        return max(op1, op2);
    }
    
    int longestSubsequence(vector<int>& nums, int difference) {
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), 0));
        return lengthOfLIS_memo(0, -1,nums, dp, difference);
    }
};


//  hashmap wali approach 
class Solution {
public:
    int longestSubsequence(vector<int>& nums, int d) {
        map<int,int> m;
        int maxLen=0;
        for(auto ele: nums)
        {
            if(m.find(ele-d)!=m.end())
                m[ele]=m[ele-d]+1;
            else
                m[ele]=1;
            maxLen=max(maxLen ,m[ele]);
        }
        return maxLen;
    }
};

// shortcut 
class Solution {
public:
    int longestSubsequence(vector<int>& nums, int d) {
        map<int,int> m;
        int maxLen=0;
        for(auto ele: nums)
        {
            m[ele]=m[ele-d]+1;
            maxLen=max(maxLen ,m[ele]);
        }
        return maxLen;
    }
};
// question : LIS ko hashmap se kyo nhi karskte ?
// ans: usme hme greater than dekhna h, to wo possible nhi ho payega 


// 781. Rabbits in Forest
// https://leetcode.com/problems/rabbits-in-forest/
// sumeet sir wali approach

class Solution {
public:
    int numRabbits(vector<int>& nums) {
        map<int,int> m; // freq map 
        for(auto ele:nums)
            m[ele]++;
        int ans=0;
        for(auto ele:m)
        {
            int group_size=ele.first+1;
            int reportees=ele.second;
            int n=ceil(reportees*1.0/ group_size*1.0); // n => no of groups
            ans+=group_size*n;
        }
        return ans;
    }
};

// 1424. Diagonal Traverse II
// https://leetcode.com/problems/diagonal-traverse-ii/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int> >m;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<nums[i].size();j++)
        {
            m[i+j].push_back(nums[i][j]);
        }
    }
   
        vector<int> ans;
        int n=m.size();
        for(int i=0;i<=n;i++)
        {
            for(auto x=m[i].rbegin();x!=m[i].rend();x++)
                ans.push_back(*x);
        }
        return ans;
    }
};

// 954. Array of Doubled Pairs
// https://leetcode.com/problems/array-of-doubled-pairs/

bool cmp(int a,int b){
    return abs(a)<abs(b);
}

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
       
        if(arr.size()%2!=0) return false;
        map<int,int> m;
        for(auto ele:arr)
            m[ele]++;
        
        sort(arr.begin(),arr.end(),cmp);
        
        for(auto ele: arr)
            cout<<ele<<" ";
        cout<<endl;
        
        for(int i=0;i<arr.size();i++)
        {
            if(m[arr[i]]>0 and m[2*arr[i]]>0)
            {
                m[arr[i]]--;
                m[2*arr[i]]--;
            }
            else if(m[arr[i]]> 0 and m[2*arr[i]]<=0)
                return false;
        }
        return true;
    }
};

// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>, greater<int>> minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxpq.size()==0 or num<=maxpq.top())
            maxpq.push(num);
        else
            minpq.push(num);
        
        if(maxpq.size()-minpq.size()==2)
        {
            int temp=maxpq.top();
            maxpq.pop();
            minpq.push(temp);
        }
        if(maxpq.size()-minpq.size()==-1)
        {
            int temp=minpq.top();
            minpq.pop();
            maxpq.push(temp);
        }
    }
    
    double findMedian() {
        if(maxpq.size()==minpq.size())
        {
            return (maxpq.top()+minpq.top())/2.0;
        }
        else
            return maxpq.top()*1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */