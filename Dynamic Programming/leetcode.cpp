// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/

// rec code

class Solution {
public:
    int uniquePathsHelper_rec(int sr,int sc,int er, int ec,vector<vector<int>>&dir)
    {
        if(sr==er and sc==ec)
            return 1;
        int count =0;
        
        for(auto ele:dir)
        {
            int r=sr+ele[0];
            int c=sc+ele[1];
            if(r>=0 and c>=0 and r<=er and c<=ec)
                count+=uniquePathsHelper_rec(r,c,er,ec,dir);
        }
        return count;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dir {{0,1},{1,0}};
        int ans =uniquePathsHelper_rec(0,0,m-1,n-1,dir);
        return ans;
    }
    
};

// mem code

class Solution {
public:
    int uniquePathsHelper_mem(int sr,int sc,int er, int ec,vector<vector<int>>&dir,vector<vector<int>>&dp)
    {
        if(sr==er and sc==ec)
        {
            return dp[sr][sc]=1;
        }
        
        if(dp[sr][sc]!=0)
            return dp[sr][sc];
        
        int count =0;
        
        for(auto ele:dir)
        {
            int r=sr+ele[0];
            int c=sc+ele[1];
            if(r>=0 and c>=0 and r<=er and c<=ec)
                count+=uniquePathsHelper_mem(r,c,er,ec,dir,dp);
        }
        return dp[sr][sc]=count;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dir {{0,1},{1,0}};
         vector<vector<int>> dp( m , vector<int> (n, 0));
        int ans =uniquePathsHelper_mem(0,0,m-1,n-1,dir,dp);
        return ans;
    }
};

// tab code

// 377. Combination Sum IV
// https://leetcode.com/problems/combination-sum-iv/


// rec code

class Solution {
public:
    
    int combinationSum4_rec(vector<int>& nums,int target)
    {
        if(target==0)
            return 1;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(target-nums[i]>=0)
                count+=combinationSum4_rec(nums, target-nums[i]);
        }
        return count;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        return combinationSum4_rec(nums, target);
    }
};

// memo code

class Solution {
public:
    
    int combinationSum4_rec(vector<int>& nums,int target,vector<int>&dp,int currSum)
    {
        if(target==currSum)
            return 1;
        
        if(currSum>target)
            return 0;
        
        if(dp[currSum]!=0)
            return dp[currSum];
        
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            count+=combinationSum4_rec(nums, target, dp,currSum+nums[i]);
        }
        return dp[currSum]=count;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1, 0);
        return combinationSum4_rec(nums, target,dp,0);
    }
};

// tab code 

// 63. Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/

// rec code

class Solution {
public:
    
    int uniquePathsWithObstacles_rec(int sr,int sc,int er,int ec,vector<vector<int>>&dir,vector<vector<int>>& obstacleGrid)
    {
        if(sr==er and sc==ec)
            return 1;
        int count=0;
        for(auto ele: dir)
        {
            int r=sr+ele[0];
            int c=sc+ele[1];
            if(r>=0 and c>=0 and r<=er and c<=ec and obstacleGrid[r][c]!=1)
                count+=uniquePathsWithObstacles_rec(r,c,er,ec,dir,obstacleGrid);
        }
        return count;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==1 or obstacleGrid[n-1][m-1]==1) return 0;
        
        vector<vector<int>>dir{{0,1},{1,0}};
        
        return uniquePathsWithObstacles_rec(0,0,n-1,m-1,dir,obstacleGrid);
    }
};

// memo code 

class Solution {
public:
    
    int uniquePathsWithObstacles_rec(int sr,int sc,int er,int ec,vector<vector<int>>&dir,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
    {
        if(sr==er and sc==ec)
            return dp[sr][sc]=1;
        
        if(dp[sr][sc]!=0)
            return dp[sr][sc];
        
        int count=0;
        
        for(auto ele: dir)
        {
            int r=sr+ele[0];
            int c=sc+ele[1];
            if(r>=0 and c>=0 and r<=er and c<=ec and obstacleGrid[r][c]!=1)
                count+=uniquePathsWithObstacles_rec(r,c,er,ec,dir,obstacleGrid,dp);
        }
        return dp[sr][sc]=count;;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==1 or obstacleGrid[n-1][m-1]==1) return 0;
        
        vector<vector<int>>dir{{0,1},{1,0}};
        
        vector<vector<int>> dp( n , vector<int> (m,0));
        
        return uniquePathsWithObstacles_rec(0,0,n-1,m-1,dir,obstacleGrid,dp);
    }
};

// tab code


// 139. Word Break
// https://leetcode.com/problems/word-break/

// rec code


class Solution {
public:
    
    bool wordBreakHelper(string s,unordered_set<string>dict)
    {
        if(s.size()==0)
        {
            return true;
        }
        int count=0;
        bool ans=false;
        for(int i=0;i<s.size();i++)
        {
            string pword=s.substr(0,i+1);
            if(dict.find(pword)!=dict.end())
            { 
               ans=ans || wordBreakHelper(s.substr(i+1),dict);
                
            }
        }
        return ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto ele: wordDict)
        {
            dict.insert(ele);
        }
       return wordBreakHelper(s,dict);
        
    }
};

//