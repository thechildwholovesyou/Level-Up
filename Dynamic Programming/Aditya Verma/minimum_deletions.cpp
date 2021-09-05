// Minimum Deletions 
// https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1

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
    
    int minimumNumberOfDeletions(string s) { 
        // code here
        
        string a=s;
        std::reverse(s.begin(),s.end());
        
        vector<vector<int>>dp(a.size()+1, vector<int>(s.size()+1,0));
        return s.size()-lcs_tabu(a,s,a.size(),s.size(),dp);
    } 
};