#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &G, int start, int n)
{
    int i = start; 
    int j;
    vector<int> visited(7, 0);
    queue<int> q;
    cout << i << " ";
    visited[i] = 1;
    q.push(i);
    while(!q.empty())
    {
        i = q.front();
        q.pop();
        for (int j = 0; j < n; ++j)
        {
            if(G[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

int dfs(vector<vector<int>> G, int start, int n)
{
    vector<int> visited(n, 0);
    if (visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;
        for (int i = 0; i < n; ++i)
        {
            if(G[start][i] == 1 && visited[i] == 0)
            {
                dfs(G, i, n);
            }
        }
    }
}

int main()
{
    vector<vector<int>> G = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    bfs(G, 1, 7);
    dfs(G, 1, 7);
    return 0;
}
