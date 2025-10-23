class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> output(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> q;

        vector<int> rowOffset = {-1, 0, 1, 0};
        vector<int> colOffset = {0, -1, 0, 1};

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    output[i][j] = 0;
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> cell = q.front();
            q.pop();
            int curRow = cell.first;
            int curCol = cell.second;

            for (int k = 0; k < 4; k++)
            {
                int nextRow = curRow + rowOffset[k];
                int nextCol = curCol + colOffset[k];

                if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols)
                {
                    if (output[nextRow][nextCol] > output[curRow][curCol] + 1)
                    {
                        output[nextRow][nextCol] = output[curRow][curCol] + 1;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }

        return output;
    }
};
