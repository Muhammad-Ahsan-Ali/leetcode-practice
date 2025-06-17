class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> res(m, -1);
        for (int curCol = 0; curCol < m; curCol++)
        {
            int row = 0;
            int col = curCol;

            while (row < n && col < m)
            {
                if (grid[row][col] == 1)
                {
                    if (col == m - 1 || grid[row][col + 1] == -1)
                        break;
                    col++;
                }
                else
                {
                    if (col == 0 || grid[row][col - 1] == 1)
                        break;
                    col--;
                }
                row++;
            }
            if (row == n)
                res[curCol] = col;
        }
        return res;
    }
};