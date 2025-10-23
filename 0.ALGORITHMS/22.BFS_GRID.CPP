vector<pair<int, int>> of = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vi> vis(r, vi(c, 0));
queue<pair<int, int>> q;
q.push({i, j});
vis[i][j] = 1;

while (!q.empty())
{
    auto [cr, cc] = q.front();
    q.pop();

    for (auto &p : of)
    {
        int nr = cr + p.first, nc = cc + p.second;
        if (nr >= 0 && nc >= 0 && nr < r && nc < c && !vis[nr][nc])
        {
            vis[nr][nc] = 1;
            q.push({nr, nc});
        }
    }
}
