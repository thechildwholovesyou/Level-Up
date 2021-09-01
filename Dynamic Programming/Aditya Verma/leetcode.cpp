// 416. Partition Equal Subset Sum

// https://leetcode.com/problems/partition-equal-subset-sum/

// rec code 
class Solution {
public:
    
    bool subsetSum_rec(vector<int>&nums, int sum,int n)
    {
        if(sum==0) return true;
        if(n==0) return false;
        bool ans=false;
        if(nums[n-1]<=sum)
        {
            bool a1=subsetSum_rec(nums,sum-nums[n-1],n-1);
            bool a2=subsetSum_rec(nums,sum,n-1);
            
            ans=a1 or a2;
        }
        else if(nums[n-1]>sum)
            return subsetSum_rec(nums,sum,n-1);
        return ans;
    }
    
    bool findPartition(vector<int>&nums)
    {
        int n=nums.size();
        int sum=0;
        for(auto ele: nums)
            sum+=ele;
        if(sum%2!=0)
            return false;
        return subsetSum_rec(nums,sum/2,n);
    }
    
    bool canPartition(vector<int>& nums) {
        return findPartition(nums);
    }
};

// mem code 

class Solution {
public:
    
    bool subsetSum_mem(vector<int>&nums, int sum,int n,vector<vector<int>>&dp)
    {
        if(sum==0) return true;
        if(n==0) return false;
        bool ans=false;
        
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        if(nums[n-1]<=sum)
        {
            bool a1=subsetSum_mem(nums,sum-nums[n-1],n-1,dp);
            bool a2=subsetSum_mem(nums,sum,n-1,dp);
            
            ans=a1 or a2;
            dp[n][sum]=ans;
        }
        else if(nums[n-1]>sum)
            return dp[n][sum]= subsetSum_mem(nums,sum,n-1,dp);
        return dp[n][sum];
    }
    
    bool findPartition(vector<int>&nums)
    {
        int n=nums.size();
        int sum=0;
        for(auto ele: nums)
            sum+=ele;
        if(sum%2!=0)
            return false;
        vector<vector<int>> dp( n+1 , vector<int> (sum/2+1, -1));
        return subsetSum_mem(nums,sum/2,n,dp);
    }
    
    bool canPartition(vector<int>& nums) {
        return findPartition(nums);
    }
};

// tabu code 

class Solution {
public:
    
    bool subsetSum_tabu(vector<int>&nums, int sum,int n,vector<vector<bool>>&dp)
    {
   
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<sum;j++)
            {
                if(i==0)
                    dp[i][j]=false;
                if(j==0)
                    dp[i][j]=true;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                {
                    bool a1=dp[i-1][j-nums[i-1]];
                    bool a2=dp[i-1][j];
                    dp[i][j]=a1 or a2;
                }
                else if(nums[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
        
    }
    
    bool findPartition(vector<int>&nums)
    {
        int n=nums.size();
        int sum=0;
        for(auto ele: nums)
            sum+=ele;
        if(sum%2!=0)
            return false;
        vector<vector<bool>> dp( n+1 , vector<bool> (sum/2+1, false));
        return subsetSum_tabu(nums,sum/2,n,dp);
    }
    
    bool canPartition(vector<int>& nums) {
        return findPartition(nums);
    }
};