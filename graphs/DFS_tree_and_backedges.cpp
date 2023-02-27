// DFS Tree and backedges:-

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N];
int vis[N];
bool cycle = false;

void dfs(int cur, int par)
{
    cout << cur << endl;
    vis[cur] = 1;
    for(auto x : gr[cur])
    {
        if(!vis[x])
        {
            dfs(x, cur);
        }
        else if(x != par)
        {
            // Backedge 
            cycle = true;
            cout << cur << " " << x << endl;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            dfs(i, 0);
        }
    }

    if(cycle)
    {
        cout << "Cycle Detected";
    }
    else
    {
        cout << "Cycle Not Detected";
    }
    return 0;
}



// Inputs :-
// 7 8
// 1 2
// 1 3
// 2 3
// 2 4
// 4 5
// 5 6
// 6 7
// 7 4
