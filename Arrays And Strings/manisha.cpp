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


//
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