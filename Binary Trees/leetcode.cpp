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

// Node to root Path => leetcode pe nhi h 

bool rootToNodePath(TreeNode* root, int data, vector<int>&ans)
{
    if(root==NULL) return false;
    if(node->val==data)
    {
        ans.push_back(node->val);
        return true;
    }
    bool res= rootToNodePath(root->left,data,ans) || rootToNodePath(root->right,data,ans);

    if(res)
    {
        ans.push_back(node->val);
    }
    return res;
}


// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

// using static variable

class Solution {
public:
    
     TreeNode* prev=NULL;
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        if(!isValidBST(root->left)) return false;
        
        if(prev!=NULL and prev->val >= root->val) return false;
        
        prev=root;
        
        if(!isValidBST(root->right)) return false;
        
        return true;
    }
};

// without using static variabe





// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/
// O(n^2)

class Solution {
public:
    
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        return max(height(root->left),height(root->right))+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lh=height(root->left);
        int rh=height(root->right);
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
        
        if(abs(lh-rh)<=1) return true;
        
        return false;
        
    }
};

// optimised

class Solution {
public:
    pair<int,bool> isBalancedHelper(TreeNode* root)
    {
       if(root==NULL) {return {-1,true};}
        
        pair<int,bool> lpair=isBalancedHelper(root->left);
        if((lpair.second)==false) return lpair;
        
        pair<int,bool> rpair=isBalancedHelper(root->right);
        if((rpair.second)==false) return rpair;
        
        pair<int,bool> ans;
        
        if(abs(lpair.first - rpair.first)>1)
        {
            // ans.second=false;
            return ans;
        }
        ans.second=true;
        
        ans.first = max(lpair.first , rpair.first )+1;
        
        return ans;
        
        
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans=isBalancedHelper(root);
        return ans.second;
    }
};