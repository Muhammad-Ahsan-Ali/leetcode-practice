class Solution
{
private:
    vector<int> preCal;
    vector<vector<int>> dp; // dp[idx][target] stores the result

    int helper(int idx, int target)
    {
        // Base case: exact match → 0 squares needed
        if (target == 0)
            return 0;

        // Base case: invalid situation (ran out of squares or overshot target)
        if (idx < 0 || target < 0)
            return INT_MAX - 1;

        // If already computed, return stored value
        if (dp[idx][target] != -1)
            return dp[idx][target];

        // Choice 1: Take the current square (idx stays same, unlimited supply)
        int take = 1 + helper(idx, target - preCal[idx]);

        // Choice 2: Skip the current square (move to smaller square)
        int noTake = helper(idx - 1, target);

        // Store and return min of both choices
        return dp[idx][target] = min(take, noTake);
    }

public:
    Solution()
    {
        int i = 1;
        while (i * i <= 10001)
        {
            preCal.push_back(i * i);
            i++;
        }
    }

    int numSquares(int n)
    {
        int idx = upper_bound(preCal.begin(), preCal.end(), n) - preCal.begin();

        dp.assign(idx, vector<int>(n + 1, -1));

        int res = helper(idx - 1, n);

        return res;
    }
};

// BOTTOM UP

class Solution
{
private:
    vector<int> preCal;

public:
    Solution()
    {
        int i = 1;
        while (i * i <= 10001)
        {
            preCal.push_back(i * i);
            i++;
        }
    }

    int numSquares(int n)
    {
        int sz = upper_bound(preCal.begin(), preCal.end(), n) - preCal.begin();

        vector<int> prev(n + 1, INT_MAX);

        prev[0] = 0;

        for (int targ = 1; targ <= n; targ++)
        {
            if ((targ % preCal[0]) == 0)
                prev[targ] = targ / preCal[0];
        }

        for (int i = 1; i < sz; i++)
        {
            vector<int> cur(n + 1, INT_MAX);
            for (int targ = 0; targ <= n; targ++)
            {

                int take = INT_MAX;
                if (targ >= preCal[i] && cur[targ - preCal[i]] != INT_MAX)
                    take = 1 + cur[targ - preCal[i]];

                int noTake = prev[targ];

                cur[targ] = min(take, noTake);
            }
            prev = cur;
        }

        int res = prev[n];

        return res;
    }
};

// another approach

class Solution
{
    int dp[10001];
    int sol(int n)
    {
        if (n == 0)
            return 0;

        int minRes = INT_MAX;
        for (int i = 1; (i * i) <= n; i++)
        {
            int ans = 1 + sol(n - (i * i));
            minRes = min(minRes, ans);
        }
        return minRes;
    }

public:
    int numSquares(int n)
    {
        memset(dp, -1, sizeof(dp));
        return sol(n);
    }
};

// bottom up

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int val = 1; (val * val) <= n; val++)
        {
            for (int targ = val * val; targ <= n; targ++)
            {
                int ans = 1 + dp[targ - (val * val)];
                dp[targ] = min(dp[targ], ans);
            }
        }

        return dp[n];
    }
};

// 📘USING Lagrange & Legendre Theorem
// 👉 Every number can be expressed as the sum of at most 4 squares.
//    n = a^2 + b^2 + c^2 + d^2
//
// ✅ Case 1 (Answer = 1):
//    The number must be a perfect square.
//
// ✅ Case 2 (Answer = 2):
//    We need to find two numbers i, j such that:
//       i^2 + j^2 = n
//       j^2 = n - i^2
//       j = sqrt(n - i^2)
//
// ✅ Case 4 (Answer = 4):
//    A number n satisfies this form:
//       n = 4^k * (8m + 7)
//    Since k and m are unknown, we do:
//       - Divide n by 4 until (n % 4 == 0)
//       - If the remaining part ≡ 7 (mod 8), i.e. (n % 8 == 7)
//       - left is (8m+7) we do
//       - (8m+7)%8
//       - ((8m % 8) +( 7 % 8)) which gives
//       -  7 so
//       - (8m+7) % 8 == 7 for ans =4
//       - (n)%8 == 7 for ans =4
//         ➝ Answer = 4
//
// ✅ Otherwise (default case):
//    Answer = 3

class Solution
{
public:
    int numSquares(int n)
    {
        int sqrt = (int)sqrt(n);
        if (sqrt * sqrt == n)
            return 1;

        while (n % 4 == 0)
            n = n / 4;
        if (n % 8 == 7)
            return 4;

        for (int i = 0; i * i <= n; i++)
        {
            int valA = i * i;
            int valB = (int)sqrt(n - valA);
            if (valB * valB == n - valA)
                return 2;
        }
        return 3;
    }
};