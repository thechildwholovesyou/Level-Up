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

// 102. Binary Tree Level Order Traversal

//https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> bigAns;
        
        if(root==NULL) return bigAns;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size =q.size();
            vector<int> smallAns;
            while(size--)
            {
                TreeNode* temp = q.front();
                q.pop();
                smallAns.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            bigAns.push_back(smallAns);
        }
        return bigAns;
    }
};

// 107. Binary Tree Level Order Traversal II

// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// reverse method 

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> bigAns;
        
        if(root==NULL) return bigAns;
        queue<TreeNode*> q;
        stack<vector<int>>s;
        q.push(root);
        while(!q.empty())
        {
            int size =q.size();
            vector<int> smallAns;
            while(size--)
            {
                TreeNode* temp = q.front();
                q.pop();
                smallAns.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            s.push(smallAns);
        }
        while(!s.empty())
        {
            vector<int> temp=s.top();
            bigAns.push_back(temp);
            s.pop();
        }
        return bigAns;
    }
};

// without using reverse => soon 





// 199. Binary Tree Right Side View

// https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
       
        vector<int> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
       
        while(q.size() >0)
        {
            int size=q.size();
            
            while(size--)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                if(size==0)
                    ans.push_back(temp->val);
                
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                
            }
            
        }
        return ans;
    }
};

// 116. Populating Next Right Pointers in Each Node

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*> q;
        Node* nextP=NULL;
        if(root==NULL) return root;
        q.push(root);
       
        
        while(q.size() >0)
        {
            int size=q.size();
            while(size--)
            {
                Node* temp=q.front();
                q.pop();
                temp->next=nextP;
                nextP=temp;
                
                if(temp->right!=NULL)
                    q.push(temp->right);
                if(temp->left!=NULL)
                    q.push(temp->left);
                
            }
             nextP=NULL;
           
        }
        return root;
    }
};

// 117. Populating Next Right Pointers in Each Node II => same hi question tha bc  literally same 
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*> q;
        Node* nextP=NULL;
        if(root==NULL) return root;
        q.push(root);
       
        
        while(q.size() >0)
        {
            int size=q.size();
            while(size--)
            {
                Node* temp=q.front();
                q.pop();
                temp->next=nextP;
                nextP=temp;
                
                if(temp->right!=NULL)
                    q.push(temp->right);
                if(temp->left!=NULL)
                    q.push(temp->left);
                
            }
             nextP=NULL;
           
        }
        return root;
    }
};

//  Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
         List<List<Integer>> v=new ArrayList<>();
        
        if(root==null) return v;
        
        Queue<TreeNode> q=new LinkedList<>();
        q.add(root);
        
        boolean f=false;
        
        while(!q.isEmpty())
        {
            int size=q.size();
            List<Integer> t=new ArrayList<>();
            while(size-- >0)
            {
                TreeNode temp=q.poll();
                
                t.add(temp.val);
                
               if(temp.left!=null)
                   q.add(temp.left);
                if(temp.right!=null)
                   q.add(temp.right);
                
            }
            if(f==true) Collections.reverse(t);
            f=!f;
            v.add(t);
        }
        return v;
    }
}

// 590. N-ary Tree Postorder Traversal
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

class Solution {
public:
    
    void postorder_helper(Node* root, vector<int>&v)
    {
        if(root==NULL) return;
        
        for(Node* child: root->children)
            postorder_helper(child,v);
        v.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        vector<int> v;
        postorder_helper(root, v);
        return v;
    }
};

// 589. N-ary Tree Preorder Traversal
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

class Solution {
public:
    
    void preorder_helper(Node* root, vector<int>&v)
    {
        if(root==NULL) return;
        v.push_back(root->val);
        for(Node* child: root->children)
            preorder_helper(child, v);
    }
    
    vector<int> preorder(Node* root) {
       vector<int> v;
        preorder_helper(root, v);
        return v;
    }
};

// 429. N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>> v;
        queue<Node*> q;
        if(root==NULL) return v;
        q.push(root);
       
        
        while(q.size() >0)
        {
            int size=q.size();
            
            vector<int> t;
            while(size--)
            {
                Node* temp=q.front();
                q.pop();
                t.push_back(temp->val);
                
                
               for(Node* child: temp->children)
                   q.push(child);
                
            }
            v.push_back(t);
            
        }
        return v;
    }
};

// 1325. Delete Leaves With a Given Value
// https://leetcode.com/problems/delete-leaves-with-a-given-value/

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return NULL;
        
        // base case 
        
        if(!root->left and !root->right and root->val==target) return NULL;
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right, target);
        
        if(!root->left and !root->right and root->val==target) return NULL;
        
        return root;
        
    }
};