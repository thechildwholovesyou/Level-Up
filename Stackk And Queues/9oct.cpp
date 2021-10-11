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

// 921. Minimum Add to Make Parentheses Valid

// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(auto ele: s)
        {
            if(ele=='(')
                stk.push(ele);
            else
            {
                if(!stk.empty() and stk.top()=='(')
                    stk.pop();
                else
                    stk.push(ele);
            }
        }
        return stk.size();
    }
};

// 895. Maximum Frequency Stack
// https://leetcode.com/problems/maximum-frequency-stack/

// Push => log(n)
// Pop => log(n)

class FreqStack {
private: 
    class pair{
        public:
            int val, idx,  freq;
        pair(int val,int idx,int freq){
            this->val = val;
            this->freq=freq;
            this->idx=idx;
        }
    };
    
    struct comparator{
        bool operator()(const pair &a, const pair &b) const{
            if(a.freq!=b.freq){
                return b.freq > a.freq;
            }
            return b.idx > a.idx;
        }
    };
    
    
    unordered_map<int,int> map;
    priority_queue<pair, vector<pair>, comparator> pq;
    
    int idx=0;
    
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        map[val]++;
        pq.push(pair(val,idx++,map[val]));
    }
    
    int pop() {
        pair temp =pq.top();
        pq.pop();
        map[temp.val]--;
        if(map[temp.val]==0)
            map.erase(temp.val);
        
        return temp.val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */


// using class 

class FreqStack {
private: 
    class pair{
        public:
            int val, idx,  freq;
        pair(int val,int idx,int freq){
            this->val = val;
            this->freq=freq;
            this->idx=idx;
        }
    };
    
    class comparator{
        public:
        bool operator()(const pair &a, const pair &b) const{
            if(a.freq!=b.freq){
                return b.freq > a.freq;
            }
            return b.idx > a.idx;
        }
    };
    
    
    unordered_map<int,int> map;
    priority_queue<pair, vector<pair>, comparator> pq;
    
    int idx=0;
    
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        map[val]++;
        pq.push(pair(val,idx++,map[val]));
    }
    
    int pop() {
        pair temp =pq.top();
        pq.pop();
        map[temp.val]--;
        if(map[temp.val]==0)
            map.erase(temp.val);
        
        return temp.val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */


// 155. Min Stack
// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    vector<pair<int,int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty())
        {
            stk.push_back({val,val});
        }
        else
        {
            stk.push_back({val,min(stk.back().second, val)});
        }
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */