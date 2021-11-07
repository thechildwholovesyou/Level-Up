// 1971. Find if Path Exists in Graph
// https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:
    
    bool hasPath(int src,int dest,vector<vector<int>>&graph,vector<bool>&vis)
    {
        if(src==dest) return true;
        
        if(vis[src]==true) return false;
        
        vis[src]=true;
        
        for(int i=0;i<graph[src].size();i++)
        {
            if(hasPath(graph[src][i],dest,graph,vis)) return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> vis(n,false);
        return hasPath(start,end,graph,vis);
    }
};