// Shortest Common Supersequence
// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1#

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcs(string a, string b, int m, int n,vector<vector<int>>&dp)
    {
        // initialization 
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        
        // main steps
        
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int shortestCommonSupersequence(string a, string b, int m, int n)
    {
        //code here
        vector<vector<int>>dp(a.size()+1, vector<int>(b.size()+1,0));
        
        int lcs_ans = lcs(a,b,m,n,dp);
        return (a.size()+b.size())-lcs_ans;
    }
};