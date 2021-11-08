// construction of graph through adjacency list 

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

void display(vector<vector<Edge>>graph){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" = ";
        for(auto x : graph[i]){
            cout<<x.src<<" - "<<x.nbr<<" @ "<<x.cost<<" ,  ";
        }
        cout<<" ";
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
    display(graph);
   
}

