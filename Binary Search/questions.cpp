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