#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int >ad[],int V)
{
    for(int v=0;v<V;v++)
    {
        cout<<"\nAdjacency list of vertex "<<v<<\n head;
        for(auto x:adj[v])
            cout<<"-> "<<x;
        cout<<endl;
    }
}
void transpose(vector<int> adj[],vector<int>transpose[],int v)
{
    for(int i=0;i<v;i++)
        for(int j=0;j<adj[i].size();j++)
            addEdge(transpose,adj[i][j],i);
}
int main()
{
    int V=5;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);

}