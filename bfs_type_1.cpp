#include <bits/stdc++.h>
using namespace std;
using state = pair<int, int>;

int n, m;
vector<vector<char>> arr;
vector<vector<int>> dis;
vector<vector<state>> par;
vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool is_vaild(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#')
        return true;
    else
        return false;
}

void bfs(state st_node)
{
    dis.assign(n, vector<int>(m, 1e9));
    par.assign(n, vector<state>(m, {-1, -1}));

    queue<state> q;
    dis[st_node.first][st_node.second] = 0;
    par[st_node.first][st_node.second] = {-1, -1};
    q.push(st_node);
    while (!q.empty())
    {
        state node = q.front();
        q.pop();
        for (auto i : moves)
        {
            int x = node.first + i.first;
            int y = node.second + i.second;
            if (is_vaild(x, y))
            {
                if (dis[x][y] == 1e9)
                {
                    par[x][y] = node;
                    dis[x][y] = dis[node.first][node.second] + 1;
                    q.push({x, y});
                }
            }
        }
    }
}
/*
S -> Starting Point, F -> final point, # -> walls , . -> path
6 6
S . # . . .
. . # . . .
# . # . # .
. . . . # .
# # # # . .
F . . . . .
*/

signed main()
{
    cin >> n >> m;
    arr.resize(n);
    state st, en;
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                st = {i, j};
            }
            else if (arr[i][j] == 'F')
            {
                en = {i, j};
            }
        }
    }

    bfs(st);

    cout << dis[en.first][en.second] << endl;
    state curr = en;
    vector<state> path;
    while (curr != make_pair(-1, -1))
    {
        path.push_back(curr);
        curr = par[curr.first][curr.second];
    }
    reverse(path.begin(), path.end());
    for (auto v : path)
    {
        cout << v.first << "," << v.second;

        cout << endl;
    }

    return 0;
}