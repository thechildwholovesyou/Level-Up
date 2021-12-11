//  Binary Search on Reverse Sorted Array

int binary_search(vector<int>&nums ,int key)
{
    int l=0;
    int h=nums.size()-1;

    while(l<=h)
    {
        int mid = l+(h-l)/2;
        if(nums[i]==nums[mid])
            return mid;
        else if(nums[i]>nums[mid])
            high=mid-1;
        else
            start=mid+1;
    }
    return -1;
}


// Order Agnostic Search 

int search(vector<int>&nums, int key)
{
    if(nums.size()==1 and num[0]==key) return key;

    if(nums[0]<nums[1])
        return binary_search_asc(nums,key);
    else if(nums[0]>nums[1])
        return binary_search_desc(nums,key);

    return -1; 
}

// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        
    int n=arr.size();
    vector<int> ans;
    int low=0;
    int high=n-1;
    int res=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]>x)
            high=mid-1;
        else if(arr[mid]<x)
            low=mid+1;
        else
        {
            res=mid;
            high=mid-1;
        }
    }
    ans.push_back(res);
    
    // last occ
    res=-1;
    low=0;
    high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]>x)
            high=mid-1;
        else if(arr[mid]<x)
            low=mid+1;
        else{
            res=mid;
            low=mid+1;
        }
    }
    ans.push_back(res);
    
    return ans;
    }
};


// Number of occurrence 

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	
    
    int low=0;
    int high=n-1;
    int res1=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]>x)
            high=mid-1;
        else if(arr[mid]<x)
            low=mid+1;
        else
        {
            res1=mid;
            high=mid-1;
        }
    }
    

    // last occ
    int res2=-1;
    low=0;
    high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]>x)
            high=mid-1;
        else if(arr[mid]<x)
            low=mid+1;
        else{
            res2=mid;
            low=mid+1;
        }
    }
    
    int ans = res2-res1;
    
    if(ans) return ans;
    else return 0;
 
	}
};

// find rotation count in rotated sorted array
#include<bits/stdc++.h>
using namespace std;
int get_ans(vector<int>&nums)
{
    int s=0;
    int e=nums.size()-1;
    int n=nums.size();
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int prev=(mid+n-1)%n;
        int next=(mid+1)%n;
        if(nums[mid]<=nums[prev] and nums[mid]<=nums[next])
            return mid;
        else if(nums[e]<=nums[mid])
            s=mid+1;
        else if(nums[mid]<=nums[e])
            e=mid-1;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        v.push_back(data);
    }
    int x=get_ans(v);
    cout<<x<<endl;
}

// 1752. Check if Array Is Sorted and Rotated
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
        bool flag=false;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int curr=i;
            int next=(i+1)%n;
            if(nums[curr]<=nums[next]) continue;
            else
                cnt++;
        }
        if(cnt<=1)
            flag=true;
        return flag;
    }
};

// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int min_idx(vector<int>&nums)
    {
        int n=nums.size();
        int s=0;
        int e=n-1;
        if(nums[s]<nums[e]) return 0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int prev=(mid+n-1)%n;
            int next=(mid+1)%n;
            if(nums[mid]<=nums[prev] and nums[mid]<=nums[next]) return mid;
            else if(nums[e]<=nums[mid])
                s=mid+1;
            else if(nums[mid]<=nums[e])
                e=mid-1;
        }
        return 0;
    }
    int binary_search(vector<int>&nums, int low,int high,int target)
    {
        int s=low;
        int e=high;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                return ans;
            }
            else if(nums[mid]<target) s=mid+1;
            else if(nums[mid]>target)
                e=mid-1;
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        // first find the min element idx
        int n=nums.size();
        int midx=min_idx(nums);
        int a=binary_search(nums,0,midx-1,target);
        int b=binary_search(nums,midx,n-1,target);
        
        if(a==b) return a;
        else if(a==-1) return b;
        return a;
        
    }
};

// 1011. Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    bool isValid(vector<int>&nums,int wt,int k)
    {
        int days=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>wt)
            {
                days++;
                sum=nums[i];
            }
        }
        if(days<=k) return true;
        return false;
    }
    int shipWithinDays(vector<int>& nums, int k) {
        int sum=0;
        for(auto ele:nums)
            sum+=ele;
        int s=*max_element(nums.begin(),nums.end());
        int e=sum;
        int res=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isValid(nums,mid,k))
            {
                res=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return res;
    }
};

// 410. Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    int isValid(vector<int>&nums, int mx,int k)
    {
        int p=1; // ek partition to banta hai 
        int sum=0; // subarray sum 
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>mx)
            {
                p++;
                sum=nums[i];
            }
        }
        if(p<=k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(auto ele:nums)
            sum+=ele;
        int s=*max_element(nums.begin(),nums.end());
        int e=sum;
        
        int res=-1;
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isValid(nums,mid,k))
            {
                res=mid;
                e=mid-1;
            }
            else 
                s=mid+1;
        }
        return res;
    }
};