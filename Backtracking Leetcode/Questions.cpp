// 39. Combination Sum
//https://leetcode.com/problems/combination-sum/

class Solution {
public:
    
    int combinationSumHelper(vector<int>&candidates, vector<int>&smallAns, vector<vector<int>>&bigAns, int target, int idx)
    {
        if(target==0)
        {
            bigAns.push_back(smallAns);
            return 1;
        }
        int count =0;
        for(int i=idx;i<candidates.size();i++)
        {
            if(target-candidates[i]>=0)
            {
                smallAns.push_back(candidates[i]);
                count+=combinationSumHelper(candidates, smallAns, bigAns, target-candidates[i], i);
                smallAns.pop_back();
            }
        }
        return count;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0)
        {
            vector<vector<int>> base;
            return base;
        }
        vector<int>smallAns;
        vector<vector<int>> bigAns;
        
        int ans = combinationSumHelper(candidates, smallAns, bigAns, target,0);
        return bigAns;
    }
};

// 40. Combination Sum II
//https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    
    
    int combinationSum2Helper(vector<int>&candidates, int target, vector<int>&smallAns, vector<vector<int>>&bigAns, int idx)
    {
        if(target==0)
        {
            bigAns.push_back(smallAns);
            return 1;
        }
        int count=0;
        
        int prev=-1;
        for(int i=idx;i<candidates.size();i++)
        {
            if(prev!=candidates[i] and target -candidates[i]>=0)
            {
                smallAns.push_back(candidates[i]);
                count+=combinationSum2Helper(candidates, target-candidates[i], smallAns, bigAns,i+1);
                smallAns.pop_back();
                prev=candidates[i];
            }
        }
        return count;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size()==0)
        {
            vector<vector<int>> base;
            return base;
        }
        vector<int> smallAns;
        vector<vector<int>> bigAns;
        sort(candidates.begin(),candidates.end());
        int ans = combinationSum2Helper(candidates, target, smallAns, bigAns, 0);
        return bigAns;
    }
};

// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    
    int combinationSum3Helper(int k,int n,int idx,vector<int>&smallAns,vector<vector<int>>&bigAns)
    {
        if(n==0 and k==0)
        {
            bigAns.push_back(smallAns);
            return 1;
        }
        int count=0;
        
        int prev=-1;
        
        for(int i=idx;i<=n;i++)
        {
            if(prev!=i and n-i>=0)
            {
                smallAns.push_back(i);
                count+=combinationSum3Helper(k-1,n-i,i+1,smallAns,bigAns);
                smallAns.pop_back();
                prev=i;
            }
        }
        return count;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k==0)
        {
            vector<vector<int>> base;
            return base;
        }
        vector<int>smallAns;
        vector<vector<int>>bigAns;
        
        int ans=combinationSum3Helper(k,n,1,smallAns,bigAns);
        
        return bigAns;
    }
};

// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    string nokiaKeys[10] = { "","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    
    vector<string> letterCombinationsHelper(string s)
    {
        if(s.size()==0)
        {
            vector<string> base;
            base.push_back("");
            return base;
        }
        char ch =s[0];
        string code=nokiaKeys[ch-'0'];
        
        vector<string> recAns = letterCombinationsHelper(s.substr(1));
        vector<string> myAns;
        
        for(int i=0;i<code.size();i++)
        {
            for(auto ele: recAns)
            {
                myAns.push_back(code[i]+ele);
            }
        }
        return myAns;
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        {
            vector<string> base;
            return base;
        }
        
        vector<string> ans= letterCombinationsHelper(digits);
        return ans;
    }
};

