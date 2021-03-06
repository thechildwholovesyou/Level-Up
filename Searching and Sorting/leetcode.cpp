// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int firstIndex(vector<int>& nums, int target,int low,int high)
    {
        int res=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                res=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return res;
    }
    int lastIndex(vector<int>& nums, int target,int low,int high)
    {
        int res=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                res=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int p=firstIndex(nums,target,0,nums.size()-1);
        int q=lastIndex(nums, target,0,nums.size()-1);
        ans.push_back(p);
        ans.push_back(q);
        
        return ans;
    }
};

// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int i=0;
        int j=n-1;
        
        while(i<m and j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            while(matrix[i][j]<target)
            {
                if(i+1<m)
                    i++;
                else
                    return false;
            }
            while(matrix[i][j]>target)
            {
                if(j-1>=0)
                    j--;
                else
                    return false;
            }
        }
        return false;
    }
};

// Find closest number in array
// https://www.geeksforgeeks.org/find-closest-number-array/
// My appraoch using priority_queue(min)

#include<bits/stdc++.h>
using namespace std;

int getClosest(vector<int>&nums, int target)
{
    // unordered_map<int,int> m;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto ele: nums)
        pq.push({abs(target-ele), ele});
    
    int l=0;
    int h=nums.size()-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(nums[mid]==target)
            return nums[mid];
        if(nums[mid]>target)
            l=mid+1;
        else 
            h=mid-1;
    }
    return pq.top().second;
}
int main()
{
    vector<int> nums={1,2,3,4,5,6,7};
    int ans=getClosest(nums,10);
    cout<<ans;
}

// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    // for STL : use upper_bound 
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size(); // nums.size()-1 , isliye nhi liya because that could be my ans
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                h=mid;
            else
                l=mid+1;
        }
        return l; // return h will also work as l and h will be in the same pos
    }
};

// 658. Find K Closest Elements
// https://leetcode.com/problems/find-k-closest-elements/
// using Priority queues

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        for(auto ele: arr)
        {
            pq.push({abs(x-ele), ele});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// O(n) solution 

class Solution {
public:
    int perfectLocation(vector<int> &arr, int data)
{
    int si = 0, ei = arr.size();

    while (si < ei)
    {
        int mid = (si + ei) / 2;
        if (arr[mid] <= data)
            si = mid + 1;
        else
            ei = mid;
    }

    return ei; // si
}

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        if(x<=arr[0])
            return {arr.begin(), arr.begin()+k};
        else if(x>=arr[n-1])
            return {arr.end()-k, arr.end()};
        
        int idx=perfectLocation(arr,x);
        int low=max(0,idx-k);
        int high=min(n-1,idx+k);
        
        while((high-low+1)>k)
        {
            if((x-arr[low])>(arr[high]-x))
                low++;
            else
                high--;
        }
        return {arr.begin()+low, arr.begin()+high+1};
    }
};

// 1. Two Sum
// https://leetcode.com/problems/two-sum/
// using maps 0(n) extra space

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            else
                mp[nums[i]]=i;
        }
        return ans;
    }
};

// efficient sol 




// 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]+nums[j]==target)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if(nums[i]+nums[j]<target)
                i++;
            else
                j--;
        }
        return ans;
    }
};

// 653. Two Sum IV - Input is a BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class Solution {
public:
    void inorder(TreeNode* root, vector<int>&ans)
    {
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        vector<int> v;
        inorder(root,v);
        
        int i=0;
        int j=v.size()-1;
        while(i<j)
        {
            if(v[i]+v[j]==k)
                return true;
            else if(v[i]+v[j]<k)
                i++;
            else
                j--;
        }
        return false;
    }
};

// Given an int array nums and an int target, find how many unique pairs in the array such that their sum is equal to target. Return the number of pairs.
// https://leetcode.com/discuss/interview-question/372434/Amazon-or-OA-2019-or-Two-Sum-Unique-Pairs/391924
// without using any extra space 
// although this question can be easily solved by using sets : as set stores unique elements

vector<vector<int>> pairs(vector<int>&nums,int target)
{
    sort(nums.begin(), nums.end());
    int i=0;
    int j=nums.size()-1;

    vector<vector<int>> bigAns;
    while(i<j)
    {
        if(nums[i]+nums[j]==target)
        {
            vector<int> smallAns;
            smallAns.push_back(i);
            smallAns.push_back(j);
            i++;
            j--;

            while(i<j and nums[i]==nums[i-1]) i++;
            while(i<j and nums[j]==nums[j+1]) j--;
        }
        else if(nums[i]+nums[j]<target)
            i++;
        else
            j--;
    }
    return ans;
}

// 15. 3Sum
// https://leetcode.com/problems/3sum/

class Solution {
public:
     vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> ans;
        int i=start;
        int j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]+nums[j]==target)
            {
                ans.push_back({nums[i],nums[j]});
                i++;
                j--;

                while(i<j and nums[i]==nums[i-1]) i++;
                while(i<j and nums[j]==nums[j+1]) j--;
            }
            else if(nums[i]+nums[j]<target)
                i++;
            else
                j--;
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>bigAns;
        if(nums.size()<3) return bigAns;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i==0 || nums[i]!=nums[i-1])
            {
                vector<vector<int>> temp=twoSum(nums,i+1, -1*nums[i]);
                for(auto smallAns:temp)
                {
                    smallAns.push_back(nums[i]);
                    bigAns.push_back(smallAns);
                }
            }
            
        }
        return bigAns;
    }
};

// Find all pairs with a given sum
// https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1

class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here  
        vector<pair<int,int>> ans;
        set<int> s;
        for(int i=0;i<N;i++)
            s.insert(A[i]);
        
        for(int i=0;i<M;i++)
        {
            if(s.find(X-B[i])!=s.end())
            {
                ans.push_back({X-B[i],B[i]});
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    
};

// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> m;
        int cnt=0;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                m[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0;i<nums3.size();i++)
        {
            for(int j=0;j<nums4.size();j++)
            {
                if(m.find(-(nums3[i] + nums4[j])) != m.end()){
					cnt += m[-(nums3[i] + nums4[j])];
				}
            }
        }
        return cnt;
    }
};

// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// using pivot element  : O(logn)

class Solution {
public:
    int binarySearch(vector<int>& arr, int low,
                 int high, int key)
{
    if (high < low)
        return -1;
 
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == arr[mid])
        return mid;
 
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
 
    // else
    return binarySearch(arr, low, (mid - 1), key);
}
 
/* Function to get pivot. For array 3, 4, 5, 6, 1, 2
   it returns 3 (index of 6) */
int findPivot(vector<int>& arr, int low, int high)
{
    // base cases
    if (high < low)
        return -1;
    if (high == low)
        return low;
 
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
 
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
 
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
 
    return findPivot(arr, mid + 1, high);
}
 
/* Searches an element key in a pivoted
   sorted array arr[] of size n */
int pivotedBinarySearch(vector<int>& arr, int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);
 
    // If we didn't find a pivot,
    // then array is not rotated at all
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);
 
    // If we found a pivot, then first compare with pivot
    // and then search in two subarrays around pivot
    if (arr[pivot] == key)
        return pivot;
 
    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);
 
    return binarySearch(arr, pivot + 1, n - 1, key);
}
    int search(vector<int>& arr, int key) {
        return pivotedBinarySearch(arr,arr.size(),key);
    }
};

// optimise


// 81. Search in Rotated Sorted Array II
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// using extra space  

class Solution {
public:
     int binarySearch(vector<int>& arr, int low,
                 int high, int key)
{
    if (high < low)
        return -1;
 
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == arr[mid])
        return mid;
 
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
 
    // else
    return binarySearch(arr, low, (mid - 1), key);
}
 
/* Function to get pivot. For array 3, 4, 5, 6, 1, 2
   it returns 3 (index of 6) */
int findPivot(vector<int>& arr, int low, int high)
{
    // base cases
    if (high < low)
        return -1;
    if (high == low)
        return low;
 
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
 
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
 
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
 
    return findPivot(arr, mid + 1, high);
}
 
/* Searches an element key in a pivoted
   sorted array arr[] of size n */
int pivotedBinarySearch (vector<int>& arr, int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);
 
    // If we didn't find a pivot,
    // then array is not rotated at all
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);
 
    // If we found a pivot, then first compare with pivot
    // and then search in two subarrays around pivot
    if (arr[pivot] == key)
        return pivot;
 
    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);
 
    return binarySearch(arr, pivot + 1, n - 1, key);
}
    bool search(vector<int>& nums, int target) {
        set<int> s(nums.begin(),nums.end());
        vector<int> arr;
        for(auto ele: s)
            arr.push_back(ele);
        int res=pivotedBinarySearch(arr,arr.size(),target);
        if(res==-1) return false;
        return true;
    }
};

// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// brute force 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(auto ele:nums1)
            res.push_back(ele);
        for(auto ele:nums2)
            res.push_back(ele);
        sort(res.begin(),res.end());
         int n=res.size();
        if(res.size()%2!=0)
            return (double)(res[res.size()/2]);
       
        else
        {
            double x=((double)(res[(n-1)/2])+(double)(res[n/2]))/2;
            return x;
        }
    }
};

//optimise 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            swap(nums1,nums2);
        int n1=nums1.size(), n2=nums2.size();
        int total=n1+n2;
        
        int low=0,high=n1;
        while(low<=high)
        {
            int cut1=(low+high)/2;
            int cut2=((n1+n2+1)/2)-cut1;
            
            int al=cut1==0?INT_MIN:nums1[cut1-1];
            int bl=cut2==0?INT_MIN:nums2[cut2-1];
            int ar=cut1==n1?INT_MAX:nums1[cut1];
            int br=cut2==n2?INT_MAX:nums2[cut2];
            
            if(bl<=ar and al<=br)
            {
                if(total%2==0){
                    int x =max(al,bl)+min(ar,br);
                    return (x*1.0)/2.0;
                }
                else
                {
                    return max(al,bl);
                }
                    
            }
            if(bl>ar)
            {
                low=cut1+1;
            }
            else if(al>br)
            {
                high=cut1-1;
            }
        }
        return -1;
    }
};

// Allocate minimum number of pages
// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int arr[],int mid,int N,int M)
    {
        int st=1;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
            if(sum>mid)
            {
                st+=1;
                sum=arr[i];
            }
        }
        return st<=M;
    }
    int findPages(int arr[], int N, int M) 
    {
        //code here
        int maxi=0,sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
    
        int low=maxi;
        int high=sum;
        
        int ans=0;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(arr,mid,N,M))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};

// 1011. Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
     bool isPossible(vector<int>&arr,int mid,int M)
    {
        int st=1;
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum>mid)
            {
                st+=1;
                sum=arr[i];
            }
        }
        return st<=M;
    }
    int shipWithinDays(vector<int>& weights, int days) {
         int sum=0;
        int maxi=0;
        for(auto ele:weights)
        {
            sum+=ele;
            maxi=max(maxi,ele);
        }
        int low=maxi;
        int high=sum;
        
        int ans=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(weights,mid,days))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans; 
    }
};