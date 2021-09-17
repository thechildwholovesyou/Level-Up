// 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) {
       if(root==NULL) return 0;
        
        int ld=maxDepth(root->left);
        int rd=maxDepth(root->right);
        
        return max(ld,rd)+1;
    }
};

//  144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/
class Solution {
public:
    
    void preorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL) return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder(root, ans);
        return ans;
    }
};

// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>&ans)
    {
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root, ans);
        return ans;
    }
};

// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
public:
    
     void postorder(TreeNode* root, vector<int>&ans)
    {
        if(root==NULL) return;
        postorder(root->left,ans);
        postorder(root->right,ans);
         ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};

// 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};