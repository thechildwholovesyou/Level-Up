//105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    
    int findPosition(vector<int>&inorder, int element,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(inorder[i]==element)
                return i;
        }
        return -1;
    }
    
    TreeNode* helper(vector<int>& inorder,int &index,  vector<int>& preorder, int istart, int iend,int n)
    {
        if(index>=n or istart>iend) return NULL;
        TreeNode* node = new TreeNode(preorder[index++]);
        
        // findPos
        int pos = findPosition(inorder, node->val,n);
        node->left = helper(inorder,index,  preorder, istart, pos-1,n);
        node->right = helper(inorder,index, preorder, pos+1, iend, n);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int index=0;
        return helper(inorder, index, preorder, 0, n,n);
        
    }
};

// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
public:
    int findPosition(vector<int>&inorder, int element,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(inorder[i]==element)
                return i;
        }
        return -1;
    }
    
    TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int &index,int istart, int iend,int n)
    {
        if(index<0 or istart>iend) return NULL;
        TreeNode* node = new TreeNode(postorder[index--]);
        
        // findPos
        int pos = findPosition(inorder, node->val,n);
        node->right = helper(inorder, postorder,index, pos+1, iend, n);
        node->left = helper(inorder, postorder,index, istart, pos-1,n);
            
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int index=n-1;
        return helper(inorder, postorder,index, 0, n-1,n);
    }
};

// Construct Binary Tree From In-order and Level-order.
// https://www.codingninjas.com/codestudio/problems/construct-binary-tree-from-in-order-and-level-order_2824774

unordered_map<int, int>m;
TreeNode* helper(vector<int>&inorder, int istart, int iend)
{
    if(istart>iend) return NULL;
    
    int k=istart;
    for(int i=istart+1;i<=iend;i++)
    {
        if(m[inorder[i]] < m[k])
            k=i;
    }
    TreeNode* node = new TreeNode(inorder[k]);
    if(istart == iend) return node;
    
    node->left = helper(inorder, istart, k-1);
    node->right = helper(inorder,k+1, iend);
    
    return node;
}

TreeNode* getTreeFromInorderAndLevelorder(int n, vector<int> &inorder, vector<int> &levelOrder)
{
	// Write your code here.
    for(int i=0;i<levelOrder.size();i++)
    {
        m[levelOrder[i]]=i;
    }
    return helper(inorder, 0, inorder.size()-1);
}

// https://www.geeksforgeeks.org/construct-bst-given-level-order-traversal/

// 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int ld=maxDepth(root->left);
        int rd=maxDepth(root->right);
        return max(ld, rd)+1;
    }
};

// 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ld =minDepth(root->left);
        int rd =minDepth(root->right);
        if(ld ==0 or rd==0) return ld+rd+1;
        return min(ld, rd)+1;
    }
};

// https://www.interviewbit.com/problems/path-to-given-node/
// Path to Given Node

 
 bool helper(TreeNode* root, int node, vector<int>&v)
 {
     if(!root) return false;
     v.push_back(root->val);
     
     if(root->val == node)
        return true;
    
    if(helper(root->left, node, v) or helper(root->right, node, v))
        return true;
    
    v.pop_back();
    return false;
     
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    if(A==NULL) return v;
    helper(A,B, v);
    cout<<dist;
    return v;
}

// root to node distance : refer prev sol

// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int d=0;
    int helper(TreeNode* root)
    {
        if(!root) return 0;
        int lh = helper(root->left);
        int rh = helper(root->right);
        d=max(d, lh+rh);
        
        return max(lh, rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        return helper(root);
        //return d;
    }
};

// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    
     int sumNumbers(TreeNode* root, int sum=0) {
        // pre order 
        if(root == NULL)  return 0;
        sum = sum*10 + root->val;
        if(!root->left && !root->right)
            return sum;
        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }
};

// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    
    int maxi = INT_MIN;
    int helper(TreeNode* root)
    {
        if(!root) return 0;
        int ls = helper(root->left);
        int rs =helper(root->right);
        
        if(ls<0) ls=0;
        if(rs<0) rs=0;
        
        maxi = max(maxi, ls+rs+root->val);
        return max(ls+root->val, rs+root->val);
    }
    
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxi;
    }
};

// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or p==root or q==root) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p,q);
        
        if(l==NULL) return r;
        if(r==NULL) return l;
        return root;
    }
}; 

// 1123. Lowest Common Ancestor of Deepest Leaves
// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

class Solution {
public:
    int height(TreeNode* root)
    {
        if(!root) return 0;
        return max(height(root->left), height(root->right))+1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL;
        int lh = height(root->left);
        int rh = height(root->right);
        
        if(lh==rh) return root;
        if(lh> rh) return lcaDeepestLeaves(root->left);
        return lcaDeepestLeaves(root->right);
    }
};

// Print path between any two nodes in a Binary Tree
// https://www.geeksforgeeks.org/print-path-between-any-two-nodes-in-a-binary-tree/

// Print nodes at k distance from root

void printKDistant(node *root , int k)
{
    if(root == NULL|| k < 0 )
        return;
    if( k == 0 )
    {
        cout << root->data << " ";
         return;
    }
     
        printKDistant( root->left, k - 1 ) ;
        printKDistant( root->right, k - 1 ) ;
     
}


// Burn a Binary Tree 

// 2385. Amount of Time for Binary Tree to Be Infected
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

class Solution {
public:
    
    int maxi=INT_MIN;
   bool rootToNodePath(TreeNode* root, int target,vector<TreeNode*>&v)
    {
        if(!root) return false;
        v.push_back(root);
        if(root->val == target) return true;
        if(rootToNodePath(root->left, target, v) or rootToNodePath(root->right, target, v))
            return true;
        v.pop_back();
        return false;
    }
    void kDown(TreeNode* root, TreeNode* blockNode, int time)
    {
        if(root==NULL or root==blockNode) return;
        maxi=max(maxi, time);
        kDown(root->left, blockNode, time+1);
        kDown(root->right, blockNode, time+1);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        vector<TreeNode*> paths;
        rootToNodePath(root, start, paths);
        reverse(paths.begin(), paths.end());

        for(int i=0; i<paths.size(); i++) {
            if(i == 0) {
                kDown(paths[i], NULL, i);
            }
            else {
                kDown(paths[i], paths[i-1], i);
            }
        }
        return maxi;
    }
};

// 863. All Nodes Distance K in Binary Tree
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class Solution {
public:
    
    bool rootToNodePath(TreeNode* root, TreeNode* target,vector<TreeNode*>&v)
    {
        if(!root) return false;
        v.push_back(root);
        if(root==target) return true;
        if(rootToNodePath(root->left, target, v) or rootToNodePath(root->right, target, v))
            return true;
        v.pop_back();
        return false;
    }
    
    void kDown(TreeNode* root, int k, TreeNode* blockNode, vector<int>&ans)
    {
        if(root==NULL or root==blockNode) return;
        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }
        kDown(root->left, k-1, blockNode, ans);
        kDown(root->right, k-1, blockNode, ans);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> paths;
        //reverse(paths.begin(), paths.end());
        rootToNodePath(root, target, paths);
        
        for(auto ele: paths) cout<<ele->val<<" ";
        cout<<endl;
        
        
        TreeNode* blockNode= NULL;
        vector<int> ans;
        for(int i = paths.size()-1;i >= 0 and k >= 0;i--,k--){
            kDown(paths[i],k, blockNode,ans);
            blockNode= paths[i];
        }
        
        return ans;
    }
};

// 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    void helper(TreeNode* root, string smallAns, vector<string>&bigAns)
    {
        if(!root) return;
        if(!root->left and !root->right)
        {
            smallAns+=to_string(root->val);
            bigAns.push_back(smallAns);
            return;
        }
        
        smallAns+=to_string(root->val);
        smallAns+="->";
        
        helper(root->left, smallAns, bigAns);
        helper(root->right, smallAns, bigAns);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> bigAns;
        helper(root, "", bigAns);
        return bigAns;
    }
};

// 112. Path Sum
// https://leetcode.com/problems/path-sum/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left and !root->right)
        {
            targetSum-=root->val;
            if(targetSum==0) return true;
            return false;
        }
        targetSum-=root->val;
        bool left = hasPathSum(root->left, targetSum);
        bool right =hasPathSum(root->right, targetSum);
        
        return left or right;
    }
};

// 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/

class Solution {
public:
    
    void helper(TreeNode* root, int target, vector<int>&smallAns, vector<vector<int>>&bigAns)
    {
        if(!root) return;
        smallAns.push_back(root->val);
        if(!root->left and !root->right and target-root->val==0)
        {
            bigAns.push_back(smallAns);
            smallAns.pop_back();
            return;
        }
        helper(root->left, target-root->val, smallAns, bigAns);
        helper(root->right, target-root->val, smallAns, bigAns);
        
        smallAns.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>bigAns;
        vector<int> smallAns;
        if(!root) return bigAns;
        
        helper(root, targetSum, smallAns, bigAns);
        return bigAns;
    }
};

// 437. Path Sum III
// https://leetcode.com/problems/path-sum-iii/

class Solution {
public:
    
    int cnt=0;
    void helper(TreeNode* root, int targetSum)
    {
        if(!root) return ;
        if(targetSum-root->val==0)
        {
            cnt++;
        }
        helper(root->left, targetSum-root->val);
        helper(root->right, targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        helper(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        
        return cnt;
    }
};

// optimal O(n)

class Solution {
public:
    unordered_map<long, int> m;
    
    int cnt=0;
    void helper(TreeNode* root, int target, long sum)
    {
        if(!root) return;
        sum+=root->val;
        
        if(sum==target) cnt++;
        if(m.find(sum-target)!=m.end())
            cnt+=m[sum-target];
        m[sum]++;
        
        helper(root->left, target, sum);
        helper(root->right, target, sum);
        
        m[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        helper(root, targetSum, 0);
        return cnt;
    }
};

