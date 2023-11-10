#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    vector<list<int>> adj;

    public:
        Graph(int v);
        void addEdge(int v,int w);
        void BFS(int s);
        vector<int>bfsOfGraph(int v,vector<int>adj[])
};

Graph::Graph(int v)
{
    this->v=v;
    adj.resize(v);
}
void Graph::BFS(int s) //for connected graph
{
    vector<bool> visited;
    visited.resize(v,false);
    list<int>queue;

    visited[s]=true;
    queue.push_back(s);

    while(!queue.empty())
    {
        s=queue.front();
        cout<< s <<" ";
        queue.pop_front();
        for(auto x:adj[s])
            if(!visited[x])
            {
                visited[x]=true;
                queue.push_back(x);
            }
    }
}

vector<int> Graph::bfsOfGraph(int v,vector<int>adj[])//for disconnected graphs
{
    vector<int>bfs_traversal;
    vector<bool>vis(V,false);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            queue<int>q;
            vis[i]=true
            q.push(i);
            while(!q.empty())
            {
                int g_node=q.front();
                q.pop();
                bfs_traversal.push_back(g_node);
                for(auto x:adj[g_node])
                {
                    if(!vis[x])
                    {
                        vis[x]=true;
                        q.push(x);
                    }
                }
            }
        }
    }
    return bfs_traversal;
}

