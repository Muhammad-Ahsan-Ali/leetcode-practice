class NumMatrix
{
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefix[i + 1][j + 1] = matrix[i][j] +
                                       prefix[i + 1][j] +
                                       prefix[i][j + 1] -
                                       prefix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int result = prefix[row2 + 1][col2 + 1] -
                     prefix[row1][col2 + 1] -
                     prefix[row2 + 1][col1] +
                     prefix[row1][col1];

        return result;
    }
};