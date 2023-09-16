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


// helper method to get toposort, note that I have reversed it later in the main caller method
void toposort_dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<int>&ans, int node){
    vis[node] = true;
    for(auto x: graph[node]){
        if(!vis[x]){
            vis[x] = true;
            toposort_dfs(graph, vis, ans, x);
        }
    }
    ans.push_back(node);
    return;
}
vector<int> toposort(vector<vector<int>> &graph, int n){
    vector<bool> vis(n, false);
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            toposort_dfs(graph, vis, ans, i);
        }
    }

    return ans;
}
// this is dfs to finally get the SCCs
void dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<int>&ans, int node){
    vis[node] = true;
    ans.push_back(node);
    for(auto x: graph[node]){
        if(!vis[x]){
            vis[x] = true;
            dfs(graph, vis, ans, x);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
  
//initial graph
// initially we were only given list of edges, which denotes the direction of edge
// [u,v] -> there is an edge from node u to v
    vector<vector<int>> graph(n, vector<int>{}), graph2(n, vector<int>{});
    for(auto a : edges){
        int u = a[0];
		int v= a[1];
        graph[u].push_back(v);
        
    }
    
// transposed the original graph
    vector<int> topo =  toposort(graph, n);
         for(auto a : edges){
        int u = a[0];
		int v= a[1];
        graph2[v].push_back(u);
        
    }
    
    reverse(topo.begin(), topo.end());
    vector<bool> vis(n, false);
    vector<vector<int>> fans;
    vector<int>ans;
 	for(int i = 0;i<n;i++){
        if(!vis[topo[i]]){
            dfs(graph2, vis, ans, topo[i]);
            fans.push_back(ans);
            ans.clear();
        }
    }

    return fans;
    
    
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
