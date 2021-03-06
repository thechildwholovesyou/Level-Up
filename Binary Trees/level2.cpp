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

// 1008. Construct Binary Search Tree from Preorder Traversal
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// jugado solution using leetcode 105
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(), inorder.end());
        TreeNode* node =helper(preorder, inorder, 0,n-1,0,n-1);
        return node;
    }
};

// O(n) O(1) wala approach 

class Solution {
public:
    int idx;
    TreeNode*  helper(vector<int>&preorder, int l,int r)
    {
        if(idx>=preorder.size() ||  preorder[idx]<l || preorder[idx]>r) return NULL;
        
        TreeNode*  node=new TreeNode(preorder[idx]);
        idx++;
        
        node->left=helper(preorder,l,node->val-1);
        node->right=helper(preorder,node->val+1,r);
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        idx=0;
        return helper(preorder, INT_MIN, INT_MAX);
    }
};

// Construct BST from Postorder 
// https://practice.geeksforgeeks.org/problems/construct-bst-from-post-order/1#

int idx;
Node* helper(int post[],int l,int r)
{
    if(idx<0 or post[idx]<l or post[idx]>r) return NULL;
    
    Node* root= new Node(post[idx]);
    idx--;
    
    root->right=helper(post,root->data+1,r);
    root->left=helper(post,l,root->data-1);
    
    return root;
}

Node *constructTree (int post[], int size)
{
    idx=size-1;
    return helper(post, INT_MIN, INT_MAX);
}

// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> bigAns;
        vector<int> smallAns;
        if(!root) return bigAns;
        
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
           int size=q.size();
            vector<int> smallAns;
            while(size--)
            {
                TreeNode* temp=q.front();
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

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>bigAns;
        stack<vector<int>> s;
        if(!root) return bigAns;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> smallAns;
            while(size--)
            {
                TreeNode* temp=q.front();
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
            auto temp=s.top();
            s.pop();
            bigAns.push_back(temp);
        }
        return bigAns;
    }
};

// 637. Average of Levels in Binary Tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/

class Solution {
public:
    double calAvg(vector<int>& v)
    {
        double sum=0;
        for(auto ele:v)
            sum+=ele;
        return sum/v.size();
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        
        if(!root) return res;
        vector<vector<int>> bigAns;
        
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> smallAns;
            while(size--)
            {
                TreeNode* temp=q.front();
                q.pop();
                smallAns.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            bigAns.push_back(smallAns);
        }
        
        for(vector<int> v: bigAns)
        {
            res.push_back(calAvg(v));
        }
        return res;
    }
};

// 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> bigAns;
        if(!root) return bigAns;
        queue<TreeNode* > q;
        q.push(root);
        bool flag=false;
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int> smallAns;
            while(size--)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                smallAns.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(flag)
            {
                reverse(smallAns.begin(), smallAns.end());
                bigAns.push_back(smallAns);
            }
            else
                bigAns.push_back(smallAns);
            flag=!flag;
        }
        return bigAns;
    }
};

// Left View of Binary Tree 
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> bigAns;
   if(!root) return bigAns;
   queue<Node* > q;
   q.push(root);
   while(!q.empty())
   {
       int size=q.size();
       for(int i=1;i<=size;i++)
       {
           Node* temp=q.front();
           q.pop();
           
           if(i==1)
            bigAns.push_back(temp->data);
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
       }
   }
   return bigAns;
}

// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> bigAns;
        if(!root) return bigAns;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=1;i<=size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                if(i==size)
                    bigAns.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return bigAns;
    }
};

// 897. Increasing Order Search Tree
// https://leetcode.com/problems/increasing-order-search-tree/

class Solution {
public:
     TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};

// 671. Second Minimum Node In a Binary Tree
// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

class Solution {
public:
    void inorder(TreeNode* root, set<int> &s)
    {
        if(!root) return;
        inorder(root->left,s);
        s.insert(root->val);
        inorder(root->right,s);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        inorder(root, s);
        vector<int> v(s.begin(), s.end());
        if(v.size()==1) return -1;
        return v[1];
        
    }
};

// 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        
        root1->val+=root2->val;
        root1->left=mergeTrees(root1->left,root2->left);
        root1->right=mergeTrees(root1->right,root2->right);
        
        return root1;
    }
};

// 965. Univalued Binary Tree
// https://leetcode.com/problems/univalued-binary-tree/

class Solution {
public:
    
    bool isUnivalTree(TreeNode* root,int val=-1) {
        if(!root) return true;
        if(val<0) val=root->val;
        return root->val==val and isUnivalTree(root->left, val) and isUnivalTree(root->right,val);
    }
};

// 872. Leaf-Similar Trees
// https://leetcode.com/problems/leaf-similar-trees/

class Solution {
public:
    void helper(TreeNode* root, vector<int>&v)
    {
        if(!root) return;
        if(root->left==NULL and root->right==NULL) v.push_back(root->val);
        helper(root->left, v);
        helper(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 or !root2) return false;
        vector<int> v1;
        vector<int> v2;
        helper(root1, v1);
        helper(root2,v2);
        
        if(v1.size()!=v2.size()) return false;
        
        int i=0;
        int j=0;
        while(i<v1.size() or j<v2.size())
        {
            if(v1[i]!=v2[j])
                return false;
            i++;
            j++;
        }
        return true;
    }
};

// 1038. Binary Search Tree to Greater Sum Tree
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

class Solution {
public:
    void reversed_inorder_traversal(TreeNode* root, int &sum)
    {
        if(!root) return;
        reversed_inorder_traversal(root->right,sum);
        root->val+=sum;
        sum=root->val;
        reversed_inorder_traversal(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        reversed_inorder_traversal(root,sum);
        return root;
    }
};

// 1305. All Elements in Two Binary Search Trees
// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

class Solution {
public:
    void inorder_helper(TreeNode* root, vector<int>&v)
    {
        if(!root) return;
        inorder_helper(root->left,v);
        v.push_back(root->val);
        inorder_helper(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        if(!root1 and !root2) return ans;
        vector<int>v1;
        vector<int>v2;
        inorder_helper(root1,v1);
        inorder_helper(root2,v2);
        
        for(int i=0;i<v1.size();i++)
            ans.push_back(v1[i]);
        for(auto ele:v2)
            ans.push_back(ele);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// 501. Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/

class Solution {
public:
    void inorder_helper(TreeNode* root, unordered_map<int,int>&m)
    {
        if(!root) return;
        inorder_helper(root->left,m);
        m[root->val]++;
        inorder_helper(root->right,m);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        unordered_map<int,int> m;
        inorder_helper(root,m);
        
        int maxFreq;
        
        for(auto ele:m)
        {
            maxFreq=max(maxFreq,ele.second);
        }
        for(auto ele:m)
        {
            if(ele.second==maxFreq)
                ans.push_back(ele.first);
        }
        return ans;
    }
};

// 559. Maximum Depth of N-ary Tree
// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int cnt=1;
        for(Node* child:root->children)
            cnt=max(cnt,1+maxDepth(child));
        return cnt;
    }
};

// 235. Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution {
public:
    TreeNode* helper(TreeNode* root, int p,int q)
    {
        TreeNode* lca=NULL;
        while(root!=NULL)
        {
            if(root->val <p and root->val <q)
                root=root->right;
            else if(root->val >p and root->val >q)
                root=root->left;
            else
            {
                lca=root;
                break;
            }
        }
        return lca;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p->val,q->val);
    }
};


// 701. Insert into a Binary Search Tree
// https://leetcode.com/problems/insert-into-a-binary-search-tree/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int data) {
        if(root==NULL)
        {
            TreeNode* node=new TreeNode(data);
            return node;
        }
        
        if(root->val >= data)
            root->left=insertIntoBST(root->left,data);
        else if(root->val<data)
             root->right=insertIntoBST(root->right,data);
        
        return root;
    }
};

// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    
    void rootToLeafPaths(TreeNode* root, vector<string>&bigAns,string smallAns)
    {
        if(!root->left and !root->right)
        {
            smallAns+=to_string(root->val);
            bigAns.push_back(smallAns);
            return;
        }
        
        smallAns+=to_string(root->val);
        if(root->left) 
            rootToLeafPaths(root->left,bigAns, smallAns);
        if(root->right)
            rootToLeafPaths(root->right, bigAns, smallAns);
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        if(!root->left and !root->right) return root->val;
        
        vector<string> res;
        rootToLeafPaths(root, res, "");
        
        int sum=0;
        for(auto ele:res)
        {
            stringstream geek(ele);
 
            // The object has the value 12345 and stream
            // it to the integer x
            int x = 0;
            geek >> x;
            sum+=x;
        }
        return sum;
    }
};

// another DFS approach 
class Solution {
    private int dfs(TreeNode node, int path) {
    if (node == null) {
        return 0;
    }
    path = path*10 + node.val;
    if (node.left == null && node.right == null) {
        return path;
    }
    return dfs(node.left, path) + dfs(node.right, path);
}
    public int sumNumbers(TreeNode root) {
        return dfs(root,0);
    }
}

// 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/
// Brute force appoach

class Solution {
public:
    void inorder(TreeNode* root, int key,vector<int>&ans)
    {
        if(!root) return;
        inorder(root->left,key,ans);
        if(root->val!=key)
            ans.push_back(root->val);
        inorder(root->right,key,ans);
        
    }
    
    TreeNode* helper(int low,int high,vector<int>&res)
    {
        if(low>high) return NULL;
        int mid=low+(high-low)/2;
        TreeNode* root=new TreeNode(res[mid]);
        root->left=helper(low,mid-1,res);
        root->right=helper(mid+1,high,res);
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        //if(root->val==key) return NULL;
        vector<int> in;
        inorder(root, key,in);
        
        return helper(0,in.size()-1, in);
        
    }
};

// optimal approach 

class Solution {
       public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return null;
        
        if(root.val < key){
            root.right = deleteNode(root.right, key);
        }else if(root.val > key){
            root.left = deleteNode(root.left, key);
        }else{
            if(root.left != null && root.right != null){
                int v = findmax(root.left, Integer.MIN_VALUE);
                root.val = v;
                root.left = deleteNode(root.left, v);
                return root;
            }else if(root.left != null){
                return root.left;
            }else if(root.right != null){
                return root.right;
            }else{
                return null;
            }
            
        }
        return root;
    }
    
    
    private static int findmax(TreeNode root, int max){
       while(root !=null){
           max = Math.max(max, root.val);
           root = root.right;
       }
        return max;
    }
}

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

