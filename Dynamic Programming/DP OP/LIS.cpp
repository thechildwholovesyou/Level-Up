// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/
// rec
class Solution {
public:
    int helper(vector<int>&nums, int prev,int curr)
    {
        int maxi=INT_MIN;
        if(curr==nums.size()) return 0;
        int op1=0;
        if(prev==-1 || nums[prev]<nums[curr])
            op1=helper(nums, curr,curr+1)+1;
        int op2=helper(nums, prev, curr+1);
        return max(op1, op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums,-1, 0);
        
    }
};

// memo 

class Solution {
public:
    int helper(vector<int>&nums, int prev,int curr,vector<vector<int>>&dp)
    {
        int maxi=INT_MIN;
        if(curr==nums.size()) return 0;
        if(prev!=-1 and dp[prev][curr]!=0) return dp[prev][curr];
        int op1=0;
        if(prev==-1 || nums[prev]<nums[curr])
            op1=helper(nums, curr,curr+1,dp)+1;
        int op2=helper(nums, prev, curr+1,dp);
        if(prev!=-1)
            dp[prev][curr]=max(op1, op2);
        return max(op1, op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1, vector<int> (nums.size()+1,0));
        return helper(nums,-1, 0,dp);
        
    }
};

// tabu 

class Solution {
public:
    int helper(vector<int>&nums, vector<int>&dp)
    {
        dp[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            int maxi =0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    maxi=max(maxi,dp[j]);
                }
            }
            dp[i]=maxi+1;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int> dp(n+1, 0);
        return helper(nums, dp);
    }
};