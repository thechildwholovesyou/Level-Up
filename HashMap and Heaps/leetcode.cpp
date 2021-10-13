// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int> m;
        for(auto ele: nums){
            m[ele]++;
        }
        
        for(auto ele: m){
            pq.push({ele.second, ele.first});
        }
        
        vector<int> v;
        while(k--){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};

// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/submissions/

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        map<char, int> m;
        for(auto ele:s){
            m[ele]++;
        }
        
        for(auto ele: m){
            pq.push({ele.second, ele.first});
        }
        string ans="";
        while(!pq.empty())
        {
            auto n=pq.top();
            while(n.first--){
                ans+=n.second;
            }
            pq.pop();
        }
        return ans;
    }
};

// 1636. Sort Array by Increasing Frequency
// https://leetcode.com/problems/sort-array-by-increasing-frequency/

struct compare{
     bool operator()(pair<int,int> p1,pair<int,int> p2){
        if (p1.first==p2.first){
            return p1.second<p2.second;
        }
        else{
            return p1.first>p2.first;
        }
    }
    };

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue <pair<int,int>, vector<pair<int,int>>, compare > pq;
        map<int, int> m;
        for(auto ele:nums){
            m[ele]++;
        }
        
        for(auto ele: m){
            pq.push({ele.second, ele.first});
        }
       vector<int> ans;
        while(!pq.empty())
        {
            auto n=pq.top();
            while(n.first--){
                ans.push_back(n.second);
            }
            pq.pop();
        }
        return ans;
    }
};

// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int, int>> m;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<s.size();i++){
            char ele=s[i];
            m[ele].first++;
            m[ele].second=i;
        }
        for(auto ele:m){
            if(ele.second.first==1)
                pq.push(ele.second.second);
        }
        
        if(pq.empty())
            return -1;
        return pq.top();
    }
};