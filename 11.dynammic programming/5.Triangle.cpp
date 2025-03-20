class Solution
{
public:
    int minimumTotalHelper(vector<vector<int>> &triangle, int i, int j)
    {
        if (i == triangle.size() - 1)
            return triangle[i][j]; // Base case: Last row, return the element itself

        return triangle[i][j] + min(minimumTotalHelper(triangle, i + 1, j),
                                    minimumTotalHelper(triangle, i + 1, j + 1));
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        return minimumTotalHelper(triangle, 0, 0);
    }
};

///
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> prev(n, 0);

        int minV = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j == 0)
                {
                    cur[j] = triangle[i][j] + prev[j];
                }
                else if (j == triangle[i].size() - 1)
                {
                    cur[j] = triangle[i][j] + prev[j - 1];
                }
                else
                {
                    cur[j] = triangle[i][j] + min(prev[j], prev[j - 1]);
                }
            }
            prev = cur;
        }

        for (int i = 0; i < n; i++)
        {
            minV = min(minV, prev[i]);
        }

        return minV;
    }
};