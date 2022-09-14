// First and Last Position of an Element In Sorted Array

int firstOcc(vector<int>& arr, int n, int x)
{
    int low=0, high = n-1, res=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]>x)
            high=mid-1;
        else if(arr[mid]<x)
            low=mid+1;
        else if(arr[mid]==x)
        {
            res=mid;
            high=mid-1;
        }
    }
    return res;
}
int lastOcc(vector<int>& arr, int n, int x)
{
    int low=0, high = n-1, res=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]>x)
            high=mid-1;
        else if(arr[mid]<x)
            low=mid+1;
        else if(arr[mid]==x)
        {
            res=mid;
            low=mid+1;
        }
    }
    return res;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int,int> p;
    p.first = firstOcc(arr,n,k);
    p.second = lastOcc(arr,n,k);
    
    return p;
    
}

// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int low=0;
        int high = n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[low]<=nums[mid])
            {
                if(target>=nums[low] and target<nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else if(nums[mid]<=nums[high])
            {
                if(target>nums[mid] and target<=nums[high])
                    low = mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};

// 81. Search in Rotated Sorted Array II
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    int searchP(vector<int>& nums, int target) {
        int n= nums.size();
        int low=0;
        int high = n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            if((nums[low] == nums[mid]) && (nums[high] == nums[mid]))
            {
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid])
            {
                if(target>=nums[low] and target<nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else if(nums[mid]<=nums[high])
            {
                if(target>nums[mid] and target<=nums[high])
                    low = mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
    bool search(vector<int>& nums, int target) {
        int ans = searchP(nums, target);
        if(ans!=-1) return true;
        return false;
    }
};

// Square root of an integer
// https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        long long  low=0;
        long long  high = x;
        int ans =-1;
        
        while(low<=high)
        {
            long long  mid=low+(high-low)/2;
            if(mid*mid==x) return mid;
            
            else if(mid*mid<x)
            {
                low=mid+1;
                ans=mid;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};

// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high = n-1;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            
            if(nums[mid]>nums[high])
                low=mid+1;
            else
                high= mid;
        }
        return nums[low];
    }
};

// 154. Find Minimum in Rotated Sorted Array II
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high = n-1;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            
            if(nums[mid]>nums[high])
                low=mid+1;
            else if(nums[mid]<nums[high])
                high= mid;
            else
                high--;
        }
        return nums[low];
    }
};


// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int ele = nums[i];
            
            if(ele>=1 and ele<=n)
            {
                int chair = ele-1;
                if(nums[chair]!=ele)
                {
                    swap(nums[chair], nums[i]);
                    i--;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i+1!=nums[i]) return i+1;
        }
        return n+1;
    }
};

// 1539. Kth Missing Positive Number
// https://leetcode.com/problems/kth-missing-positive-number/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        set<int> s;
        for(auto ele: arr)
            s.insert(ele);
        int cnt=0;
        
        for(int i=0;i<=n+k;i++)
        {
            if(s.count(i)==1)
                continue;
            if(cnt==k)
                return i;
            cnt++;
        }
        return -1;
    }
};

// 169. Majority Element
// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int life=0;
        int ele = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele)
                life++;
            else if(life==0)
            {
                ele = nums[i];
                life++;
            }
            else
                life--;
        }
        return ele;
        
    }
};

// 229. Majority Element II
// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    
    bool check(vector<int>&nums, int x, int n)
    {
        int cnt=0;
        for(auto ele: nums)
            if(ele==x) cnt++;
        return (cnt>(n/3));
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int life1=0;
        int candidate1 = INT_MIN;
        int life2=0;
        int candidate2 = INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==candidate1)
                life1++;
            
             else if(nums[i]==candidate2)
                life2++;
            else if(life1==0)
            {
                candidate1 = nums[i];
                life1=1;
            }
           
            else if(life2==0)
            {
                candidate2 = nums[i];
                life2=1;
            }
            else
            {
                life1--;
                life2--;
            }
        }
        
        vector<int> ans;
        if(check(nums, candidate1, n)) ans.push_back(candidate1);
        if(check(nums, candidate2, n)) ans.push_back(candidate2);
        
        return ans;
    }
};

// Allocate Books
// https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?leftPanelTab=0

bool possible(vector<int> arr, int mid, int m)
{
    int student=1;
    int currPage =0;
    
    for(int i=0;i<arr.size();i++)
    {
        currPage+=arr[i];
        if(currPage>mid)
        {
            student++;
            currPage=arr[i];
        }
    }
    return student<=m;
}
int allocateBooks(vector<int> arr, int n, int m) {
    // Write your code here.
        int maxi=0,sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
    
        int low=maxi;
        int high=sum;
    
    int ans =0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(possible(arr,mid,m))
        {
            ans=mid;
            high=mid-1;
        } 
        else
            low=mid+1;
    }
    return ans;
}

// 1011. Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    
    bool check(vector<int>& weights,int mid, int days)
    {
        int d=1;
        int sum=0;
        
        for(auto ele: weights)
        {
            sum+=ele;
            if(sum>mid)
            {
                d++;
                sum=ele;
            }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        
        int sum=0;
        for(auto ele: weights)
            sum+=ele;
        
        int low=*max_element(weights.begin(),weights.end());
        int high = sum;
        
        int ans = 0;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(weights, mid, days))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
    
};

// 410. Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    
    bool check(vector<int>& nums, int mid,int k)
    {
        int cnt=1;
        int sum=0;
        for(auto ele: nums)
        {
            sum+=ele;
            if(sum>mid)
            {
                cnt++;
                sum=ele;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        int sum=0;
        for(auto ele: nums) sum+=ele;
        
        int low=*max_element(nums.begin(), nums.end());
        int high = sum;
        
        int ans=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(nums, mid, k))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};

//  Find the Smallest Divisor Given a Threshold
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    bool check(vector<int>&nums, int mid, int threshold)
    {
        int sum=0;
        for(auto ele: nums)
        {
            sum+=(int)ceil(ele*1.0/mid);
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low=1;
        int  high=*max_element(nums.begin(), nums.end());
        
        int ans=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(check(nums, mid, threshold))
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

