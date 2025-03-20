class Solution
{
public:
    int minPathSumHelper(vector<vector<int>> &grid, int i, int j)
    {
        if (i == 0 && j == 0)
            return grid[0][0]; // Base case: Start point

        if (i < 0 || j < 0)
            return INT_MAX; // Out of bounds, return a large number so it won't be chosen

        return grid[i][j] + min(minPathSumHelper(grid, i - 1, j), minPathSumHelper(grid, i, j - 1));
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return minPathSumHelper(grid, m - 1, n - 1);
    }
};

//
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    cur[j] = grid[i][j];
                }
                else if (i == 0)
                {
                    cur[j] = cur[j - 1] + grid[i][j];
                }
                else if (j == 0)
                {
                    cur[j] = prev[j] + grid[i][j];
                }
                else
                {
                    cur[j] = grid[i][j] + min(prev[j], cur[j - 1]);
                }
            }
            prev = cur;
        }

        return prev[n - 1];
    }
};