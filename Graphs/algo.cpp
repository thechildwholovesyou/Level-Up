// Prim's Algorithm

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>graph(n);
    int u,v,wt;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }

    vector<int>parent(n,-1);
    vector<int>key(n,INT_MAX);
    vector<bool>mst(n,false);

    key[0]=0;
    parent[0]=-1;

    for(int i=0;i<n-1;i++)
    {
        int mini=INT_MAX;
        int u
    }
}