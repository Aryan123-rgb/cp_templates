#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node)
{
    vis[node] = 1;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

void bfs(int st_node)
{
    queue<int> q;
    vis[st_node] = 1;
    q.push(st_node);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto v : g[node])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    g.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int num_comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            num_comp++;
            bfs(i);
        }
    }
    cout << num_comp - 1 << endl;
}
