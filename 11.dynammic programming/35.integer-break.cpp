class Solution
{

    int dp[59];

    int solve(int n)
    {

        if (n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int ans = INT_MIN;
        for (int i = 1; i <= n / 2; i++)
        {
            int maxProd = i * max((n - i), solve(n - i));

            ans = max(ans, maxProd);
        }

        return dp[n] = ans;
    }

public:
    int integerBreak(int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};

// optimized

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 3)
            return n - 1;

        int product = 1;
        while (n > 4)
        {
            product *= 3;
            n -= 3;
        }

        product *= n;

        return product;
    }
};
