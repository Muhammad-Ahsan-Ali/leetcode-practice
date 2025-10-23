// 🔹 Domino & Tromino Tiling Problem Explanation

// 🔹 Base cases for the tiling problem:
// f(1) = 1 way  → [|]
//   🟦 Only one vertical domino
// f(2) = 2 ways → {[||], [==]}
//   🟦 [||] → Two vertical dominoes stacked
//   🟦 [==] → Two horizontal dominoes side by side

// 🔹 How new tilings are formed:
// To compute f(3) and beyond, consider all unique tilings:
// - f(n-1) → Tilings that extend from a board of length n-1
// - f(n-2) → Tilings that extend from a board of length n-2

// - Tromino contribution:
//   🔹 New tilings using trominos appear when n ≥ 3
//   🔹 For example, f(3) has 5 total ways:
//       - 3 come from f(1) and f(2)
//       - 2 are new tilings using trominos
//               L—⅃   and it,s mirror

//   🟢 Pattern emerges: +2 * f(n-3)

// 🔹 General recurrence relation for f(n):
// f(n) = f(n-1) + f(n-2) + 2*f(n-3) + 2*f(n-4) + ... + 2*f(0)

// 🔹 Simplifying the recurrence:
// f(n-1) = f(n-2) + f(n-3) + 2*f(n-4) + 2*f(n-5) + ... + 2*f(0)

// 🔹 Subtracting f(n-1) from f(n):
// f(n) - f(n-1) = f(n-1) + f(n-3)  --- take — f(n-1) to the right side
// f(n)    = 2*f(n-1) + f(n-3)

// ✅ This gives a compact and efficient way to compute f(n) iteratively

class Solution
{
    int MOD = 1E9 + 7;
    int dp[1001];
    int sol(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = ((2 * sol(n - 1)) % MOD + sol(n - 3) % MOD) % MOD;
    }

public:
    int numTilings(int n)
    {
        memset(dp, -1, sizeof(dp));
        return sol(n);
    }
};

// BOTTOM UP

class Solution
{
public:
    int numTilings(int n)
    {
        if (n == 1 || n == 2)
            return n;
        int MOD = 1E9 + 7;
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; i++)
        {
            dp[i] = ((2 * dp[i - 1]) % MOD + dp[i - 3] % MOD) % MOD;
        }
        return dp[n];
    }
};

// most optimized solution

class Solution
{
public:
    int numTilings(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;

        const int MOD = 1000000007;
        std::array<int, 4> dp = {0, 1, 2, 5}; // dp[1..3] hold last 3 results

        for (int i = 4; i <= n; i++)
        {
            int next = ((2 * dp[3]) % MOD + dp[1] % MOD) % MOD;
            rotate(dp.begin(), dp.begin() + 1, dp.end());
            dp[3] = next;
        }

        return dp[3];
    }
};
