// rec code 

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       // base cond
       if(W==0 or n==0) return 0;
       
       int maxx=INT_MIN;
       
       if(wt[n-1]<=W)
       {
           maxx=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
           return maxx;
       }
       else if(wt[n-1]>W)
        return knapSack(W,wt,val,n-1);
    }
};

// mem code

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.

    void display(vector<vector<int>>v)
    {
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[0].size();j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int knapSack_mem(int W, int wt[], int val[], int n, vector<vector<int>>&dp)
    {
        if(W==0 or n==0) return dp[n][W]=0;
       
       int maxx=INT_MIN;
       
       if(dp[n][W]!=-1) return dp[n][W];
       
       if(wt[n-1]<=W)
       {
            return dp[n][W]=max(val[n-1]+knapSack_mem(W-wt[n-1],wt,val,n-1,dp),knapSack_mem(W,wt,val,n-1,dp));
       }
       else if(wt[n-1]>W)
          return dp[n][W]=knapSack_mem(W,wt,val,n-1,dp);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp( n+1 , vector<int> (W+1, -1));
       int ans =knapSack_mem(W,wt,val,n,dp);
       //display(dp);
       return ans;
    }
};

// tabu code

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int knapSack_tabu(int W, int wt[], int val[], int n,vector<vector<int>>&dp)
    {
        // initialization step 
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
            }
        }
        
        // choice diagram 
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(wt[i-1]<=j)
                {
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
                else if(wt[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                
            }
        }
        return dp[n][W];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp( n+1, vector<int> (W+1, -1));
       int ans=knapSack_tabu(W,wt,val,n,dp);
       return ans;
    }
};