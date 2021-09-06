// Minimum number of deletions and insertions

// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1#

class Solution{
		

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
	int minOperations(string text1, string text2) 
	{ 
	    // Your code goes here
	      vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1,-1));
	      int lcs=lcs_tabu(text1,text2,text1.size(),text2.size(),dp);
	      
	      int deletions= text1.size()-lcs;
	      int insertions=text2.size()-lcs;
	      return deletions + insertions;
	} 
};