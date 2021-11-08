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

// 1020. Number of Enclaves
// https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    
    void dfs(int sr,int sc,vector<vector<int>>& grid,vector<vector<int>>& dir)
    {
        grid[sr][sc]=0;
        for(auto ele:dir)
        {
            int r=sr+ele[0];
            int c=sc+ele[1];
            
            if(r>=0 and c>=0 and r<grid.size() and c<grid[0].size() and grid[r][c]==1)
                dfs(r,c,grid,dir);
        }
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 or j==0 or i==m-1 or j==n-1)
                {
                    if(grid[i][j]==1)
                        dfs(i,j,grid,dir);
                }
            }
        }
        
        // now count all 1's
        int cnt=0;
        for(auto ele:grid)
        {
            for(auto i:ele)
            {
                if(i==1)
                    cnt++;
            }
        }
        return cnt;
    }
};

// 841. Keys and Rooms
// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    
    void dfs(vector<vector<int>>&graph, int src,vector<bool>&vis)
    {
        vis[src]=true;
        for(int i=0;i<graph[src].size();i++)
        {
            if(vis[graph[src][i]]==0)
            {
                dfs(graph,graph[src][i],vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        dfs(rooms, 0,vis);
        
         for(int i = 0; i < rooms.size(); i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};

// GET CONNECTED COMPONENTS 
// https://classroom.pepcoding.com/myClassroom/the-placement-program-pitampura-mar-14-2021/graph/gcc-official/ojquestion

#include<bits/stdc++.h>
using namespace std;

class Edge{
    public :
    int src;
    int nbr;
    int cost;
    Edge(){}
    Edge(int u, int v, int c){
        src = u;
        nbr = v;
        cost= c;
    }

};

void add(vector<vector<Edge>>&graph , int u, int v, int c){
    Edge *e = new Edge(u,v,c);
    graph[u].push_back(*e);
}

// void display(vector<vector<Edge>>graph){
//     for(int i=0;i<graph.size();i++){
//         cout<<i<<" = ";
//         for(auto x : graph[i]){
//             cout<<x.src<<" - "<<x.nbr<<" @ "<<x.cost<<" ,  ";
//         }
//         cout<<" ";
//     }
// }

void check(vector<vector<Edge>>&graph, int src ,vector<int>&temp ,vector<bool>&pos){
    
    if(pos[src]==true) return ;
    
   
    temp.push_back(src);
    
    pos[src] = true;
    for(auto x : graph[src]){
        int nb = x.nbr;
        check(graph , nb, temp, pos);
    }
    
}



int main(){
    int vertex , edge;
    cin>>vertex>>edge;
    vector<vector<Edge>>graph ; 
    vector<Edge>t;
    for(int i=0;i<vertex;i++){
       graph.push_back(t);
    }
    for(int i = 0;i<edge;i++){
        int u , v, c;
        cin>>u>>v>>c;
       add(graph , u, v, c);
       add(graph , v, u, c);
    }
    vector<bool>pos(vertex , false);
    vector<vector<int>>vx;
    for(int i=0;i<vertex;i++){
        vector<int>temp;
        check(graph, i , temp , pos);
        if(temp.size()>0){
            vx.push_back(temp);
        }
    }
    cout<<"[";
    for(int i=0;i<vx.size();i++){
       vector<int>as = vx[i];
       cout<<"[";
       for(int i=0;i<as.size();i++){
           if(i==as.size()-1){
               cout<<as[i];
           }else{
               cout<<as[i]<<", ";
           }
       }
       cout<<"]";
       if(i==vx.size()-1){
           
       }else{
           cout<<", ";
       }
    }
    cout<<"]";
}