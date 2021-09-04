// longest common subsequence
// https://leetcode.com/problems/longest-common-subsequence/
// 1143. Longest Common Subsequence
// rec code

class Solution {
public:
    int lcs_rec(string a,string b,int n,int m)
    {
        if(n==0 or m==0)
            return 0;
        if(a[n-1]==b[m-1])
            return lcs_rec(a,b,n-1,m-1)+1;
        else
            return max(lcs_rec(a,b,n-1,m), lcs_rec(a,b,n,m-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return lcs_rec(text1,text2,text1.size(),text2.size());
    }
};

// memo code 

class Solution {
public:
    int lcs_memo(string a,string b,int n,int m,vector<vector<int>>&dp)
    {
        if(n==0 or m==0)
            dp[n][m]=0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(a[n-1]==b[m-1])
            return dp[n][m]=lcs_memo(a,b,n-1,m-1,dp)+1;
        else
            return dp[n][m]=max(lcs_memo(a,b,n-1,m,dp), lcs_memo(a,b,n,m-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1,-1));
        return lcs_memo(text1,text2,text1.size(),text2.size(),dp);
    }
};

// tabu code

class Solution {
public:
    int lcs_tabu(string a,string b,int n,int m,vector<vector<int>>&dp)
    {   
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
            }
        }
        
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1,-1));
        return lcs_tabu(text1,text2,text1.size(),text2.size(),dp);
    }
};