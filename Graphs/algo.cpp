// // BFS ALGORITHM

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> bfs(int V,vector<int>adj[])
// {
//     vector<int> res;
//     vector<int> vis(V,0);
//     queue<int> q;
//     q.push(0);
//     vis[0]=1;

//     while(!q.empty())
//     {
//         int node=q.front();
//         q.pop();
//         res.push_back(node);
//         for(auto ele:adj[node])
//         {
//             if(!vis[ele])
//             {
//                 q.push(ele);
//                 vis[ele]=1;
//             }
//         }
//     }
//     return res;
// }


// int main()
// {
//     int t;
//     cin>>t;

//     while(t--)
//     {
//         int V,E;
//         cin>>V>>E;

//         vector<int> adj[V];
//         for(int i=0;i<E;i++)
//         {
//             int u,v;
//             cin>>u>>v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         vector<int> ans=bfs(V,adj);
//         for(auto ele:ans)
//             cout<<ele<<" ";
//         cout<<endl;
//     }
//     return 0;
// }

// // DFS ALGORITHM 



// void dfs_helper(int src, vector<int>&vis, vector<int> adj[], vector<int>&res)
// {
//     res.push_back(src);
//     vis[src]=1;
//     for(auto ele:adj[src])
//     {
//         if(!vis[ele])
//             dfs_helper(ele,vis,adj,res);
//     }
// }

// vector<int> dfs(int V,vector<int>adj[])
// {
//     vector<int> res;
//     vector<int> vis(V+1,0);
//     for(int i=1;i<=V;i++)
//     {
//         if(!vis[i])
//             dfs_helper(i,vis,adj,res);
//     }
//     return res;
// }


// DJISKTRA ALGORITHM

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,src;
    cin>>n>>m;
    vector<pair<int,int>> g[n+1];
    int a,b,wt;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>wt;
        g[a].push_back({b,wt});
        g[b].push_back({a,wt});
    }
    cin>>src;

    // real implementation begins here

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

    vector<int> distTo(n+1,INT_MAX);

    distTo[src]=0;
    pq.push({0,src});

    while(!pq.empty())
    {
        int dist=pq.top().first;
        int prev=pq.top().second;

        vector<pair<int,int>> :: iterator it;
        for(it=g[prev].begin();it!=g[prev].end();it++)
        {
            int next=it->first;
            int nextDist=it->second;
            if(distTo[next]>distTo[prev]+nextDist)
            {
                distTo[next]=distTo[prev]+nextDist;
                pq.push({distTo[next],next});
            }
        }
    }
    cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
}

// 