#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool vis[2000][2000];
int n, m;

bool isValid(int x, int y)
{
    if (x < 0 or x >= n or y < 0 or y >= m)
        return false;
    if (vis[x][y])
        return false;
    return true;
}

void dfs(int i, int j)
{
    vis[i][j] = true;
    for (auto &it : moves)
    {
        if (isValid(i + it.first, j + it.second))
        {
            dfs(i + it.first, j + it.second);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                vis[i][j] = true;
            }
        }
    }

    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                rooms++;
                dfs(i, j);
            }
        }
    }
    cout << rooms << endl;

    return 0;
}
