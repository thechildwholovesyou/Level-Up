// check path

#include<bits/stdc++.h>
using namespace std;

bool checkPath(int src,int dest,vector<vector<int>>&graph,vector<bool>&vis)
{
    if(src==dest) return true;
    if(vis[src]==true) return false;
    vis[src]=true;
    for(auto ele:graph[src])
    {
        if(checkPath(ele,dest,graph,vis)) return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> graph(200);
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int a,b;
    cin>>a>>b;
    vector<bool>vis(n+1,false);
    bool ans=checkPath(a,b,graph,vis);
    cout<<ans;
}

// check cycle

#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int src,int parent,vector<vector<int>>&graph,vector<int>&vis)
{
    vis[src]=1;
    for(auto ele:graph[src])
    {
        if(!vis[ele])
        {
             if(checkCycle(ele,src,graph,vis)) return true;
        }
        else if(ele!=parent) return true;
    }
    return false;
}
bool cycle(vector<vector<int>>&graph)
{
    vector<int>vis(graph.size()+1,0);
    for(int i=1;i<=graph.size();i++)
    {
        if(!vis[i])
            if(checkCycle(i,-1,graph,vis)) return true;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> graph(200);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool ans=cycle(graph);
    cout<<ans;
}

// Bipartite Graph 
 
#include<bits/stdc++.h>
using namespace std;


bool bipartite(int src,vector<vector<int>>&graph,vector<int>&color)
{
    if(color[src]==-1) color[src]=1;
    for(auto ele:graph[src])
    {
        if(color[ele]==-1)
        {
            color[ele]=1-color[src];
            if(!bipartite(ele,graph,color)) return false;
        }
        else if(color[ele]==color[src]) return false;
    }
    return true;
}

bool checkBipartite(vector<vector<int>>&graph)
{
    int n=graph.size();
    vector<int> color(n,-1);
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!bipartite(i,graph,color)) return false;
        }
    }
    return true;
}


int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> graph(200);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool ans=checkBipartite(graph);
    cout<<ans;
}

// dijkstars algo

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,src;
    cin>>n>>m;
    vector<pair<int,int>> graph[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
    cin>>src;

    vector<int> distTo(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;

    distTo[src]=0;
    pq.push({0,src});

    while(!pq.empty())
    {
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        vector<pair<int,int>> :: iterator it;
        for(it=graph[prev].begin();it!=graph[prev].end();it++)
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

    for(int i=1;i<=n;i++)
        cout<<distTo[i]<<" ";
    return 0;
}

// 0/1 Knapsack

#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>&wt,vector<int>&val,int W,int n)
{
    if(W==0 or n==0) return 0;
    if(wt[n-1]<=W)
    {
        return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1));
    }
    else
        return knapsack(wt,val,W,n-1);
}

int main()
{
    int n;
    cin>>n;
    vector<int> wt;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        wt.push_back(data);
    }
    vector<int> val;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        val.push_back(data);
    }
    int W;
    cin>>W;

    int ans=knapsack(wt,val,W,n);
    cout<<ans<<endl;
}

// LCS
#include<bits/stdc++.h>
using namespace std;

int lcs_rec(string a, string b,int n,int m)
{
    if(n==0 or m==0)
            return 0;
        if(a[n-1]==b[m-1])
            return lcs_rec(a,b,n-1,m-1)+1;
        else
            return max(lcs_rec(a,b,n-1,m), lcs_rec(a,b,n,m-1));
}

int main()
{
    string a,b;
    cin>>a>>b;

    int ans=lcs_rec(a,b,a.size(),b.size());
    cout<<ans<<endl;
}
