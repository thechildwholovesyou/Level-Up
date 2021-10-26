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