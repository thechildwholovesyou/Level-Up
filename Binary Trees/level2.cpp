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

// 572. Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/

class Solution {
public:
    
    bool helper(TreeNode* root, TreeNode* subRoot)
    {
        if(!root and !subRoot) return true;
        if((root && !subRoot)||(!root && subRoot))
            return false;
        return root->val==subRoot->val && helper(root->left,subRoot->left) && helper(root->right, subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(subRoot==NULL) return true;
        
        if(helper(root, subRoot)) return true;
        
        return isSubtree(root->left , subRoot) || isSubtree(root->right, subRoot);
    }
};

// 938. Range Sum of BST
// https://leetcode.com/problems/range-sum-of-bst/

class Solution {
public:
        int sum=0;
    int inorder(TreeNode* root,int L,int R)
    {
        if(root){
        inorder(root->left,L,R);
        if(root->val>=L && root->val<=R)
            sum+=root->val;
        inorder(root->right,L,R);
        }
        return sum;
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)return 0;
        return inorder(root,L,R);
    }
    
};

// 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    
    void helper(TreeNode* root, vector<string>&bigAns, string smallAns)
    {
        if(root->left==NULL && root->right==NULL)
        {
           smallAns+=to_string(root->val);
            bigAns.push_back(smallAns);
            return;
        }
         smallAns+=to_string(root->val);
        smallAns+="->";
        
        if(root->left) helper(root->left,bigAns,smallAns);
        if(root->right) helper(root->right, bigAns, smallAns);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> bigAns;
        if(!root) return bigAns;
    
        helper(root,bigAns, "");
        
        return bigAns;
        
    }
};

// 783. Minimum Distance Between BST Nodes
// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

class Solution {
public:
    
    TreeNode* prev=NULL;
    int min_diff=INT_MAX;
    
    void inorder(TreeNode* root)
    {
        if(root)
        {
                inorder(root->left);
            if(prev!=NULL and root->val-prev->val <min_diff)
            {
                min_diff=root->val - prev->val;
            }
            prev=root;
            inorder(root->right);
        }
        
    }
    
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        inorder(root);
        return min_diff;
    }
};

// 530. Minimum Absolute Difference in BST
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/


class Solution {
public:
    
     TreeNode* prev=NULL;
    int min_diff=INT_MAX;
    
    void inorder(TreeNode* root)
    {
        if(root)
        {
                inorder(root->left);
            if(prev!=NULL and abs(root->val-prev->val )<min_diff)
            {
                min_diff=abs(root->val - prev->val);
            }
            prev=root;
            inorder(root->right);
        }
        
    }
    
    
    int getMinimumDifference(TreeNode* root) {
         if(!root) return 0;
        inorder(root);
        return min_diff;
    }
};

// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

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

// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/

class Solution {
public:
    int sum=0;
    void helper(TreeNode* root)
    {
        if(!root) return ;
        
        if(root->left and !root->left->left and !root->left->right)
            sum+=root->left->val;
        helper(root->left);
        helper(root->right);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return sum;
    }
};

// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool check(TreeNode* r1, TreeNode* r2)
    {
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        
        if(r1->val !=r2->val) return false;
        return check(r1->left,r2->right) and check(r1->right,r2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        return check(root->left,root->right);
    }
};

// 1448. Count Good Nodes in Binary Tre
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

class Solution {
public:
    
    int preorder(TreeNode* root, int maxi)
    {
        if(!root) return 0;
       int ans =0;
        if(root->val>=maxi)
            ans=1;
         
        maxi=max(maxi,root->val);
        int left = preorder(root->left,maxi);
        int right = preorder(root->right,maxi);
        
        ans+=left+right;
        return ans;
    }
    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return preorder(root, INT_MIN);
    }
};

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

// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int pstart,int pend, int istart, int iend)
    {
        // base case 
        if(pend<pstart)
            return NULL;
        // first make root node using preorder 
        TreeNode* node=new TreeNode(preorder[pstart]);
        // search the root in inorder array 
        int k=-1;
        for(int i=istart;i<=iend;i++)
        {
            if(inorder[i]==node->val)
            {
                k=i;
                break;
            }
        }
        // calculate count of left subtree wrt node
        int cls=k-istart;
        
        node->left=helper(preorder, inorder, pstart+1,pstart+cls,istart,k-1);
        node->right=helper(preorder, inorder,pstart+cls+1,pend,k+1,iend);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        TreeNode* node=helper(preorder,inorder,0,n-1,0,n-1);
        return node;
    }
};

// java code
 /**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode helper(int[] preorder , int[] inorder, int ps,int pe,int is,int ie)
    {
        // base case 
        if(ps>pe)
            return null;
        
        // make root using pre first element 
        TreeNode node= new TreeNode(preorder[ps]);
        // search the node in inorder array 
        int k=-1;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==node.val)
            {
                k=i;
                break;
            }
        }
        // count left subtree nodes wtr root node
        int cls=k-is;
        
        node.left=helper(preorder, inorder, ps+1,ps+cls,is,k-1);
        node.right=helper(preorder, inorder, ps+cls+1,pe,k+1,ie);
        return node;
    }
    public TreeNode buildTree(int[] preorder , int[] inorder) {
        int n=preorder.length;
        TreeNode root=helper(preorder, inorder, 0,n-1,0,n-1);
        return root;
    }
}

// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
public:
    
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int ps,int pe, int is,int ie)
    {
        if(is>ie) return NULL;
        // make root node from post ka end 
        TreeNode* node= new TreeNode(postorder[pe]);
        // serch in inorder 
        int k=-1;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==node->val)
            {
                k=i;
                break;
            }
        }
        // count left tree nodes wrt to root node
        int cls=k-is;
        
        node->left =helper(inorder,postorder,ps,ps+cls-1,is,k-1);
        node->right=helper(inorder,postorder,ps+cls,pe-1,k+1,ie);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        TreeNode* node=helper(inorder, postorder, 0,n-1,0,n-1);
        return node;
    }
};

// 889. Construct Binary Tree from Preorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int prs,int pre,int poss, int pose)
    {
        if(prs>pre or poss> pose) return NULL;
        if(prs==pre){
            return new TreeNode(preorder[prs]);
        }
        TreeNode* root=new TreeNode(preorder[prs]);
        int val=preorder[prs+1];
        int idx=-1;
        
        for(int i=0;i<postorder.size()-1;i++)
        {
            if(postorder[i]==val)
            {
                idx=i;
                break;
            }
        }
        int cls=idx-poss+1;
        root->left=helper(preorder, postorder, prs+1, prs+cls,poss,idx);
        root->right=helper(preorder, postorder, prs+cls+1,pre,idx+1, pose-1);
        
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder ) {
        TreeNode* node= helper(preorder, postorder, 0,preorder.size()-1,0,postorder.size()-1);
        return node;
        
    }
};

// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class Solution {
public:
    TreeNode* helper(vector<int>& nums, int start,int end)
    {
        if(start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        
        root->left=helper(nums, start,mid-1);
        root->right=helper(nums,mid+1, end);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* node=helper(nums,0,nums.size()-1);
        return node;
    }
};