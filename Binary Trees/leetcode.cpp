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

// find data in  a binaty tree => leetcode pe nhi h 

class Solution {
public:
    bool find(TreeNode* root,key) {
        if(root==NULL) return false;
        if(root->val == key)
            return true;

        return find(root->left,key) or find(root->right,key);
    }
};

// Count Leaves in Binary Tree
// https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

int countLeaves(Node* root)
{
  // Your code here
  if(root==NULL) return 0;
  if(root->left ==NULL && root->right==NULL) return 1;
  int ll=countLeaves(root->left);
  int rl=countLeaves(root->right);
  return ll+rl;
}

// Print the nodes having exactly one child in a binary tree =>leetcode pe nhi h 

void exactlyOneChild(TreeNode* root, vector<int>&ans)
{
    if(root==NULL or(root->left==NULL and root->right==NULL)) return;

    if(root->left==NULL or root->right==NULL)
        ans.push_back(root->val);

    exactlyOneChild(root, ans);
    exactlyOneChild(root, ans);
}

