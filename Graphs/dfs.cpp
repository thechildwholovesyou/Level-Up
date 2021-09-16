void dfs_helper(int node, vector<int>&vis, vector<int> adj[], vector<int>&storeDfs)
{
    storeDfs.push_back(node);
    vis[node]=1;
    for(auto ele: adj[node])
    {
        if(!vis[ele])
            dfs(ele, vis, adj,storeDfs);
    }
}

vector<int> dfs(int v,vector<int> int adj[])
{
    vector<iint> storeDfs;
    vector<int> vis(v+1, 0);
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
            dfs_helper(i,vis, adj, storeDfs);
    }
    return storeDfs;
}