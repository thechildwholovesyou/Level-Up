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
        cout<<"";
    }
}
int small=INT_MAX;
string smallPath="";
int large=INT_MIN;
string largePath="";

vector<pair<int,string>> m;
void check(vector<vector<Edge>>&graph,int src,int des,vector<bool>&vis,string asf,int sum)
{
    if(src==des)
    {
        asf+=to_string(src);
        if(sum<small){
            small=sum;
            smallPath=asf;
        }
        else if(sum>large){
            large=sum;
            largePath=asf;
        }
         m.push_back({sum,asf});
    }
    vis[src]=true;
    vector<Edge>v=graph[src];
    for(Edge e:v){
        int nb=e.nbr;
        if(vis[nb]==false)
        {
            check(graph,nb,des,vis,asf+to_string(src),sum+e.cost);
        }
    }  
    vis[src]=false; 
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
    int s,d;
    cin>>s>>d;
    vector<bool>pos(vertex , false);
    check(graph, s ,d, pos, "");
    
}