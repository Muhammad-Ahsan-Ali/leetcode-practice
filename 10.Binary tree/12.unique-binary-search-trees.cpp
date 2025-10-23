class Solution
{

private:
    map<pair<int, int>, int> mp;

    int generateTreesCnt(int start, int end)
    {
        if (start > end)
            return 1;

        if (mp.contains({start, end}))
            return mp[{start, end}];

        int ans = 0;
        for (int i = start; i <= end; i++)
        {
            int left = generateTreesCnt(start, i - 1);
            int right = generateTreesCnt(i + 1, end);

            ans += left * right;
        }
        return mp[{start, end}] = ans;
    }

public:
    int numTrees(int n) { return generateTreesCnt(1, n); }
};

// Another approach
class Solution
{
private:
    vector<int> memo;

    int countTrees(int n)
    {
        if (n <= 1)
            return 1; // base cases
        if (memo[n] != -1)
            return memo[n]; // already computed

        int ans = 0;
        for (int root = 1; root <= n; root++)
        {
            ans += countTrees(root - 1) * countTrees(n - root);
        }
        return memo[n] = ans;
    }

public:
    int numTrees(int n)
    {
        memo.assign(n + 1, -1);
        return countTrees(n);
    }
};

// BUTTOM UP
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1; // base cases

        for (int nodes = 2; nodes <= n; nodes++)
        {
            for (int i = 1; i <= nodes; i++)
            {
                dp[nodes] += dp[i - 1] * dp[nodes - i];
            }
        }

        return dp[n];
    }
};
