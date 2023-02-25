#include <bits/stdc++.h>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int v)
    {
        V = v;
        l = new list <int> [V];
    }
    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if(undir)
        {
            l[j].push_back(i);
        }
    }
    void printAdjList()
    {
        // Iterate over all rows
        for(int i = 0; i < V; i++)
        {
            cout << i << "-->";
            // Every element of ith linked list
            for(auto node:l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }

    // BFS Traversal
    void bfs(int source)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};

        q.push(source);
        visited[source] = true;

        while(!q.empty())
        {
            auto f = q.front();
            cout << f << endl;
            q.pop();

            for(auto nbr : l[f])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    // DFS Traversal
    void dfsHelper(int node, bool *visited)
    {
        visited[node] = true;
        cout << node << ", ";
        for(auto nbr : l[node])
        {
            if(!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
        return;
    }

    void dfs(int source)
    {
        bool *visited = new bool[V]{0};
        dfsHelper(source, visited);
    }

    // Shortest Path
    void bfs_SP(int source, int dest = -1)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *dist = new int[V]{0};
        int *parent = new int[V];

        for (int i = 0; i < V; ++i)
        {
            parent[i] = -1;
        }

        q.push(source);
        visited[source] = true;
        parent[source] = source;
        dist[source] = 0;

        while(!q.empty())
        {
            auto f = q.front();
            // cout << f << endl;
            q.pop();

            for(auto nbr : l[f])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    parent[nbr] = f;
                    dist[nbr] = dist[f] + 1;
                    visited[nbr] = true;
                }
            }
        }

        // Print the shortest distance
        for (int i = 0; i < V; ++i)
        {
            cout << "Shortest distance to " << i << " is " << dist[i] << endl;
        }

        // Print the path from a source to any destination
        if(dest != -1)
        {
            int temp = dest;
            while(temp != source)
            {
                cout << temp << "--";
                temp = parent[temp];
            }
            cout << source << endl;
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.printAdjList();
    cout << "BFS Traversal of the given graph:-" << endl;
    // g.bfs(0);
    // g.dfs(0);
    g.bfs_SP(1, 6);
    return 0;
}
