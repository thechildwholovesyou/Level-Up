// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

// rec 

class Solution {
public:
    
    int lengthOfLIS_rec(int prev, int curr,vector<int>& nums)
    {
        if(curr<0) return 0;
        int op1=0;
        if(prev==-1 or nums[curr]<nums[prev])
        {
            op1=1+lengthOfLIS_rec(curr,curr-1,nums);
        }
        int op2=lengthOfLIS_rec(prev,curr-1,nums);
        
        return max(op1,op2);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLIS_rec(-1,nums.size()-1,nums);
    }
};

// memo code 

class Solution {
public:
    
    int lengthOfLIS_memo(int curr, int prev, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(curr==nums.size())
            return 0;
        
        if(prev!=-1 and dp[prev][curr]!=0)
            return dp[prev][curr];
        
        int op1=0;
        
        if(prev==-1 or nums[prev]<nums[curr])
        {
            op1=lengthOfLIS_memo(curr+1, curr, nums, dp)+1;
        }
        int op2= lengthOfLIS_memo(curr+1, prev, nums, dp);
        
        
        if(prev!=-1)
            dp[prev][curr]=max(op1,op2);
        return max(op1, op2);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), 0));
        return lengthOfLIS_memo(0, -1,nums, dp);
    }
};