#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<int>> g;
vector<int> vis;

bool is_bipartite = false;

void dfs(int node, int color)
{
    vis[node] = color;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v, 3 - color);
        }
        else if (vis[v] == vis[color])
        {
            is_bipartite = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, 1);
        }
    }
}