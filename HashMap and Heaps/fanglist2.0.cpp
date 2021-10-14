// 18. 4Sum
// https://leetcode.com/problems/4sum/

// using sets 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n=nums.size();
        
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int sum=target-(nums[i]+nums[j]);
                int left =j+1;
                int right=n-1;
                
                while(left<right)
                {
                    int tempAns=nums[left]+nums[right];
                    if(tempAns < sum) left++;
                    else if(tempAns> sum) right--;
                    else
                    {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[left]);
                        t.push_back(nums[right]);
                        s.insert(t);
                        left++;
                        right--;
                    }
                }
            }
        }
        for(auto ele: s)
            ans.push_back(ele);
        
        return ans;
    }
};

// using heaps 

