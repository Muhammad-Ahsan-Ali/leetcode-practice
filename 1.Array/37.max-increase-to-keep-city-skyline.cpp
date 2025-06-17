class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {

        int n = grid.size();
        vector<int> rowMax(n, 0);
        vector<int> colMax(n, 0);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                rowMax[i] = max(grid[i][j], rowMax[i]);
                colMax[j] = max(grid[i][j], colMax[j]);
            }

        int sum = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                sum += min(rowMax[i], colMax[j]) - grid[i][j];

        return sum;
    }
};