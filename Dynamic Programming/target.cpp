// permutation 

// memo 

int permutation_helper(vector<int>&nums, int target,vector<int>&dp)
{
    if(target==0) return dp[tar]=1;
    
    if(dp[tar]!=-1) return dp[tar];

    int count=0;
    for(auto ele: arr)
    {
        if(tar-ele>=0)
            count+=permutation_helper(nums,target-ele, dp);
    }
    return dp[tar]=count;
}

int permutation(vector<int>&nums, int target)
{
    vector<int> dp(nums.size()+1,-1);
    return permutation_helper(nums, target, dp);
}

// tabu 

int permutation_helper(vector<int>&nums, int target,vector<int>&dp)
{
    if(target==0) return dp[tar]=1;
    
    if(dp[tar]!=-1) return dp[tar];

    int count=0;
    for(auto ele: arr)
    {
        if(tar-ele>=0)
            count+=permutation_helper(nums,target-ele, dp);
    }
    return dp[tar]=count;
}

int permutation(vector<int>&nums, int target)
{
    vector<int> dp(nums.size()+1,-1);
    return permutation_helper(nums, target, dp);
}

// combination 

// memo


