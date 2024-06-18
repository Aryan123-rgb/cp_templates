#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
vector<int> par;
vector<int> cycle;
bool is_cycle = false;

void dfs(int node, int p)
{
    col[node] = 2;
    par[node] = p;
    for (auto v : g[node])
    {
        if (col[v] == 1)
        {
            // node - v is a forward edge
            dfs(v, node);
        }
        else if (col[v] == 2)
        {
            // node - v is a backward edge -> found a cycle
            if (is_cycle == false)
            {
                int temp = node;
                while (temp != v)
                {
                    cycle.push_back(temp);
                    temp = par[temp];
                }
                cycle.push_back(temp);
                reverse(cycle.begin(), cycle.end());
            }
            is_cycle = true;
        }
        else if (col[v] == 3)
        {
            // node -v is a cross edge
        }
    }
    col[node] = 3;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 1);
    par.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 1)
        {
            dfs(i, 0);
        }
    }
    for (auto v : cycle)
    {
        cout << v << " ";
    }
}