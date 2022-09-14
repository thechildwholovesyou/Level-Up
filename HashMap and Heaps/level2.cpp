// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cs=0;
        int cnt=0;
        unordered_map<int, int> m;
        for(auto ele: nums)
        {
            cs+=ele;
            if(cs==k) cnt++;
            if(m.find(cs-k)!=m.end())
                cnt+=m[cs-k];
            m[cs]++;
        }
        return cnt;
    }
};

// 974. Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt=0;
        int cs=0;
        unordered_map<int, int> m;
        for(auto ele: nums)
        {
            cs+=ele;
            
            int rem=cs%k;
            
            if(rem<0) rem+=k;
            
            if(rem==0)
                cnt++;
            if(m.find(rem)!=m.end())
                cnt+=m[rem];
            m[rem]++;
        }
        return cnt;
    }
};

// Subarrays with equal 1s and 0s
// https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        unordered_map<int, int> m;
        int cnt=0;
        int cs=0;
        
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
                cs+=1;
            else
                cs+=-1;
            if(cs==0) cnt++;
            if(m.find(cs-k)!=m.end())
                cnt+=m[cs-k];
            m[cs]++;
        }
        return cnt;
    }
};

// 525. Contiguous Array
// https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> m;
        m[0]=-1;
        int len=0;
        
        int cs=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                cs+=1;
            else
                cs-=1;
            if(m.find(cs)!=m.end())
            {
                len = max(len, i-m[cs]);
            }
            else
                m[cs]=i;
        }
        return len;
    }
};

// Count Substrings with equal number of 0s, 1s and 2s
// https://practice.geeksforgeeks.org/problems/equal-0-1-and-23208/1

class Solution {
  public:
    long long getSubstringWithEqual012(string s) {
        // code here
        map<pair<int, int>, int> m;
        int zc=0, oc=0, tc=0;
        int n=s.size();
        m[make_pair(0, 0)] = 1;
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                zc++;
            else if(s[i]=='1')
                oc++;
            else
                tc++;
        
            pair<int,int> p= make_pair(zc-oc, zc-tc);
            
            if(m.find(p)!=m.end())
                cnt+=m[p];
                
            m[p]++;
        
        }
        return cnt;
    }
};

// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        if(n==0) return 0;
        map<int,int> m;
        for(auto ele: nums) m[ele]++;
        
        int cnt=1;
        int maxi=1;
        for(auto ele: m)
        {
            if(m.find(ele.first+1)!=m.end())
            {
                cnt++;
                maxi=max(maxi,cnt);
            }
               
            else
                cnt=1;
        }
        return maxi;
    }
};

