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

// 1319. Number of Operations to Make Network Connected
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
     void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
    {
        visited[src] = true;
        for(int i : adj[src])
            if(!visited[i])
                dfs(adj, visited, i);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                dfs(adj, visited, i);
                components++;
            }
        return components - 1;
    }
};

// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    
    void dfs(int sr,int sc,vector<vector<char>>& grid,vector<vector<int>>& dir)
    {
        grid[sr][sc]='0';
        for(auto ele:dir)
        {
            int r=sr+ele[0];
            int c=sc+ele[1];
            
            if(r>=0 and c>=0 and r<grid.size() and c<grid[0].size() and grid[r][c]=='1')
                dfs(r,c,grid,dir);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid,dir);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    
    int dfs(int sr,int sc,vector<vector<int>>& grid,vector<vector<int>>& dir)
    {
        grid[sr][sc]=0;
        int cnt=0;
        for(auto ele:dir)
        {
            int r=sr+ele[0];
            int c=sc+ele[1];
            
            if(r>=0 and c>=0 and r<grid.size() and c<grid[0].size() and grid[r][c]==1)
                cnt+=dfs(r,c,grid,dir);
        }
        return cnt+1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dir={{1,0},{-1,0},{0,-1},{0,1}};
        
        int maxi=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int temp=dfs(i,j,grid,dir);
                    maxi=max(maxi,temp);
                }
            }
        }
        return maxi;
    }
};