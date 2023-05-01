#include <bits/stdc++.h>
using namespace std;

class Graph {
    // Adjacency List
    vector<pair<int, int>> *l;
    int v;

public:
    Graph(int n)
    {
        v = n;
        l = new vector<pair<int, int>>[n];
    }

    void addEdge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst()
    {
        // Most Important
        //Min. Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        // Visited array that denotes whether a node has been included in MST or not
        bool *vis = new bool[v]{0};
        int ans = 0;

        Q.push({0, 0});

        while(!Q.empty())
        {
            // Pick out the edge with min weight
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if(vis[to])
            {
                // Discard the edge and continue
                continue;
            }


            // Otherwise take the current edge
            ans += weight;
            vis[to] = 1;

            //Add the new edge in the queue
            for(auto x : l[to])
            {
                if(vis[x.first] == 0)
                {
                    Q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};

int main()
{
    int m, n;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x - 1, y - 1, w);
    }
    cout << g.prim_mst() << endl;
    return 0;
}
