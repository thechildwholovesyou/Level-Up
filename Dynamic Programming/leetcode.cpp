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

class Solution {
public:
    
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
    
    int uniquePaths_tabu(int sr,int sc,int er,int ec,vector<vector<int>>&dir,vector<vector<int>>&dp)
    {
        for(int i=er;i>=0;i--)
        {
            for(int j=ec;j>=0;j--)
            {
                if(i==er and j==ec)
                {
                    dp[i][j]=1;
                    continue;
                }
                 int count =0;
        
                for(auto d: dir)
                {
                    int r=i+d[0];
                    int c=j+d[1];

                    if(r>=0 and c>=0 and r<=dp.size() and c<=dp[0].size())
                        count+=dp[r][c];
                }
                dp[i][j]=count;
            }
        }
        return dp[0][0];
       
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dir{{0,1},{1,0}};
        vector<vector<int>> dp( m+1 , vector<int> (n+1, 0));
        int ans = uniquePaths_tabu(0,0,m-1,n-1,dir,dp);
        display(dp);
        return ans;
    }
};

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
        return dp[sr][sc]=count;
        
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

// mem code

class Solution {
public:
    
    bool wordBreakHelper_mem(string s,int i,unordered_set<string>&dict,vector<bool>&dp)
    {
        if(s.size()==0)
            return dp[i]=true;
        
        if(dp[i]!=false) return dp[i];
    
        bool ans=false;
        
        for(int i=0;i<s.size();i++)
        {
            string pword=s.substr(0,i+1);
            if(dict.find(pword)!=dict.end())
            {
                ans = ans || wordBreakHelper_mem(s.substr(i+1),i, dict,dp);
            }
        }
        return dp[i]=ans;;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size()+1, false);
        
         return wordBreakHelper_mem(s,0,dict,dp);
        
       
    }
};

// 322. Coin Change
// https://leetcode.com/problems/coin-change/

// rec code

class Solution {
public:
    int coinChange_rec(vector<int>& coins, int amount,int &res,int count)
    {
        if(amount<0) return -1;
        if(amount==0)
        {
            res=min(res,count);
            return res;
        }
        for(int i=0;i<coins.size();i++)
        {
            coinChange_rec(coins, amount-coins[i],res,count+1);
        }
        return res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int res =INT_MAX;
        int ans =coinChange_rec(coins, amount, res,0);
        
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

// mem code

// tab code


// 1219. Path with Maximum Gold
// https://leetcode.com/problems/path-with-maximum-gold/

// rec code

class Solution {
public:
    
    int getMaximumGold_rec(int sr,int sc,int er,int ec,vector<vector<int>>&grid, vector<vector<int>>&dir)
    {
        int val=grid[sr][sc];
    
        int maxGold = 0;
        grid[sr][sc]=-grid[sr][sc];
        for(auto ele: dir)
        {
            int r=sr+ele[0];
            int c=sc+ele[1];
            
            if(r>=0 and c>=0 and r<=er and c<=ec and grid[r][c]>0)
            {
                int recGold = getMaximumGold_rec(r,c,er,ec,grid, dir);
                maxGold = max(recGold, maxGold);
            }
        }
        grid[sr][sc]=-grid[sr][sc];
        return maxGold+val;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int maxGold=0;
        vector<vector<int>> dir{{0,-1},{0,1},{1,0},{-1,0}};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]>0)
                {
                    int recGold=getMaximumGold_rec(i,j,n-1,m-1,grid,dir);
                    maxGold=max(recGold, maxGold);
                }
            }
        }
        return maxGold;
    }
};

//mem code 

// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/


// rec code 

class Solution {
public:
    
    int numDecodings_rec(string s)
    {
        if(s.size()==0)
        {
            return 1;
        }
        char ch=s[0];
        if(ch=='0')
            return 0;
        
        int count=0;
        count+=numDecodings_rec(s.substr(1));
        
        if(s.size()>1)
        {
            int num=(ch-'0')*10+(s[1]-'0');
            if(num<=26)
            {
                count+=numDecodings_rec(s.substr(2));
            }
        }
        return count;
    }
    
    int numDecodings(string s) {
        if(s.size()==0)
            return 0;
        if(s[0]=='0')
            return 0;
        if(s.size()==1)
            return 1;
        int res=numDecodings_rec(s);
        return res;
    }
};

// mem code

class Solution {
public:
    
    int numDecodings_mem(string s, int idx, vector<int>&dp)
    {
        if(idx==s.size())
            return dp[idx]=1;
        
        if(dp[idx]!=-1) return dp[idx];
        
        char ch=s[idx];
        if(ch=='0') return dp[idx]=0;
        int count= numDecodings_mem(s,idx+1, dp);
        
        if(idx<s.size()-1)
        {
            char ch1= s[idx+1];
            int num = (ch-'0')*10+(ch1-'0');
            if(num<=26)
            {
                count+=numDecodings_mem(s,idx+2,dp);
            }
        }
        return dp[idx]=count;
    }
    
    int numDecodings(string s) {
        if(s.size()==0)
            return 0;
        if(s[0]=='0')
            return 0;
        if(s.size()==1)
            return 1;
        
        vector<int>dp(s.size()+1,-1);
        
        return numDecodings_mem(s,0,dp);
    }
};

// tabu 
class Solution {
public:
    
    int numDecodings_tabu(string s, int idx,vector<int>&dp)
    {
        for(int i=s.size();i>=0;i--)
        {
            if(i==s.size())
            {
                dp[i]=1;
                continue;
            }
            char ch=s[i];
            if(ch=='0')
            {
                dp[i]=0;
                continue;
            }
            int count =dp[i+1];
            
            if(i<s.size()-1)
            {
                char ch1=s[i+1];
                int num =(ch-'0')*10+(ch1-'0');
                if(num<=26)
                    count+=dp[i+2];
            }
            dp[i]=count;
        }
        return dp[idx];
    }
    
    int numDecodings(string s) {
        if(s.size()==0)
            return 0;
        if(s[0]=='0')
            return 0;
        if(s.size()==1)
            return 1;
        
        vector<int>dp(s.size()+1,-1);
        
        return numDecodings_tabu(s,0,dp);
    }
};


// 516. Longest Palindromic Subsequence

// https://leetcode.com/problems/longest-palindromic-subsequence/

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
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int longestPalindromeSubseq(string s) {
        string a=s;
        std::reverse(s.begin(),s.end());
        
        vector<vector<int>>dp(a.size()+1, vector<int>(s.size()+1,0));
        return lcs_tabu(a,s,a.size(),s.size(),dp);
    }
};


// 72. Edit Distance
// https://leetcode.com/problems/edit-distance/

// rec

class Solution {
public:
    
    int min_dist_rec(string s1,string s2,int m,int n)
    {
        if(m==0) return n;
        if(n==0) return m;
        
        if(s1[m-1]==s2[n-1])
            return min_dist_rec(s1,s2,m-1,n-1);
        
        
            int op1=min_dist_rec(s1,s2,m-1,n-1);
            int op2=min_dist_rec(s1,s2,m,n-1);
            int op3=min_dist_rec(s1,s2,m-1,n);
            
            return 1+min(op1,min(op2,op3));
    }
    int minDistance(string s1, string s2) {
        return min_dist_rec(s1,s2,s1.size(),s2.size());
        
    }
};

// mem 
class Solution {
public:
    
    int min_dist_rec(string s1,string s2,int m,int n,vector<vector<int>>&dp)
    {
        if(m==0) return n;
        if(n==0) return m;
        
        if(dp[m][n]!=0) return dp[m][n];
        
        if(s1[m-1]==s2[n-1])
        {
            dp[m][n]=min_dist_rec(s1,s2,m-1,n-1,dp);
            return min_dist_rec(s1,s2,m-1,n-1,dp);
        }
                    
            int op1=min_dist_rec(s1,s2,m-1,n-1,dp);
            int op2=min_dist_rec(s1,s2,m,n-1,dp);
            int op3=min_dist_rec(s1,s2,m-1,n,dp);
            
            dp[m][n]=1+min(op1,min(op2,op3));
            return 1+min(op1,min(op2,op3));
        
    }
    int minDistance(string s1, string s2) {
        
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        return min_dist_rec(s1,s2,s1.size(),s2.size(),dp);
        
    }
};

// 115. Distinct Subsequences

// https://leetcode.com/problems/distinct-subsequences/

// rec

class Solution {
public:
    
    int numDistinct_rec(string a,string b,int m,int n)
    {
        if(n==0)
            return 1;
        if(m==0)
            return 0;
        if(a[m-1]==b[n-1])
            return numDistinct_rec(a,b,m-1,n-1)+numDistinct_rec(a,b,m-1,n);
        else
            return numDistinct_rec(a,b,m-1,n);
    }
    int numDistinct(string s, string t) {
        return numDistinct_rec(s,t,s.size(),t.size());
    }
};

// memo 
class Solution {
public:
    
    int numDistinct_rec(string &a,string &b,int m,int n,vector<vector<int>>&dp)
    {
        if(n==0)
            return 1;
        if(m==0)
            return 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(a[m-1]==b[n-1])
        {
            dp[m][n]=numDistinct_rec(a,b,m-1,n-1,dp)+numDistinct_rec(a,b,m-1,n,dp);
            return numDistinct_rec(a,b,m-1,n-1,dp)+numDistinct_rec(a,b,m-1,n,dp);
        }
            dp[m][n]=numDistinct_rec(a,b,m-1,n,dp);
            return numDistinct_rec(a,b,m-1,n,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        return numDistinct_rec(s,t,s.size(),t.size(),dp);
    }
};


// 583. Delete Operation for Two Strings
// https://leetcode.com/problems/delete-operation-for-two-strings/

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
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1,-1));
        int lcs=lcs_tabu(word1,word2,word1.size(),word2.size(),dp);
        
        int deletions=word1.size()-lcs;
        int insertions=word2.size()-lcs;
        return deletions+insertions;
    }
};


// 1035. Uncrossed Lines
// https://leetcode.com/problems/uncrossed-lines/

// rec 

class Solution {
public:
    
    int maxUncrossedLines_rec(vector<int>& a, vector<int>& b,int m,int n)
    {
        if(n==0 or m==0) return 0;
        if(a[m-1]==b[n-1])
            return maxUncrossedLines_rec(a,b,m-1,n-1)+1;
        else
            return max(maxUncrossedLines_rec(a,b,m-1,n), maxUncrossedLines_rec(a,b,m,n-1));
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return maxUncrossedLines_rec(nums1, nums2, nums1.size(),nums2.size());
    }
};

// memo code

class Solution {
public:
    
    int maxUncrossedLines_memo(vector<int>& a, vector<int>& b,int m,int n,vector<vector<int>>&dp)
    {
        if(n==0 or m==0) return dp[m][n]= 0;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(a[m-1]==b[n-1])
            return dp[m][n]= maxUncrossedLines_rec(a,b,m-1,n-1,dp)+1;
        else
            return dp[m][n]=max(maxUncrossedLines_memo(a,b,m-1,n,dp), maxUncrossedLines_memo(a,b,m,n-1,dp));
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>>dp(nums1.size()+1, vector<int>(nums2.size()+1,-1));
        return maxUncrossedLines_memo(nums1, nums2, nums1.size(),nums2.size(),dp);
    }
};

// tabu code

class Solution {
public:
    
    int maxUncrossedLines_tabu(vector<int>& a, vector<int>& b,int m,int n,vector<vector<int>>&dp)
    { 
        // initialization 
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
            }
        }
        
        // main dp 
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
        return dp[m][n];
        
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>>dp(nums1.size()+1, vector<int>(nums2.size()+1,-1));
        return maxUncrossedLines_tabu(nums1, nums2, nums1.size(),nums2.size(),dp);
    }
};

// Max Dot Product of Two Subsequences
// https://leetcode.com/problems/max-dot-product-of-two-subsequences/
// rec code

class Solution {
public:
    int maxDotProduct_rec(vector<int>& a, vector<int>& b,int m,int n)
    {
        if(m==0 or n==0) return 0;
        
        int op1=a[m-1]*b[n-1]+maxDotProduct_rec(a,b,m-1,n-1);
        int op2=maxDotProduct_rec(a,b,m-1,n);
        int op3=maxDotProduct_rec(a,b,m,n-1);
        
        return max(op1,max(op2,op3));
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        
        int ans = maxDotProduct_rec(nums1,nums2,nums1.size(),nums2.size());
        return ans;
    }
};

// 1458. Max Dot Product of Two Subsequences
// https://leetcode.com/problems/max-dot-product-of-two-subsequences/
// rec code

class Solution {
public:
    int maxDotProduct_rec(vector<int>& a, vector<int>& b,int m,int n)
    {
        if(m==0 or n==0) return -1e8;
        
        int val=a[m-1]*b[n-1];
        int op1=val+maxDotProduct_rec(a,b,m-1,n-1);
        int op2=maxDotProduct_rec(a,b,m-1,n);
        int op3=maxDotProduct_rec(a,b,m,n-1);
        
        int m1= max(op1,max(op2,op3));
        int m2=max(val,m1);
        return m2;
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        //vector<vector<int>> dp(nums1.size()+1, vector<int>dp(nums2.size()+1,-1));
        int ans = maxDotProduct_rec(nums1,nums2,nums1.size(),nums2.size());
        return ans;
    }
};

// memo code

class Solution {
public:
    int maxDotProduct_rec(vector<int>& a, vector<int>& b,int m,int n,vector<vector<int>>&dp)
    {
        if(m==0 or n==0) return dp[m][n]=-1e8;
        
        if(dp[m][n]!=-1e9) return dp[m][n];
        
        int val=a[m-1]*b[n-1];
        int op1=val+maxDotProduct_rec(a,b,m-1,n-1,dp);
        int op2=maxDotProduct_rec(a,b,m-1,n,dp);
        int op3=maxDotProduct_rec(a,b,m,n-1,dp);
        
        int m1= max(op1,max(op2,op3));
        int m2=max(val,m1);
        return dp[m][n]=m2;
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1,-1e9));
        int ans = maxDotProduct_rec(nums1,nums2,nums1.size(),nums2.size(),dp);
        return ans;
    }
};

// tabu code

class Solution {
public:
    int maxDotProduct_tabu(vector<int>& a, vector<int>& b,int m,int n,vector<vector<int>>&dp)
    {

        // initialization 
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=-1e8;
            }
        }
        
        // main dp 
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                int val=a[i-1]*b[j-1];
                int op1=val+dp[i-1][j-1];
                int op2=dp[i-1][j];
                int op3=dp[i][j-1];
                
                int m1=max(op1,max(op2,op3));
                int m2=max(val,m1);
                
                dp[i][j]=m2;
            }
        }
        return dp[m][n];
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1,-1e9));
        int ans = maxDotProduct_tabu(nums1,nums2,nums1.size(),nums2.size(),dp);
        return ans;
    }
};

// 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// rec code 

class Solution {
public:
    
    int minOperations_rec(vector<int>&nums,int i,int j ,int sum,int count)
    {
        if(sum==0) return count;
        if(sum<=0 or i>j) return 1e8;
        
        int left = minOperations_rec(nums,i+1,j,sum-nums[i],count+1);
        int right = minOperations_rec(nums,i,j-1,sum-nums[j],count+1);
        
        return min(left,right);
        
    }
    
    int minOperations(vector<int>& nums, int x) {
        int ans = minOperations_rec(nums,0,nums.size()-1,x,0);
        
        return (ans>=1e8)?-1 : ans;
    }
};

// memo code 



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

// tabu code 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        int len=0,n=s.length();
        for(string &ss: wordDict){
            st.insert(ss);
            int l=ss.length();
             len=max(len,l);
        }
        
       vector<int>dp(n+1);
        dp[0]=true;
        for(int i=0;i<=n;i++){
          if(!dp[i])continue;
          for(int l=1;l<=len and i+l<=n;l++){
              string str=s.substr(i,l);
               //cout<<str<<endl;
              if(st.find(str) != st.end()) {
                  dp[i+l]=true;
                  
              }
          }  
        }
        
        return dp[n];
    }
};


// 403. Frog Jump
// https://leetcode.com/problems/frog-jump/

class Solution {
public:
    
    bool canCross_helper(vector<int>& stones)
    {
        unordered_map<int,unordered_set<int>> m;
        for(auto ele: stones)
            m[ele]={};
        
        m[0].insert(1);
        
        for(int i=0;i<stones.size();i++)
        {
            int currStone = stones[i];
            unordered_set<int> jumps = m[currStone];
            for(auto jump: jumps)
            {
                int pos = currStone + jump;
                if(pos ==stones[stones.size()-1]) return true;
                if(m.find(pos)!=m.end())
                {
                    if(jump-1>0)
                        m[pos].insert(jump-1);
                    m[pos].insert(jump);
                    m[pos].insert(jump+1);
                }
            }
        }
        return false;
        
    }
    
    bool canCross(vector<int>& stones) {
        return canCross_helper(stones);
    }
};



// 688. Knight Probability in Chessboard
// https://leetcode.com/problems/knight-probability-in-chessboard/

class Solution {
public:
    
    bool isSafe(int n,int r,int c)
    {
        if(r<0 or r>=n or c<0 or c>=n) return false;
        return true;
    }
    
    double knightProbability_rec(int n, int k, int row, int col,vector<vector<int>>&dir)
    {
        
        if(isSafe(n,row,col)==false) return 0; 
        if(k==0) return 1;
        double probability = 0;
        for(int i=0;i<dir.size();i++)
        {
            probability+=knightProbability_rec(n,k-1,row+dir[i][0],col+dir[i][1],dir)/8.0;
        }
        
        return probability;
    }
    
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<int>> dir={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
        
        return knightProbability_rec(n,k,row,col,dir);
    }
};


// 354. Russian Doll Envelopes

// https://leetcode.com/problems/russian-doll-envelopes/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(),envelopes.end());
        vector<int>dp(n,0);
        int maxLen = 0 ;  
         for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j <i; j++) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(dp[i], maxLen);
        }

        return maxLen;
        
    }
};

// 

// rec

class Solution {
public:
    
    int solve(int e,int f)
    {
        // base condition 
        if(f==0 or f==1) return f;
        if(e==1) return f;
        
        int mini=INT_MAX;
        
        for(int k=1;k<f;k++)
        {
            int temp=1+max(solve(e-1,k-1),solve(e,f-k));
            
            mini=min(temp, mini);
        }
        return mini;
    }
    
    int twoEggDrop(int n) {
        return solve(2,n);
    }
};

// memo 
class Solution {
public:
    
    int dp[3][1001];
    int egg(int n , int k){
        if(k==0 || k==1){
            dp[n][k] = k;
            return k;
        }
        if(n==1){
            dp[n][k] = 1;
            return k;
        }
        
        if(dp[n][k]!=-1) return dp[n][k];
        
        int ans=  INT_MAX;
        for(int i = 1;i<=k;i++){
            
            int a,b;
            // if(dp[n-1][i-1]!=-1){
            //     a = dp[n-1][i-1];
            // }else{
                a = egg(n-1, i-1);
          //  }
            
            if(dp[n][k-i]!=-1){
                b = dp[n][k-i];
            }else{
                b = egg(n, k-i);
            }
            
            int t = 1 + max(a, b);
            ans = min(ans, t);
        }
        return dp[n][k] =  ans;
        
    }
    
    
    int twoEggDrop(int n) {
        memset(dp , -1, sizeof(dp));
        return egg(2 , n);
    }
};

// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/
// rec code

class Solution {
public:
    
    bool helper(vector<int>&nums, int target, int n)
    {
        if(n==0) return false;
        if(target==0) return true;
        
        bool ans =false;
        if(nums[n-1]<=target)
        {
            bool a1=helper(nums, target-nums[n-1],n-1);
            bool a2=helper(nums, target,n-1);
            ans = a1 || a2;
        }
        else if(nums[n-1]>target)
            return helper(nums, target,n-1);
        
        return ans;
            
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto ele: nums)
            sum+=ele;
        
        if(sum%2!=0) return false;
        return helper(nums,sum/2,nums.size());
        
    }
};

// memo code

class Solution {
public:
    
    bool subsetSum_mem(vector<int>&nums, int sum,int n,vector<vector<int>>&dp)
    {
        if(sum==0) return true;
        if(n==0) return false;
        bool ans=false;
        
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        if(nums[n-1]<=sum)
        {
            bool a1=subsetSum_mem(nums,sum-nums[n-1],n-1,dp);
            bool a2=subsetSum_mem(nums,sum,n-1,dp);
            
            ans=a1 or a2;
            dp[n][sum]=ans;
        }
        else if(nums[n-1]>sum)
            return dp[n][sum]= subsetSum_mem(nums,sum,n-1,dp);
        return dp[n][sum];
    }
    
    bool findPartition(vector<int>&nums)
    {
        int n=nums.size();
        int sum=0;
        for(auto ele: nums)
            sum+=ele;
        if(sum%2!=0)
            return false;
        vector<vector<int>> dp( n+1 , vector<int> (sum/2+1, -1));
        return subsetSum_mem(nums,sum/2,n,dp);
    }
    
    bool canPartition(vector<int>& nums) {
        return findPartition(nums);
    }
};

// tabu code

class Solution {
public:
    
    bool helper(vector<int>&nums, int target,vector<vector<int>>&dp)
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
        
        bool ans =false;
        // main dp
        
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(nums[i-1]<=j)
                {
                    bool a1=dp[i-1][j-nums[i-1]];
                    bool a2=dp[i-1][j];
                    
                    dp[i][j]=a1 or a2;
                }
                else if(nums[i-1]>j)
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
            
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto ele: nums)
            sum+=ele;
        
        if(sum%2!=0) return false;
        vector<vector<int>>dp(nums.size()+1, vector<int>(sum/2+1,-1));
        return helper(nums,sum/2,dp);
        
    }
};


// Knapsack with Duplicate Items 
// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

// rec + memo 
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

// 494. Target Sum
// https://leetcode.com/problems/target-sum/

// rec code

class Solution {
public:

    
    int findTargetSumWays_rec(vector<int>&nums, int ans, int n,int sum)
    {
        if(n==0 and ans==sum) return 1;
        if(n==0) return 0;
        
        int count=0;
        count+=findTargetSumWays_rec(nums, ans-nums[n-1],n-1,sum);
        count+=findTargetSumWays_rec(nums,ans+nums[n-1],n-1,sum);
        
        return count;
    }
            
    int findTargetSumWays(vector<int>& nums, int target) {
       
        return findTargetSumWays_rec(nums,0,nums.size(), target);
    }
};

// 698. Partition to K Equal Sum Subsets
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
class Solution {
public:
    bool helper(vector<int>&nums, int idx ,int sum,int target,vector<bool>&vis,int k)
    {
        if(k==1) return true;
        if(sum==target)
            return helper(nums, 0,0,target,vis,k-1 );
        
        for(int i=idx;i<nums.size();i++)
        {
            if(!vis[i])
            {
                vis[i]=true;
                bool recAns = helper(nums, i+1, sum+nums[i],target, vis, k);
                if(recAns)
                    return true;
                vis[i]=false;
            }
        }
        return false;
    }
    
    bool canPartition(vector<int>& nums, int k)
    {
        int n=nums.size();
        if(k>n) return false;
        if(k==1) return true;
        int sum=0;
        for(auto ele:nums)
            sum+=ele;
        if(sum%k!=0) return false;
        
        int s=sum/k;
        
        vector<bool>vis(nums.size()+1, false);
        return helper(nums,0,0,s,vis,k);
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        return canPartition(nums,k);
        
    }
};

// 576. Out of Boundary Paths
// https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
       int dp[50][50][51];
       int mod = 1e9+7;
       int dx[4] = {-1,0,1,0};
       int dy[4] = {0,-1,0,1};
    public:
    int find(int m,int n,int k,int r,int c){
        if(r<0 || c<0 || r>=m || c>=n ){ 
            return 1;
        }
        
        if(k == 0){
            return 0;
        }
         if(dp[r][c][k]!=-1)
        {
            return dp[r][c][k];
        }
        int sum = 0;
        
        for(int i=0;i<4;i++){
            int x = r + dx[i];
            int y = c + dy[i];
            sum = (sum + find(m,n,k-1,x,y))%mod;
        }

         return dp[r][c][k] = sum;
    }
    int findPaths(int m, int n, int M, int r, int c) {
        memset(dp,-1,sizeof(dp));
        return find(m,n,M,r,c);
    }
};


// 312. Burst Balloons
// https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    
     int dp[502][502];
    
    int solve_memo(vector<int>&arr,int i,int j)
    {
        // base condition 
        if(i>=j) return 0;
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans =INT_MIN;
        for(int k=i;k<j;k++)
        {
            int tempAns = solve_memo(arr,i,k)+solve_memo(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);
            
            ans=max(ans,tempAns);
        }
        return dp[i][j]=ans;
        
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        memset(dp,-1,sizeof(dp));
        return solve_memo(nums,1,nums.size()-1);
    }
};

// 221. Maximal Square
// https://leetcode.com/problems/maximal-square/
// rec code



class Solution {
public:
    
    int helper(vector<vector<char>>& matrix, int i,int j)
    {
        if(i>=matrix.size() or j>=matrix[0].size() or matrix[i][j]=='0')
            return 0;
        
        int ans =1+min(helper(matrix,i+1,j),min(helper(matrix,i+1,j+1),helper(matrix, i,j+1)));
        return ans;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0) return 0;
        int maxArea=0;
        int currArea=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                currArea=helper(matrix,i,j);
                maxArea=max(currArea, maxArea);
            }
        }
        return maxArea*maxArea;
    }
};


// dp code

class Solution {
public:
    
    int helper(vector<vector<char>>& matrix, int i,int j,vector<vector<int>>&dp)
    {
        if(i>=matrix.size() or j>=matrix[0].size())
            return 0;
        if(matrix[i][j]=='0') return dp[i][j]=0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        int ans =1+min(helper(matrix,i+1,j,dp),min(helper(matrix,i+1,j+1,dp),helper(matrix, i,j+1,dp)));
        return dp[i][j]=ans;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0) return 0;
        vector<vector<int>>dp(matrix.size()+1, vector<int>(matrix[0].size()+1,-1));
        int maxArea=0;
        int currArea=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                currArea=helper(matrix,i,j,dp);
                maxArea=max(currArea, maxArea);
            }
        }
        return maxArea*maxArea;
    }
};

// 1277. Count Square Submatrices with All Ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int helper(vector<vector<int>>& matrix,int i,int j)
    {
        if(i>=matrix.size() or j>=matrix[0].size() or matrix[i][j]==0)
            return 0;
        int ans=1+min(helper(matrix, i+1,j),min(helper(matrix, i+1,j+1),helper(matrix,i,j+1)));
        return ans;
    }
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        int cnt=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                cnt+=helper(matrix,i,j);
            }
        }
        return cnt;
    }
};

// dp code

class Solution {
public:
    int helper(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=matrix.size() or j>=matrix[0].size())
            return 0;
        if(matrix[i][j]==0) return dp[i][j]=0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=1+min(helper(matrix, i+1,j,dp),min(helper(matrix, i+1,j+1,dp),helper(matrix,i,j+1,dp)));
        return dp[i][j]=ans;
    }
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        vector<vector<int>>dp(matrix.size()+1, vector<int>(matrix[0].size()+1, -1));
        int cnt=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                cnt+=helper(matrix,i,j,dp);
            }
        }
        return cnt;
    }
};