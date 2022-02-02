// https://leetcode.com/problems/long-pressed-name/
class Solution {
public:
    bool isLongPressedName(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();
        if(n2<n1) return false;
        int i=0;
        int j=0;
        
        while(i<n1 and j<n2)
        {
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else if(j>0 and s2[j]==s2[j-1])
            {
                j++;
            }
            else{
                return false;
            }
        }
        while(j<n2)
        {
            if(s2[j]!=s1[i-1]) return false;
            j++;
        }

        return i<s1.size()?false: true;
        
    }
};


// https://www.lintcode.com/problem/903/
// https://leetcode.com/discuss/interview-question/1733247/903-Range-Addition (by ME)
// brute force approach => TLE 

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        // brute force approach 
        vector<int> res(length,0);
        for(auto ele: updates)
        {
            int s=ele[0];
            int e=ele[1];
            int inc=ele[2];

            for(int i=s;i<=e;i++)
            {
                res[i]+=inc;
            }
        }
        return res;
    }
};

// optimised using Prefix Sum => O(K+N)

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> res(length, 0);
        for(auto ele: updates)
        {
            int s=ele[0];
            int e=ele[1];
            int inc=ele[2];

            res[s]+=inc;
            if(e+1<res.size()) res[e+1]-=inc;
        }
        for(int i=1;i<res.size();i++)
        {
            res[i]+=res[i-1];
        }
        return res;
    }
};

// https://leetcode.com/problems/magic-squares-in-grid/
// 5 wala jo logic h ,, usse nhi kia h 
// O(m*n) 

class Solution {
public:
    
    bool check(vector<vector<int>>&grid, int i,int j)
    {
        if(i + 2 < grid.size() && j+2 < grid[i].size()){
            int col1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
            int col2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
            int col3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
            int row1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            int row2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
            int row3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
            int diag1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
            int diag2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
            if(
                (col1 == col2) &&
                (col1 == col3) &&
                (col1 == row1) && 
                (col1 == row2) &&
                (col1 == row3) &&
                (col1 == diag1) &&
                (col1 == diag2)) {
                    set<int> s({1,2,3,4,5,6,7,8,9});
                    for(int r = 0 ; r < 3 ; r++){
                        for(int c = 0; c < 3 ; c++){
                            s.erase(grid[i + r][j + c]);
                        }
                    }
                    return s.empty();
            }
        }
        return false;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(check(grid, i,j)) cnt++;
            }
        }
        return cnt;
        
    }
};


// https://leetcode.com/problems/container-with-most-water/
// Brute force O(n*n)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        for(int i=0;i<height.size()-1;i++)
        {
            for(int j=i+1;j<height.size();j++)
            {
                int tempWater= min(height[i],height[j])*(j-i);
                maxi = max(maxi, tempWater);
            }
        }
        return maxi;
    }
};

// optimised -> 2 pointers -> O(n)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int i=0;
        int j=height.size()-1;
        
        while(i<=j)
        {
            int tempWater=min(height[i], height[j])*(j-i);
            maxi=max(maxi, tempWater);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxi;
    }
};

// https://leetcode.com/problems/squares-of-a-sorted-array/
// O(n) solution using 2 pointers 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        
        vector<int> res(n, 0);
        int k=n-1;
        while(i<=j)
        {
            if((nums[i]*nums[i]) <=(nums[j]*nums[j]))
            {
                res[k]=nums[j]*nums[j];
                j--;
            }
            else
            {
                res[k]=nums[i]*nums[i];
                i++;
            }
            k--;
        }
        return res;
    }
};

//238. Product of Array Except Self 
// https://leetcode.com/problems/product-of-array-except-self/
// brute force approach 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n, 1);
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<n;j++)
           {
               if(i==j) continue;
               res[j]*=nums[i];
           }
        }
        return res;
    }
};


// optimised approach => with division operator => runtime error 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        for(auto ele: nums)
            product*=ele;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            nums[i]=product/nums[i];
        }
        return nums;
    }
};

// optimised O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,1),right(n,1);
        left[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            left[i]=nums[i]*left[i-1];
        }
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=nums[i]*right[i+1];
        }
        
        // fill array 
        vector<int> res(n,1);
        for(int i=0;i<n;i++)
        {
            // pes => product aray itself 
            int pes = (i==0?1: left[i-1]) *(i==n-1?1: right[i+1]);
            res[i]=pes;
        }
        return res;
    }
    
};


// 169. Majority Element
// https://leetcode.com/problems/majority-element/
// moore's voting algorithm  O(N) O(1)

class Solution {
public:
    bool check(vector<int>&nums, int x,int n)
    {
        int cnt=0;
        for(auto ele:nums)
            if(ele==x) cnt++;
        return (cnt>n/2);
    }
    int get_ans(vector<int>&nums,int n)
    {
        int val=nums[0];
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==val)
                cnt++;
            else 
                cnt--;
            if(cnt==0)
            {
                val=nums[i];
                cnt=1;
            }
        }
        // potential majority element => val;
        // now check if it is actually a majority element or not 
        if(check(nums, val, n)) return val;
        return -1;
    }
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans = get_ans(nums, n);
        return ans;
    }
};

// 229. Majority Element II
// https://leetcode.com/problems/majority-element-ii/
// moore's voting algo O(n) O(1)

class Solution {
public:
    bool check(vector<int>&nums, int x, int n)
    {
        int cnt=0;
        for(auto ele: nums)
            if(ele==x) cnt++;
        return (cnt>floor(n/3));
    }
    vector<int> get_ans(vector<int>&nums,int n)
    {
        int val1=nums[0], cnt1=1;
        int val2=INT_MIN, cnt2=0;
        vector<int> res;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==val1) cnt1++;
            else if(nums[i]==val2) cnt2++;
            else
            {
                if(cnt1==0){
                    val1=nums[i];
                    cnt1=1;
                }
                else if(cnt2==0){
                    val2=nums[i];
                    cnt2=1;
                }
                else
                {
                    cnt1--;
                    cnt2--;
                }
            }
        }
         // val1 and val2 arre potential numbers 
        // let's verify
        if(check(nums, val1, n)) res.push_back(val1);
        if(check(nums, val2, n)) res.push_back(val2);
        return res;
    }
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return {nums[0]};
        vector<int> ans = get_ans(nums, n);
        return ans;
    }
};

// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/
// two pointers O(N)
class Solution {
public:
    bool check(char ch)
    {
        return (ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U');
    }
    string reverseVowels(string s) {
        //transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
            if(!check(s[i]) and !(check(s[j]))){
                i++;
                j--;
            }
            else if(!check(s[i])) i++;
            else if(!check(s[j])) j--;
            else
            {
               swap(s[i], s[j]);
                i++;
                j--; 
            }
            
        }
        return s;
    }
};

// 537. Complex Number Multiplication
// https://leetcode.com/problems/complex-number-multiplication/

class Solution {
public:
    pair<int,int> helper(string s)
    {
        int i=s.find('+');
        double real = stoi(s.substr(0,i));
        double imaginary = stoi(s.substr(i+1, s.size()-i-2));
        
        pair<int,int> res(real, imaginary);
        return res;
    }
    string complexNumberMultiply(string num1, string num2) {
        pair<int,int> p1= helper(num1), p2= helper(num2);
        
         // c1* c2= (ac-bd) + i(ad+bc);
        int a=p1.first, c=p2.first;
        int b=p1.second, d=p2.second;
        
        return to_string(a*c-b*d)+'+'+to_string(a*d+b*c)+'i';
    }
};

// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/
// O(N) O(1)

class Solution {
public:
    int seggregate(vector<int>&nums)
    {
        int i=0;
        int j=0;
        
        while(j<nums.size())
        {
            if(nums[j]<=0) j++;
            else
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        return i-1;
    }
    int firstMissingPositive(vector<int>& nums) {
        int pi=seggregate(nums); // pi=> positive index
        
        for(int i=0;i<=pi;i++)
        {
            int idx=abs(nums[i])-1;
            if(idx<=pi and nums[idx]>0)
                nums[idx]=-nums[idx];
        }
        
        for(int i=0;i<=pi;i++)
        {
            if(nums[i]>0)
                return i+1;
        }
        return pi+2;
    }
};

// 628. Maximum Product of Three Numbers
// https://leetcode.com/problems/maximum-product-of-three-numbers/
// nlogn 

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // nlogn 
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        int res1=1;
        int maxi=1;
        for(int i=0;i<=2;i++)
            res1*=nums[i];
        int res2=nums[n-1]*nums[n-2]*nums[0];
        
        return max(res1, res2);
    }
};

// O(N) O(1)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // simply find out te largest 3 elements and 2 smallest elements
        int max1=INT_MIN;
        int max2=INT_MIN;
        int max3=INT_MIN;
        int min1=INT_MAX;
        int min2=INT_MAX;
        
        for(auto ele: nums)
        {
            if(ele>max1)
            {
                max3=max2;
                max2=max1;
                max1=ele;
            }
            else if(ele>max2)
            {
                max3=max2;
                max2=ele;
            }
            else if(ele>max3)
            {
                max3=ele;
            }
            if(ele<min1)
            {
                min2=min1;
                min1=ele;
            }
            else if(ele<min2)
            {
                min2=ele;
            }
        }
        return max(max1*max2*max3, max1*min1*min2);
    }
};
