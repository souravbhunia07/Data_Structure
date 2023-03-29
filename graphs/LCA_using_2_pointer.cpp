#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> gr[N];
int dep[N], Par[N]; // Depth, Parent

void dfs(int cur, int par)
{
    Par[cur] = par;
    dep[cur] = dep[par] + 1;
    for(auto x : gr[cur])
    {
        if(x != par)
        {
            dfs(x, cur);
        }
    }
}

int LCA(int u, int v)
{
    if(u == v)
    {
        return u;
    }

    // depth of v is more than depth of u
    if(dep[u] < dep[v])
    {
        swap(u, v);
    }

    int diff = dep[u] - dep[v];

    // Depth of both node same
    while(diff--)
    {
        u = Par[u];
    }

    // Until they are equal, nodes keep climbing
    while(u != v)
    {
        u = Par[u];
        v = Par[v];
    }
    return u;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    dfs(1, 0);

    // Depth
    for(int i = 1; i <= n; i++)
    {
        cout << i << " " << dep[i] << endl;
    }

    cout << LCA(9, 12) << '\n';
    cout << LCA(10, 8) << '\n';
    cout << LCA(9, 11) << '\n';
    return 0;
}

// 12
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 4 10
// 5 8
// 8 9
// 8 11
// 3 7
// 7 12