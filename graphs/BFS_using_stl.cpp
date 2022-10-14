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
    return 0;
}
