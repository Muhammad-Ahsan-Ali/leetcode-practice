class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        vector<int> rowOffset = {1, 0, -1, 0};
        vector<int> colOffset = {0, -1, 0, 1};

        queue<pair<int, int>> q;
        int n = grid.size();

        bool cotainWater = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                    q.push({i, j});
                if (!grid[i][j])
                    cotainWater = true;
            }

        if (!cotainWater || q.empty())
            return -1;

        int dist = -1; // -1 means that are have not processed even 0th indx  so at start of loop it becomes dist++ so dist=0 for grid[i][j]=1
        while (!q.empty())
        {
            int sz = q.size();
            dist++;
            for (int i = 0; i < sz; i++)
            {
                auto [r, c] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nr = r + rowOffset[i];
                    int nc = c + colOffset[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nr < n &&
                        !grid[nr][nc])
                    {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return dist;
    }
};