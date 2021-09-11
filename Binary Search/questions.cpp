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


