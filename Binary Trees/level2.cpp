// 968. Binary Tree Cameras
// https://leetcode.com/problems/binary-tree-cameras/

class Solution {
public:
    
    int cameras;
    int minCameraCover_helper(TreeNode* root)
    {
        if(root==NULL) return 1;
        
        int lc=minCameraCover_helper(root->left);
        int rc=minCameraCover_helper(root->right);
        
        if(lc==-1 || rc==-1){
            cameras++;
            return 0;
        }
        if(lc==0 || rc==0) return 1;
        
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        if(minCameraCover_helper(root)==-1) cameras++;
        
        return cameras;
    }
};

// 979. Distribute Coins in Binary Tree
// https://leetcode.com/problems/distribute-coins-in-binary-tree/


class Solution {
public:
    
    int moves=0;
    
    int dfs_helper(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        int lc=dfs_helper(root->left);
        int rc=dfs_helper(root->right);
        
        int coins = lc+rc;
        
        if(root->val==0)
            coins-=1;
        else if(root->val==1)
            coins+=0;
        else
            coins+=root->val-1;
        
        moves+=abs(coins);
        
        return coins;
    }
    int distributeCoins(TreeNode* root) {
        int coins = dfs_helper(root);
        return moves;
    }
};

// 112. Path Sum112. Path Sum
// https://leetcode.com/problems/path-sum/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        
        if(root->left==NULL and root->right==NULL)
        {
            if(targetSum-root->val==0) return true;
            return false;
        }
        
        bool left=hasPathSum(root->left,targetSum-root->val);
        bool right=hasPathSum(root->right, targetSum-root->val);
        
        bool ans = left or right;
        return ans;
    }
};

// 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/

class Solution {
public:
    
    int helper(TreeNode* root,int target,vector<int>&smallAns, vector<vector<int>>&bigAns)
    {
        if(root==NULL) return 0;
        smallAns.push_back(root->val);
        
        if(root->left==NULL and root->right==NULL and target-root->val==0)
        {
           bigAns.push_back(smallAns);
            smallAns.pop_back();
            return 1;
        }
        
        int count =0;
        
        count+=helper(root->left, target-root->val, smallAns,bigAns);
        count+=helper(root->right,  target-root->val, smallAns , bigAns);
        smallAns.pop_back();
        
        return count;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>smallAns;
        vector<vector<int>>bigAns;
        int ans = helper(root, targetSum, smallAns, bigAns);
        cout<<ans;
        return bigAns;
    }
};

// 437. Path Sum III
// https://leetcode.com/problems/path-sum-iii/

class Solution {
public:
    
     int count =0;
    
    void helper(TreeNode* root, int target)
    {
        if(root==NULL) return ;
        
        if(target-root->val==0)
            count++;
       
        helper(root->left ,target-root->val);
        helper(root->right, target-root->val);
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        
       helper(root, targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right, targetSum);
        
        return count;
        
    }
};

// 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

class Solution {
public:
    
    TreeNode* helper(vector<int>&nums, int start,int end)
    {
        if(start>end) return NULL;
        int mid =(start + end)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        
        root->left =helper(nums, start,mid-1);
        root->right=helper(nums, mid+1, end);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            v.push_back(curr->val);
            curr=curr->next;
        }
        
        return helper(v, 0, v.size()-1);
    }
};

// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


class Solution {
public:
    
    TreeNode* helper(vector<int>& inorder, vector<int>&postorder, int istart, int iend, int pstart, int pend )
    {
        if(istart > iend)return NULL;
        
        TreeNode* root= new TreeNode(postorder[pend]);
        
        int rootIdx=istart;
        for(;rootIdx<=iend;rootIdx++)
        {
            if(inorder[rootIdx]==postorder[pend])
                break;
        }
        
        int leftTreeSize=rootIdx-istart;
        int rightTreeSize=iend-rootIdx;
        
        root->left=helper(inorder, postorder, istart,rootIdx-1, pstart, pstart+leftTreeSize-1);
        root->right=helper(inorder, postorder,rootIdx+1,iend, pend-rightTreeSize, pend-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,0,inorder.size()-1, 0,postorder.size()-1);
    }
};