// 300. Longest Increasing Subsequence

// memo 

class Solution {
public:
    
    int lengthOfLIS_memo(vector<int>&nums, int n,vector<int>&dp)
    {
        if(dp[n]!=0) return dp[n];
        
        int maxLen=1; // kyoki ek single number bhi to LIS hota h 
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<nums[n])
            {
                 int reclen=lengthOfLIS_memo(nums, i,dp);
                 maxLen=max(maxLen, reclen+1);
            }
           
        }
        return dp[n]=maxLen;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int maxLen=0;
        vector<int> dp(nums.size(), 0);
        for(int i=0;i<nums.size();i++)
        {
            maxLen = max(maxLen, lengthOfLIS_memo(nums, i, dp));
        }
        return maxLen;
    }
};

// tabu 
class Solution {
public:
    
    int lengthOfLIS_tabu(vector<int>& nums,vector<int>&dp)
    {
        int maxLen=0;
        for(int i=0;i<nums.size();i++)
        {
            dp[i]=1; // kyoki har ek number lis hoat h 
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxLen = max(dp[i],maxLen);
        }
        return maxLen;
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1);
        
        return lengthOfLIS_tabu(nums, dp );
        
    }
};


// Longest Bitonic subsequence
// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1#

class Solution
{
    
     public  int LIS_LR(int[] arr, int[] dp) {
        int n = arr.length, maxLen = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[i] > arr[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }

            maxLen = Math.max(dp[i], maxLen);
        }

        return maxLen;
    }

    public  int LIS_RL(int[] arr, int[] dp) {
        int n = arr.length, maxLen = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }

            maxLen = Math.max(dp[i], maxLen);
        }

        return maxLen;
    }
    
    public int LongestBitonicSequence(int[] arr)
    {
        int n = arr.length, maxLen = 0;
        int[] LIS = new int[n];
        int[] LDS = new int[n];

        LIS_LR(arr, LIS);
        LIS_RL(arr, LDS);

        for (int i = 0; i < n; i++) {
            maxLen = Math.max(maxLen, LIS[i] + LDS[i] - 1);
        }

        return maxLen;
    }
}


// Maximum sum increasing subsequence 
// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

class Solution
{
     public  int maxSumIS(int arr[], int n, int[] dp) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                  dp[i] = arr[i];
                  for (int j = i - 1; j >= 0; j--) {
                        if (arr[i] > arr[j])
                              dp[i] = Math.max(dp[i], dp[j] + arr[i]);
                  }
                  sum = Math.max(sum, dp[i]);
            }
            return sum;
      }
	public int maxSumIS(int arr[], int n)  
	{  
	    //code here.
	     int[] dp = new int[n];
        return maxSumIS(arr, n, dp);
	    
	}  
}



// Minimum number of deletions to make a sorted sequence

// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence3248/1

class Solution{
		

	public:
	
	
	int lengthOfLIS_tabu(int nums[],int n,vector<int>&dp)
    {
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            dp[i]=1; // kyoki har ek number lis hoat h 
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxLen = max(dp[i],maxLen);
        }
        return maxLen;
        
    }
	int minDeletions(int arr[], int n) 
	{ 
	    // Your code goes here
	    vector<int>dp(n);
	    int lis= lengthOfLIS_tabu(arr,n,dp);
	    
	    return n-lis;
	} 
};
