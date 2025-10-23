class Solution
{
private:
    void dfsSavr(vector<vector<bool>> &saved, vector<vector<int>> &grid, int curR, int curC)
    {
        if (grid[curR][curC] != 1 || saved[curR][curC])
            return;

        saved[curR][curC] = true;

        vector<int> rOffset = {1, 0, -1, 0};
        vector<int> cOffset = {0, 1, 0, -1};

        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nexR = curR + rOffset[i];
            int nexC = curC + cOffset[i];
            if (nexR >= 0 && nexC >= 0 && nexR < r && nexC < c)
            {
                dfsSavr(saved, grid, nexR, nexC);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {

        int r = grid.size();
        int c = grid[0].size();
        int enclaves = 0;

        vector<vector<bool>> saved(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++)
        {
            if (grid[i][0] == 1)
            {
                dfsSavr(saved, grid, i, 0);
            }
            if (grid[i][c - 1] == 1)
            {
                dfsSavr(saved, grid, i, c - 1);
            }
        }

        for (int i = 0; i < c; i++)
        {
            if (grid[0][i] == 1)
            {
                dfsSavr(saved, grid, 0, i);
            }

            if (grid[r - 1][i] == 1)
            {
                dfsSavr(saved, grid, r - 1, i);
            }
        }

        for (int i = 0; i < r; i++)
        {

            for (int j = 0; j < c; j++)
            {
                if (!saved[i][j] && grid[i][j] == 1)
                {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};