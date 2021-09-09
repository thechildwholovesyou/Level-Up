// 416. Partition Equal Subset Sum

// https://leetcode.com/problems/partition-equal-subset-sum/

// rec code 
class Solution {
public:
    
    bool subsetSum_rec(vector<int>&nums, int sum,int n)
    {
        if(sum==0) return true;
        if(n==0) return false;
        bool ans=false;
        if(nums[n-1]<=sum)
        {
            bool a1=subsetSum_rec(nums,sum-nums[n-1],n-1);
            bool a2=subsetSum_rec(nums,sum,n-1);
            
            ans=a1 or a2;
        }
        else if(nums[n-1]>sum)
            return subsetSum_rec(nums,sum,n-1);
        return ans;
    }
    
    bool findPartition(vector<int>&nums)
    {
        int n=nums.size();
        int sum=0;
        for(auto ele: nums)
            sum+=ele;
        if(sum%2!=0)
            return false;
        return subsetSum_rec(nums,sum/2,n);
    }
    
    bool canPartition(vector<int>& nums) {
        return findPartition(nums);
    }
};

// mem code 

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
    
    bool subsetSum_tabu(vector<int>&nums, int sum,int n,vector<vector<bool>>&dp)
    {
   
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<sum;j++)
            {
                if(i==0)
                    dp[i][j]=false;
                if(j==0)
                    dp[i][j]=true;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                {
                    bool a1=dp[i-1][j-nums[i-1]];
                    bool a2=dp[i-1][j];
                    dp[i][j]=a1 or a2;
                }
                else if(nums[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
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
        vector<vector<bool>> dp( n+1 , vector<bool> (sum/2+1, false));
        return subsetSum_tabu(nums,sum/2,n,dp);
    }
    
    bool canPartition(vector<int>& nums) {
        return findPartition(nums);
    }
};

// 718. Maximum Length of Repeated Subarray
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
class Solution {
public:
    
    int findLength_tabu(vector<int>& a, vector<int>& b,int n,int m,vector<vector<int>>&dp)
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
        
        int maxi=INT_MIN;
        
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
                maxi=max(dp[i][j],maxi);
            } 
        }
        return maxi;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        return findLength_tabu(nums1, nums2,nums1.size(),nums2.size(),dp);
    }
};



// 1092. Shortest Common Supersequence
// https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    
    string lcs_dp(string a,string b,int m,int n,vector<vector<int>>&dp)
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
        // print lcs
        int i=m,j=n;
        string s="";
        while(i>0 and j>0)
        {
            if(a[i-1]==b[j-1])
            {
                s.push_back(a[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                s.push_back(a[i-1]);
                i--;
            }
            else
            {
                s.push_back(b[j-1]);
                j--;
            }
                   
            
        }
        
        while(i>0)
        {
            s.push_back(a[i-1]);
            i--;
        }
        while(j>0)
        {
            s.push_back(b[j-1]);
            j--;
        }
        std:: reverse(s.begin(),s.end());
        
        return s;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>>dp(str1.size()+1, vector<int>(str2.size()+1,0));
        string lcs=lcs_dp(str1,str2,str1.size(),str2.size(),dp);
        
        return lcs;
    }
};

// 1312. Minimum Insertion Steps to Make a String Palindrome
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:
    
    // calculation LPS from LCS;
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
    int minInsertions(string s) {
        string a=s;
        std::reverse(s.begin(),s.end());
        
        vector<vector<int>>dp(a.size()+1, vector<int>(s.size()+1,0));
        int lps= lcs_tabu(a,s,a.size(),s.size(),dp);
        
        int deletions = s.size()-lps;
        return deletions;
    }
};

// 392. Is Subsequence
// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    
    int lcs_tabu(string a, string b,int n,int m,vector<vector<int>>&dp)
    {
        // initialiaztion 
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
            }
        }
        
        // main dp
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
    bool isSubsequence(string s, string t) {
        
        if(s.size() == 0 && t.size() == 0) return true;
        if(s.size() == 0 && t.size() != 0) return true;
        if(s.size() != 0 && t.size() == 0) return false;
        vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1, -1));
        int lcs=lcs_tabu(s,t,s.size(),t.size(),dp);
        if(lcs==min(s.size(),t.size()))
            return true;
        return false;
    }
};


// 132. Palindrome Partitioning II
// https://leetcode.com/problems/palindrome-partitioning-ii/

// rec code
class Solution {
public:
    
    bool isPalindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int minCut_rec(string s,int i,int j)
    {
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        int mini=INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            int tempAns=minCut_rec(s,i,k)+minCut_rec(s,k+1,j)+1;
            mini=min(tempAns,mini);
        }
        return mini;
    }
    int minCut(string s) {
        return minCut_rec(s,0,s.size()-1);
    }
};

// memo code

class Solution {
public:
    
    bool isPalindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int minCut_rec(string s,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            int tempAns=minCut_rec(s,i,k,dp)+minCut_rec(s,k+1,j,dp)+1;
            mini=min(tempAns,mini);
            dp[i][j]=mini;
        }
        return dp[i][j]=mini;
    }
    int minCut(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return minCut_rec(s,0,s.size()-1,dp);
    }
};

// memo opti

// ye bhi BC TLE dera tha

class Solution {
public:
    
    bool isPalindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int minCut_memo_opti(string s,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            
            
            int left ,right;
            
            if(dp[i][k]!=-1)
                left=dp[i][k];
            else
                left=minCut_memo_opti(s,i,k,dp);
            
            if(dp[k+1][j]!=-1)
                right=dp[k+1][j];
            else
                right=minCut_memo_opti(s,k+1,j,dp);
            
            int tempAns=left+right+1;
            mini=min(tempAns,mini);
            dp[i][j]=mini;
        }
        return dp[i][j]=mini;
    }
    int minCut(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return minCut_memo_opti(s,0,s.size()-1,dp);
    }
};


// 583. Delete Operation for Two Strings
// https://leetcode.com/problems/delete-operation-for-two-strings/

// tabu code 

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


// Longest Common Substring 
// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution{
    public:
     int findLength_tabu(string&a, string& b,int n,int m,vector<vector<int>>&dp)
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
        
        int maxi=INT_MIN;
        
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
                maxi=max(dp[i][j],maxi);
            } 
        }
        return maxi;
    }
    int longestCommonSubstr (string a, string b, int n, int m)
    {
        // your code here
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));
        return findLength_tabu(a, b,a.size(),b.size(),dp);
    }
};


// 

// rec code

class Solution {
public:
    
    bool isPalindrome(string s,int i,int j)
    {
        
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int minCut_rec(string s,int i,int j)
    {
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        int mini=INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            int tempAns=minCut_rec(s,i,k)+minCut_rec(s,k+1,j)+1;
            mini=min(tempAns,mini);
        }
        return mini;
    }
    int minCut(string s) {
        return minCut_rec(s,0,s.size()-1);
    }
};

// memo code

class Solution {
public:
    
    bool isPalindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int minCut_rec(string s,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            int tempAns=minCut_rec(s,i,k,dp)+minCut_rec(s,k+1,j,dp)+1;
            mini=min(tempAns,mini);
            dp[i][j]=mini;
        }
        return dp[i][j]=mini;
    }
    int minCut(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return minCut_rec(s,0,s.size()-1,dp);
    }
};

// memo opti 

class Solution {
public:
    
    bool isPalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int minCut_memo_opti(string &s,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            
            int left ,right;
            
            if(dp[i][k]!=-1)
                left=dp[i][k];
            else
                left=minCut_memo_opti(s,i,k,dp);
            
            if(dp[k+1][j]!=-1)
                right=dp[k+1][j];
            else
                right=minCut_memo_opti(s,k+1,j,dp);
            
            int tempAns=left+right+1;
            mini=min(tempAns,mini);
            dp[i][j]=mini;
        }
        return dp[i][j]=mini;
    }
    int minCut(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return minCut_memo_opti(s,0,s.size()-1,dp);
    }
};

// memo more opti 
// bc kuch TC paas nhi hore the 

class Solution {
public:
    
    bool isPalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int minCut_memo_opti(string &s,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            
            if(!isPalindrome(s,i,k)) continue;
            
            int left ,right;
            
            if(dp[i][k]!=-1)
                left=dp[i][k];
            else
                left=minCut_memo_opti(s,i,k,dp);
            
            if(dp[k+1][j]!=-1)
                right=dp[k+1][j];
            else
                right=minCut_memo_opti(s,k+1,j,dp);
            
            int tempAns=left+right+1;
            mini=min(tempAns,mini);
            dp[i][j]=mini;
        }
        return dp[i][j]=mini;
    }
    int minCut(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return minCut_memo_opti(s,0,s.size()-1,dp);
    }
};
