class Solution
{
    int dp[5001][10];
    int MOD = 1e9 + 7;

public:
    Solution() { memset(dp, -1, sizeof(dp)); }
    int knightDialer(int n)
    {

        vector<vector<int>> adj = {
            {4, 6},    // from 0
            {8, 6},    // from 1
            {7, 9},    // from 2
            {8, 4},    // from 3
            {0, 3, 9}, // from 4
            {},        // from 5
            {0, 1, 7}, // from 6
            {2, 6},    // from 7
            {1, 3},    // from 8
            {2, 4}     // from 9
        };

        function<int(int, int)> sol = [&](int n, int cell) -> int
        {
            if (n == 0)
                return 1;
            if (dp[n][cell] != -1)
                return dp[n][cell];

            int ans = 0;
            for (auto nextCell : adj[cell])
                ans = (ans + sol(n - 1, nextCell)) % MOD;

            return dp[n][cell] = ans;
        };

        int ans = 0;
        for (int i = 0; i <= 9; i++)
            ans = (ans + sol(n - 1, i)) % MOD;

        return ans;
    }
};

// BOTTOM UP

class Solution
{
    int dp[5001][10];
    int MOD = 1e9 + 7;

public:
    Solution() { memset(dp, -1, sizeof(dp)); }
    int knightDialer(int n)
    {

        vector<vector<int>> adj = {
            {4, 6},    // from 0
            {8, 6},    // from 1
            {7, 9},    // from 2
            {8, 4},    // from 3
            {0, 3, 9}, // from 4
            {},        // from 5
            {0, 1, 7}, // from 6
            {2, 6},    // from 7
            {1, 3},    // from 8
            {2, 4}     // from 9
        };

        for (int i = 0; i <= 9; i++)
            dp[0][i] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int cell = 0; cell <= 9; cell++)
            {
                int temp = 0;
                for (int nextCell : adj[cell])
                {
                    temp = (temp + dp[i - 1][nextCell]) % MOD;
                }
                dp[i][cell] = temp;
            }
        }

        long long ans = 0;
        for (int d = 0; d <= 9; d++)
            ans = (ans + dp[n - 1][d]) % MOD;

        return ans;
    }
};

// 1D dp

class Solution
{
    int MOD = 1e9 + 7;

public:
    Solution() { memset(dp, -1, sizeof(dp)); }
    int knightDialer(int n)
    {
        vector<vector<int>> adj = {
            {4, 6},    // from 0
            {8, 6},    // from 1
            {7, 9},    // from 2
            {8, 4},    // from 3
            {0, 3, 9}, // from 4
            {},        // from 5
            {0, 1, 7}, // from 6
            {2, 6},    // from 7
            {1, 3},    // from 8
            {2, 4}     // from 9
        };

        int prev[10];
        for (int i = 0; i <= 9; i++)
            prev[i] = 1;

        for (int i = 1; i < n; i++)
        {
            int cur[10];
            for (int cell = 0; cell <= 9; cell++)
            {
                int temp = 0;
                for (int nextCell : adj[cell])
                {
                    temp = (temp + prev[nextCell]) % MOD;
                }
                cur[cell] = temp;
            }
            prev = cur;
        }

        long long ans = 0;
        for (int d = 0; d <= 9; d++)
            ans = (ans + prev[d]) % MOD;

        return ans;
    }
};