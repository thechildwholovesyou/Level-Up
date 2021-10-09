// 402. Remove K Digits
// https://leetcode.com/problems/remove-k-digits/
// mera wala sol 

class Solution {
public:
    string removeLeadingZeros(string str)
{
    // Regex to remove leading
    // zeros from a string
    const regex pattern("^0+(?!$)");
 
    // Replaces the matched
    // value with given string
    str = regex_replace(str, pattern, "");
    return str;
}
    string removeKdigits(string num, int k) {
        stack<char> stk;
        if(num.size()==k) return "0";
        for(auto ele: num)
        {
            while(k!=0 and !stk.empty() and (int)(stk.top())> (int)ele)
            {
                stk.pop();
                k--;
            }
            stk.push(ele);
        }
       if(k)
       {
           while(k--)
           {
               stk.pop();
           }
       }
        
        string ans="";
        while(!stk.empty())
        {
            char ele=stk.top();
            stk.pop();
            ans+=ele;
        }
        reverse(ans.begin(),ans.end());
       ans=removeLeadingZeros(ans);
        return ans;
    }
};

// sir wala method ... vector se // observe krna TC (ye wala better hai)

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for(auto ele: num)
        {
            while(k and stk.size()!=0 and (int)(stk[stk.size()-1]) > (int)ele)
            {
                k--;
                stk.pop_back();
            }
            stk.push_back(ele);
        }
        if(k)
        {
            while(k--)
            {
                stk.pop_back();
            }
        }
        
        string ans="";
        bool nonZero=false;
        for(auto ele: stk)
        {
            if(ele=='0' and !nonZero) continue;
            nonZero=true;
            ans+=ele;
        }
        
        if(ans=="")
            ans+="0";
        return ans;
    }
};
 
// 316. Remove Duplicate Letters
// https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<bool> vis(26,false);
        vector<int> freq(26,0);
        vector<char> stk;
        
        for(int i=0;i<n;i++)
        {
           freq[s[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            char ele=s[i];
            freq[ele-'a']--;
            if(vis[ele-'a'])
                continue;
            while(stk.size()!=0 and stk[stk.size()-1] > ele and freq[stk[stk.size()-1] -'a']>0)
            {
                vis[stk[stk.size()-1] -'a']=false;
                stk.pop_back();
            }
            vis[ele-'a']=true;
            stk.push_back(ele);
        }
        string ans="";
        for(auto ele:stk)
            ans+=ele;
        return ans;
    }
};

// 1081. Smallest Subsequence of Distinct Characters
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution {
public:
    string smallestSubsequence(string s) {
         int n=s.size();
        vector<bool> vis(26,false);
        vector<int> freq(26,0);
        vector<char> stk;
        
        for(int i=0;i<n;i++)
        {
           freq[s[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            char ele=s[i];
            freq[ele-'a']--;
            if(vis[ele-'a'])
                continue;
            while(stk.size()!=0 and stk[stk.size()-1] > ele and freq[stk[stk.size()-1] -'a']>0)
            {
                vis[stk[stk.size()-1] -'a']=false;
                stk.pop_back();
            }
            vis[ele-'a']=true;
            stk.push_back(ele);
        }
        string ans="";
        for(auto ele:stk)
            ans+=ele;
        return ans;
    }
};