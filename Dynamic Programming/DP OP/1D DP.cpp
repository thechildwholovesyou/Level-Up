
// https://leetcode.com/problems/climbing-stairs/

// REC 

class Solution {
public:
    int helper(int n)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int op1= helper(n-1);
        int op2=helper(n-2);
        return op1+op2;
        
    }
    int climbStairs(int n) {
      return helper(n);  
    }
};

// Optmised
class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
       
        for(int i=0;i<=n;i++)
        {
            if(i<=2)
            {
                dp[i]=i;
                continue;
            }
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
    int climbStairs(int n) {
        if(n==0 or n==1 or n==2) return n;
        vector<int>dp(n+1, 0);
      return helper(n,dp);  
    }
};

// 

// rec 
class Solution {
public:
    int helper(vector<int>&cost, int idx)
    {
        if(idx>=cost.size()) return 0;
        int mini =INT_MAX;
        int op1=helper(cost, idx+1)+cost[idx];
        int op2=helper(cost, idx+2)+cost[idx];
        return min(op1, op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int op1= helper(cost,0);
        int op2=helper(cost,1);
        return min(op1, op2);
    }
};

// optimised

class Solution {
public:
    int helper(vector<int>&cost, int idx,vector<int>&dp)
    {
        if(idx>=cost.size()) return 0;
        if(dp[idx]) return dp[idx];
        int op1=helper(cost, idx+1,dp)+cost[idx];
        int op2=helper(cost, idx+2,dp)+cost[idx];
        return dp[idx]=min(op1, op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1, 0);
        int op1= helper(cost,0,dp);
        int op2=helper(cost,1,dp);
        return min(op1, op2);
    }
};

// https://leetcode.com/problems/divisor-game/

// very simple sol 
class Solution {
public:
    bool divisorGame(int n) {
        return n%2==0;
    }
};

// rec

class Solution {
public:
    bool divisorGame(int n) {
        if(n==1) return false;
        if(n==2) return true;
        
        for(int i=1;i<=n;i++)
        {
            if(n%i==0) 
                return !(divisorGame(n-i));
        }
        return false;
    }
};

// https://leetcode.com/problems/decode-ways/

// rec 

class Solution {
public:
    
    int numDecodings_rec(string s)
    {
        if(s.size()==0)
        {
            return 1;
        }
        char ch=s[0];
        if(ch=='0')
            return 0;
        
        int count=0;
        count+=numDecodings_rec(s.substr(1));
        
        if(s.size()>1)
        {
            int num=(ch-'0')*10+(s[1]-'0');
            if(num<=26)
            {
                count+=numDecodings_rec(s.substr(2));
            }
        }
        return count;
    }
    
    int numDecodings(string s) {
        if(s.size()==0)
            return 0;
        if(s[0]=='0')
            return 0;
        if(s.size()==1)
            return 1;
        int res=numDecodings_rec(s);
        return res;
    }
};

// https://leetcode.com/problems/house-robber/
//rec

class Solution {
public:
    int helper(vector<int>&nums, int idx)
    {
        if(idx>=nums.size()) return 0;
        return max(helper(nums, idx+2)+nums[idx], helper(nums, idx+1));
    }
    int rob(vector<int>& nums) {
        return helper(nums,0);
    }
};

// memo 
class Solution {
public:
    int helper(vector<int>&nums, int idx,vector<int>&dp)
    {
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=max(helper(nums, idx+2,dp)+nums[idx], helper(nums, idx+1,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return helper(nums,0,dp);
    }
};

// https://leetcode.com/problems/perfect-squares/
// rec 

class Solution {
public:
    int helper(vector<int>&nums, int idx,vector<int>&dp)
    {
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=max(helper(nums, idx+2,dp)+nums[idx], helper(nums, idx+1,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return helper(nums,0,dp);
    }
};

// memo 

class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
        if(n==0) return dp[0]=0;
        if(dp[n]!=-1) return dp[n];
        int mini= INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            int tempAns = helper(n-i*i,dp)+1;
            mini=min(mini, tempAns);
        }
        return dp[n]=mini;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};

// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange_rec(vector<int>& coins, int amount, vector<int>&dp)
    {
        if(amount<0) return -1;
        
        if(amount==0)
        {
           return 0;
        }
        int res=INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        for(int i=0;i<coins.size();i++)
        {
            if(coins[i]<=amount){
                int smallAns=coinChange_rec(coins, amount-coins[i],dp);
                if(smallAns!=INT_MAX) res=min(res, smallAns+1);
            }
        }
        return dp[amount]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
      
        vector<int> dp(amount+1, -1);
        int ans =coinChange_rec(coins, amount, dp);
    
        
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

// https://leetcode.com/problems/coin-change-2/
// rec

class Solution {
public:
    int helper(int amt, vector<int>&coins, int n)
    {
        if(amt==0) return 1;
        if(n==0) return 0;
        if(coins[n-1]<=amt)
        {
            return helper(amt-coins[n-1], coins, n)+helper(amt, coins, n-1);
        }
        return helper(amt,coins, n-1);
    }
    int change(int amount, vector<int>& coins) {
        return helper(amount, coins, coins.size());
    }
};

// tabu 

class Solution {
public:
    int helper(int amt, vector<int>&coins, int n,vector<vector<int>>&dp)
    {
        
        
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(coins[i-1]<=j)
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1,-1));
        return helper(amount, coins, coins.size(), dp);
    }
};

//
// rec 

class Solution {
public:
    int helper(int n)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n%2==0) return helper(n/2);
        else return helper(n/2)+1;
    }
    vector<int> countBits(int n) {
       vector<int> v(n+1);
        for(int i=0;i<=n;i++)
        {
            v[i]=helper(i);
        }
        return v;
    }
};

// memmo 

class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
        if(n==0) return dp[0]=0;
        if(n==1) return dp[1]=1;
        if(dp[n]!=-1) return dp[n];
        if(n%2==0) return helper(n/2,dp);
        else return helper(n/2,dp)+1;
    }
    vector<int> countBits(int n) {
       vector<int> v(n+1,-1);
        for(int i=0;i<=n;i++)
        {
            v[i]=helper(i,v);
        }
        return v;
    }
};