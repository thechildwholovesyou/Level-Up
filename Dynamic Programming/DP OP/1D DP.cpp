
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