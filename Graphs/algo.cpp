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

// topological sort 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node)
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
};



int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// prims

#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}

// kruskal

#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N,m;
	cin >> N >> m;
	vector<node> edges; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    edges.push_back(node(u, v, wt)); 
	}
	sort(edges.begin(), edges.end(), comp); 
	
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 
	vector<int> rank(N, 0); 
	
	int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}

// belman ford 
#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }

    int src;
    cin >> src; 


    int inf = 10000000; 
    vector<int> dist(N, inf); 

    dist[src] = 0; 

    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle"; 
            fl = 1; 
            break; 
        }
    }

    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }


    return 0;
}

/* 
6 7 
3 2 6 
5 3 1 
0 1 5 
1 5 -3 
1 2 -2 
3 4 -2 
2 4 3 
0
*/
