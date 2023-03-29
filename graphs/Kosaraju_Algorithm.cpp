#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N], grr[N];
vector<int> order;
int vis[N], col[N];
vector<int> components[N];

// Topological Sorting
void dfs1(int cur) 
{
    vis[cur] = 1;

    for(auto x : gr[cur])
    {
        if(!vis[x])
        {
            dfs1(x);
        }
    }
    order.push_back(cur);
}

void dfs2(int cur, int comp) 
{
    vis[cur] = 1;
    col[cur] = comp;
    components[comp].push_back(cur);

    for(auto x : grr[cur])
    {
        if(!vis[x])
        {
            dfs2(x, comp);
        }
    }
}

int main()
{
    int n, m;
    // cout << " Enter node and edges:- ";
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        grr[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());
    memset(vis, 0, sizeof(vis));
    int comp = 1;
    for(auto x : order)
    {
        // cout << x << " ";
        if(!vis[x])
        {
            dfs2(x, comp++);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << i << " " << col[i] << endl;
    }

    cout << "Total strongly connected components are " << comp - 1;
    return 0;
}
