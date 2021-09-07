// Longest Repeating Subsequence
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

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
                if(a[i-1]==b[j-1] and i!=j)
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		     vector<vector<int>>dp(str.size()+1, vector<int>(str.size()+1,-1));
            return lcs_tabu(str,str,str.size(),str.size(),dp);
		}

};

