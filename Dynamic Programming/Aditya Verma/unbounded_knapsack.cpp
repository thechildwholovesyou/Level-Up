// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#

// rec code 
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        if(W==0 or N==0) return 0;
        
        int maxi=INT_MIN;
        
        if(wt[N-1]<=W)
        {
            maxi=max(val[N-1]+knapSack(N, W-wt[N-1],val,wt),knapSack(N-1,W-wt[N-1],val,wt));
        }
        else if(wt[N-1]>W)
        {
            return knapSack(N-1,W,val,wt);
        }
        return maxi;
    }
};

// memo code

class Solution{
public:

   int knapSack_mem(int W, int wt[], int val[], int n, vector<vector<int>>&dp)
    {
        if(W==0 or n==0) return dp[n][W]=0;
       
       int maxx=INT_MIN;
       
       if(dp[n][W]!=-1) return dp[n][W];
       
       if(wt[n-1]<=W)
       {
            return dp[n][W]=max(val[n-1]+knapSack_mem(W-wt[n-1],wt,val,n,dp),knapSack_mem(W,wt,val,n-1,dp));
       }
       else if(wt[n-1]>W)
          return dp[n][W]=knapSack_mem(W,wt,val,n-1,dp);
    }
    
   


    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp( N+1 , vector<int> (W+1, -1));
       int ans =knapSack_mem(W,wt,val,N,dp);
       //display(dp);
       return ans;
        
    }
};

// tabu code

class Solution{
public:

   int knapSack_mem(int W, int wt[], int val[], int N, vector<vector<int>>&dp)
    {
    
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
            
            // main dp step 
            
            for(int i=1;i<dp.size();i++)
            {
                for(int j=1;j<dp[0].size();j++)
                {
                    if(wt[i-1]<=j)
                    {
                        dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
                    }
                    else if(wt[i-1]>j)
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            return dp[N][W];
            }
   

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp( N+1 , vector<int> (W+1, -1));
       int ans =knapSack_mem(W,wt,val,N,dp);
       //display(dp);
       return ans;
        
    }
};
