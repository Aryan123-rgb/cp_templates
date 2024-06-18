#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> g;
vector<vector<int>> vis;
int n, m;

bool isValid(int x, int y)
{
    if (x < 0 or x >= n or y < 0 or y >= m)
        return false;
    if (vis[x][y])
        return false;
    return true;
}

void dfs(int i, int j, int comp_no)
{
    vis[i][j] = comp_no;
    for (auto &it : moves)
    {
        if (isValid(i + it.first, j + it.second))
        {
            dfs(i + it.first, j + it.second, comp_no);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        g.assign(n, vector<int>(m, 0));
        vis.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> g[i][j];
                vis[i][j] = g[i][j];
            }
        }

        int num_comp = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                {
                    num_comp++;
                    dfs(i, j, num_comp);
                }
            }
        }

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] != 1)
                {
                    mp[vis[i][j]]++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] != 1)
                {
                    if (mp[vis[i][j]] != 1)
                        cout << mp[vis[i][j]] << " ";
                    else
                        cout << 0 << " ";
                }
                else
                    cout << 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
