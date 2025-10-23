class Solution
{

    int dp[31][1001];
    int MOD = 1e9 + 7;

private:
    int solve(int n, int k, int target)
    {

        if (n == 0)
            return target == 0;
        if (target < 0)
            return 0;
        if (dp[n][target] != -1)
            return dp[n][target];

        int ways = 0;
        for (int i = 1; i <= k; i++)
        {
            ways = (ways + solve(n - 1, k, target - i)) % MOD;
        }
        return dp[n][target] = ways;
    }

public:
    int numRollsToTarget(int n, int k, int target)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, target);
    }
};

// BUTTOM UP

class Solution
{

    int dp[31][1001];
    int MOD = 1e9 + 7;

public:
    int numRollsToTarget(int n, int k, int target)
    {
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;

        for (int j = 1; j <= n; j++)
        {
            for (int t = 1; t <= target; t++)
            {

                int ways = 0;
                for (int i = 1; i <= k; i++)
                {
                    if (!(t - i < 0))
                        ways = (ways + dp[j - 1][t - i]) % MOD;
                }

                dp[j][t] = ways;
            }
        }

        return dp[n][target];
    }
};

// optimized

class Solution
{

    int MOD = 1e9 + 7;

public:
    int numRollsToTarget(int n, int k, int target)
    {

        vector<int> prev(target + 1, 0);

        prev[0] = 1;

        for (int j = 1; j <= n; j++)
        {
            vector<int> cur(target + 1, 0);

            for (int t = 1; t <= target; t++)
            {

                int ways = 0;
                for (int i = 1; i <= min(k, t); i++)
                {
                    ways = (ways + prev[t - i]) % MOD;
                }

                cur[t] = ways;
            }
            prev = cur;
        }

        return prev[target];
    }
};