
class Solution
{

public:
    long long maxPoints(vector<vector<int>> &points)
    {

        int n = points.size();
        int m = points[0].size();

        function<long long(int, int)> sol = [&](int prevRow,
                                                int prevCol) -> long long
        {
            if (prevRow == n - 1)
                return 0;

            long long ans = LONG_LONG_MIN;
            int row = prevRow + 1;

            for (int col = 0; col < m; col++)
            {
                long long cost = abs(prevCol - col);
                long long profit = points[row][col] + sol(row, col) - cost;
                ans = max(ans, profit);
            }

            return ans;
        };

        long long res = LONG_LONG_MIN;
        for (int col = 0; col < m; col++)
            res = max(res, points[0][col] + sol(0, col));

        return res;
    }
};

// dp

class Solution
{

public:
    long long maxPoints(vector<vector<int>> &points)
    {

        int n = points.size();
        int m = points[0].size();

        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        long long res = LONG_LONG_MIN;

        for (int prevRow = n - 2; prevRow >= 0; prevRow--)
        {

            for (int prevCol = 0; prevCol < m; prevCol++)
            {
                long long ans = LONG_LONG_MIN;
                int row = prevRow + 1;

                for (int col = 0; col < m; col++)
                {
                    long long cost = abs(prevCol - col);
                    long long profit = points[row][col] + dp[row][col] - cost;
                    ans = max(ans, profit);
                }

                dp[prevRow][prevCol] = ans;
            }
        }

        for (int col = 0; col < m; col++)
            res = max(res, (long long)(points[0][col] + dp[0][col]));

        return res;
    }
};

// OPTIMIZATION

class Solution
{

public:
    long long maxPoints(vector<vector<int>> &points)
    {

        int n = points.size();
        int m = points[0].size();

        vector<long long> dp(points[n - 1].begin(), points[n - 1].end());

        for (int row = n - 2; row >= 0; row--)
        {
            vector<long long> left(m), right(m);

            left[0] = dp[0];
            for (int col = 1; col < m; col++)
                left[col] = max(left[col - 1] - 1, dp[col]);

            right[m - 1] = dp[m - 1];
            for (int col = m - 2; col >= 0; col--)
                right[col] = max(right[col + 1] - 1, dp[col]);

            for (int col = 0; col < m; col++)
                dp[col] = points[row][col] + max(left[col], right[col]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
