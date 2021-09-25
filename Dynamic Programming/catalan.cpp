// https://leetcode.com/problems/unique-binary-search-trees/
// 96. Unique Binary Search Trees

// rec code

class Solution {
public:
    
    int catalanNumber(int n)
    {
        if(n==0 or n==1) return 1;
        int ans =0;
        for(int i=0;i<n;i++)
        {
            ans+=catalanNumber(i)* catalanNumber(n-i-1);
        }
        return ans;
    }
    
    int numTrees(int n) {
        return catalanNumber(n);
    }
};

// dp code

class Solution {
public:
    
    int catalanNumber(int n,vector<int>&dp)
    {
        dp[0]=dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        return catalanNumber(n,dp);
    }
};

// 95. Unique Binary Search Trees II
// https://leetcode.com/problems/unique-binary-search-trees-ii/

class Solution {
public:
    

    
    vector<TreeNode*> generateTrees_helper(int i,int j) {
        vector<TreeNode*> v;
        
        if(i>j){
            v.push_back(NULL);
            return v;
        }
        
        for(int k=i;k<=j;k++)
        {
            vector<TreeNode*> left = generateTrees_helper(i,k-1);
            vector<TreeNode*> right = generateTrees_helper(k+1,j);
            
            for(auto l: left)
            {
                for(auto r: right)
                {
                    TreeNode* root=new TreeNode(k);
                    root->left=l;
                    root->right=r;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode* > v;
        if(n==0) return v;
        
        return generateTrees_helper(1,n);
    }
};