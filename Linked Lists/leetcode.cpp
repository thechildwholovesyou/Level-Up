// 1367. Linked List in Binary Tree
// https://leetcode.com/problems/linked-list-in-binary-tree/

class Solution {
public:
    
    // dfs 
    bool helper(ListNode* head, TreeNode* root)
    {
        if(head==NULL) return true;
        if(root==NULL || root->val!=head->val) return false;
        
        
        return helper(head->next,root->left) || helper(head->next, root->right);
        
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL) return false;
        
        if(helper(head,root)) return true;
        
        return isSubPath(head, root->left) || isSubPath(head,root->right);
    }
};