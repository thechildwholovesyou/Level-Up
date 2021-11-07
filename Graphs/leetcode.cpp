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

// 797. All Paths From Source to Target
// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    
    void allPaths(vector<vector<int>>& graph,int src,int dest,vector<vector<int>>&bigAns,vector<int>&smallAns)
    {
        smallAns.push_back(src); // and here we are just assume maring the node as visisted
        
        if(src==dest)
        {
            bigAns.push_back(smallAns);
        }
        for(int i=0;i<graph[src].size();i++)
        {
            allPaths(graph,graph[src][i],dest,bigAns,smallAns);
        }
        smallAns.pop_back(); // this also acts as a visited array 
        // just assume here we are unmarking the vis node
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> bigAns;
        if(graph.size()==0) return bigAns;
        vector<int>smallAns;
        
         allPaths(graph,0,graph.size()-1,bigAns,smallAns);
        
        return bigAns;
    }
};