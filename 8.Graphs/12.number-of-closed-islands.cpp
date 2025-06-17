class Solution
{
    using pi = pair<int, int>;

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
    
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        auto flood = [&](auto &&self, int i, int j)
        {
            queue<pi> bfs;
            bfs.push({i, j});
            vis[i][j] = true; // mark _as soon as_ you push
            static const vector<pi> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            while (!bfs.empty())
            {
                auto [r, c] = bfs.front();
                bfs.pop();
                for (auto [dr, dc] : dirs)
                {
                    int rr = r + dr, cc = c + dc;
                    if (rr >= 0 && rr < m && cc >= 0 && cc < n && !vis[rr][cc] && grid[rr][cc] == 0)
                    {
                        vis[rr][cc] = true;  
                        bfs.push({rr, cc});
                    }
                }
            }
        };

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0 && !vis[i][0])
                flood(flood, i, 0);
            if (grid[i][n - 1] == 0 && !vis[i][n - 1])
                flood(flood, i, n - 1);
        }

        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 0 && !vis[0][j])
                flood(flood, 0, j);
            if (grid[m - 1][j] == 0 && !vis[m - 1][j])
                flood(flood, m - 1, j);
        }

        int count = 0;
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 0 && !vis[i][j])
                {
                    flood(flood, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
