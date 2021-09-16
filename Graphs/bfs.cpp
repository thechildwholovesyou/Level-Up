vector<int> bfs(int v, vector<int>adj[])
{
    vector<int> ans;
    vector<int> vis(v+1, 0);

    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i]=1;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for(auto ele: adj[node])
                {
                    if(!vis[i])
                    {
                        q.push(ele);
                        vis[ele]=1;
                    }
                }
            }
        }
    }
    return ans;
}