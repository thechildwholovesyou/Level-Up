

// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
// Longest Common Substring

class Solution{
    public:
     int findLength_tabu(string&a, string& b,int n,int m,vector<vector<int>>&dp)
    {
        // initialization 
        
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
            }
        }
        
        int maxi=INT_MIN;
        
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
                maxi=max(dp[i][j],maxi);
            } 
        }
        return maxi;
    }
    int longestCommonSubstr (string a, string b, int n, int m)
    {
        // your code here
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));
        return findLength_tabu(a, b,a.size(),b.size(),dp);
    }
};