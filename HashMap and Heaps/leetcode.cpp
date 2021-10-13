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