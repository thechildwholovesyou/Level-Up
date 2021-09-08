// Matrix Chain Multiplication 
// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// rec code

class Solution{
public:

    int solve_rec(int arr[],int i,int j)
    {
        // base condition 
        if(i>=j) return 0;
        
        int mini = INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            int tempAns = solve_rec(arr,i,k)+solve_rec(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);
            
            mini=min(tempAns, mini);
        }
        return mini;
        
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        return solve_rec(arr,1,N-1);
        
    }
};


// memo code

class Solution{
public:

    int solve_memo(int arr[],int i,int j,vector<vector<int>>&dp)
    {
        // base condition 
        if(i>=j) return dp[i][j]=0;
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        dp[i][j] = INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            int tempAns = solve_memo(arr,i,k,dp)+solve_memo(arr,k+1,j,dp) + (arr[i-1]*arr[k]*arr[j]);
            
            dp[i][j]=min(tempAns, dp[i][j]);
        }
        return dp[i][j];
        
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N+1 , vector<int>(N+1,-1));
        return solve_memo(arr,1,N-1,dp);
        
    }
};