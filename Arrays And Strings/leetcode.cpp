
// 925. Long Pressed Name
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.size()>typed.size()) return false;
        int i=0;
        int j=0;
        
        while(i<name.size() and j<typed.size())
        {
            if(name[i]==typed[j])
            {
                i++;
                j++;
            }
            else if(i>0 and name[i-1]==typed[j])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        
        while(j<typed.size())
        {
            if(name[i-1]!=typed[j]) return false;
            j++;
        }
        return i<name.size()? false:  true;
    }
};

// 169. Majority Element

// Brute force using MAP => O(N) O(N);

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        
        int n= nums.size();
        
        for(auto ele: nums)
            m[ele]++;
        
        int ans =-1;
        
        for(auto ele: m)
        {
            if(ele.second > n/2)
                ans=ele.first;
        }
        
        return ans;
    }
};

// Using Moore's Voting Algorithm 

class Solution {
public:
    
    int moore_algorithm(vector<int>& nums)
    {
        int majIdx= 0 ;
        int count =1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[majIdx]==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count==0)
            {
                majIdx=i;
                count=1;
            }
        }
        return nums[majIdx];
    }
    
    bool isMajority(vector<int>& nums, int x)
    {
        int n =nums.size();
        int count=0;
        for(auto ele: nums)
        {
            if(ele==x)
                count++;
        }
        if(count>n/2)
            return true;
        return false;
    }
    
    int majorityElement(vector<int>& nums) {
        int ans = moore_algorithm(nums);
        if(isMajority(nums, ans))
            return ans;
        return -1;
    }
};


// 229. Majority Element II

// Brute Force 


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto ele: nums)
            m[ele]++;
        
        int n=nums.size();
        vector<int> v;
        for(auto ele: m)
        {
            if(ele.second > n/3)
            {
                v.push_back(ele.first);
            }
        }
        return v;
    }
};

