
// rec code

class Solution{   
public:
    bool isSubsetSum_rec(int N, int arr[], int sum){
        // code here 
        if(sum==0) return true;
        if(N==0) return false;
        bool ans =false;
        if(arr[N-1]<=sum)
        {
            bool a1=isSubsetSum_rec(N-1, arr,sum);
            bool a2=isSubsetSum_rec(N-1, arr,sum-arr[N-1]);
            bool ans = a1 or a2;
        }
        else if(arr[N-1]>sum)
        {
            return isSubsetSum_rec(N-1, arr,sum);
        }
    }
};


// mem code

class Solution{   
public:

    bool isSubsetSum_memo(int N, int arr[], int sum,vector<vector<int>>& dp)
    {
        if(sum==0) return true;
        if(N==0) return false;
        
        if(dp[N][sum]!=-1)
            return dp[N][sum];
        
        if(arr[N-1]<=sum)
        {
            bool a1=isSubsetSum_memo(N-1, arr,sum,dp);
            bool a2=isSubsetSum_memo(N-1, arr,sum-arr[N-1],dp);
            bool ans = a1 or a2;
            dp[N][sum]=ans;
        }
        else if(arr[N-1]>sum)
        {
            return dp[N][sum]=isSubsetSum_memo(N-1, arr,sum,dp);
        }
    }

    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        vector<vector<int>> dp( N+1 , vector<int> (sum+1, -1));
        return isSubsetSum_memo(N,arr, sum, dp);
        
    }
};


// tabu code

class Solution{   
public:

    void display(vector<vector<bool>>&v)
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
    
   
   bool isSubsetSum_tabu(int N, int arr[], int sum,vector<vector<bool>>&dp)
   {
       for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0)
                    dp[i][j]=false;
                if(j==0)
                    dp[i][j]=true;
            }
        }
        
        
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                {
                    bool a1=dp[i-1][j];
                    bool a2=dp[i-1][j-arr[i-1]];
                    dp[i][j]=a1 or a2;
                }
                else if(arr[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
   }

    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        vector<vector<bool>> dp( N+1 , vector<bool> (sum+1));
        
        return isSubsetSum_tabu(N,arr,sum,dp);
        
    }
};