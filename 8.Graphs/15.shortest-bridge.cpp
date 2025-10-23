class Solution
{
public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();

        int i = 0, j = 0;
        bool found = false;
        for (; i < n && !found; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    found = true;
                    break;
                }
            }
        }
        i--; // adjust because outer loop increments one extra time

        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, -1, 0, 1};

        // DFS to mark first island and enqueue border water cells
        auto dfs = [&](auto &&dfs, int r, int c) -> void
        {
            visited[r][c] = true;
            grid[r][c] = 2; // mark as part of first island
            for (int k = 0; k < 4; k++)
            {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc])
                {
                    if (grid[nr][nc] == 1)
                    {
                        dfs(dfs, nr, nc);
                    }
                    else
                    {
                        visited[nr][nc] = true;
                        q.push({nr, nc, 1}); // enqueue water cell with cost 1
                    }
                }
            }
        };

        // BFS to expand to second island
        auto bfs = [&]() -> int
        {
            while (!q.empty())
            {
                auto [r, c, cost] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc])
                    {
                        if (grid[nr][nc] == 1)
                            return cost;
                        visited[nr][nc] = true;
                        q.push({nr, nc, cost + 1});
                    }
                }
            }
            return -1;
        };

        dfs(dfs, i, j);
        return bfs();
    }
};
