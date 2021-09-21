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