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