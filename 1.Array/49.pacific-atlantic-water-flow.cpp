
struct PairHash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        unordered_set<pair<int, int>, PairHash> pacificReachables;
        unordered_set<pair<int, int>, PairHash> atlanticReachables;

        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, -1, 0, 1};

        auto dfs = [&](auto &&dfs, unordered_set<pair<int, int>, PairHash> &reachables, int r, int c) -> void
        {
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    heights[nr][nc] >= heights[r][c] &&
                    !reachables.contains({nr, nc}))
                {
                    reachables.insert({nr, nc});
                    dfs(dfs, reachables, nr, nc);
                }
            }
        };

        // Pacific border
        for (int i = 0; i < n; i++)
        {
            pacificReachables.insert({i, 0});
            dfs(dfs, pacificReachables, i, 0);
            atlanticReachables.insert({i, m - 1});
            dfs(dfs, atlanticReachables, i, m - 1);
        }

        for (int i = 0; i < m; i++)
        {
            pacificReachables.insert({0, i});
            dfs(dfs, pacificReachables, 0, i);
            atlanticReachables.insert({n - 1, i});
            dfs(dfs, atlanticReachables, n - 1, i);
        }

        // Intersection
        vector<vector<int>> ans;
        for (auto &cell : pacificReachables)
        {
            if (atlanticReachables.contains(cell))
            {
                ans.push_back({cell.first, cell.second});
            }
        }

        return ans;
    }
};

// optimized
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, -1, 0, 1};

        auto dfs = [&](auto &&dfs, vector<vector<bool>> &visited, int r, int c) -> void
        {
            visited[r][c] = true;
            for (int k = 0; k < 4; k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    !visited[nr][nc] &&
                    heights[nr][nc] >= heights[r][c])
                {
                    dfs(dfs, visited, nr, nc);
                }
            }
        };

        // Pacific
        for (int i = 0; i < n; i++)
        {
            dfs(dfs, pacific, i, 0);
            dfs(dfs, atlantic, i, m - 1);
        }
        for (int j = 0; j < m; j++)
        {
            dfs(dfs, pacific, 0, j);
            dfs(dfs, atlantic, n - 1, j);
        }

        // Intersection
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
