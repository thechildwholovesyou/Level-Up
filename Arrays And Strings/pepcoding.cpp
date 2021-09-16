// two sum 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        
        vector<int> v;
        
        while(i<j)
        {
            if(i!=0 and nums[i]==nums[i-1])
            {
                i++;
                continue;
            }
            int sum=nums[i]+nums[j];
            if(sum==target)
            {
                v.push_back(i);
                v.push_back(j);
                i++;
                j--;
                break;
            }
            else if(sum<target)
                i++;
            else
                j--;
        }
        return v;
    }
};

// three sum 

class Solution {
public:
    
     vector<vector<int>>  twoSum(vector<int>& nums, int left,int right, int target) {
        sort(nums.begin(),nums.end());
        
         int i=left;
         int j=right;
        
        vector<vector<int>> v;
        
        while(i<j)
        {
            if(i!=0 and nums[i]==nums[i-1])
            {
                i++;
                continue;
            }
            int sum=nums[i]+nums[j];
            if(sum==target)
            {
               vector<int> smallAns;
                smallAns.push_back(nums[i]);
                smallAns.push_back(nums[j]);
                v.push_back(smallAns);
                i++;
                j--;
                break;
            }
            else if(sum<target)
                i++;
            else
                j--;
        }
        return v;
    }
    vector<vector<int>> threeSum(vector<int>& nums,int target) {
        int n=nums.size();
        vector<vector<int>> v;
        for(int i=0;i<=n-3;i++)
        {
            if(i!=0 and nums[i]==nums[i-1])
            {
                continue;
            }
            int val1=nums[i];
            int newTarget= target-nums[i];
            
            vector<vector<int>> subAns = twoSum(nums,i+1,n-1;newTarget);
            
            for(auto ele: subAns)
            {
                ele.push_back(val1);
                v.push_back(ele);
            }
        }
        return v;
    }
    
};