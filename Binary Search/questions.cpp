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

