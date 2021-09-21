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