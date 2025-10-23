class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        long long ans = 0;

        auto util = [&](auto &&util, int ind, int curAmount) -> void
        {
            if (curAmount == 0)
            {
                ans++;
                return;
            }
            if (ind == 0)
            {
                if (curAmount % coins[ind] == 0 || curAmount == 0)
                    ans++;
                return;
            }

            // Choice 1: Take the current coin (if possible)
            if (curAmount - coins[ind] >= 0)
                util(util, ind, curAmount - coins[ind]);

            // Choice 2: Skip the current coin
            util(util, ind - 1, curAmount);
        };

        util(util, coins.size() - 1, amount);

        return ans;
    }
};

// optimized

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        long long ans = 0;

        vector<unsigned long long> prev(amount + 1, 0);

        for (int subTar = 0; subTar <= amount; subTar++)
        {
            if (subTar % coins[0] == 0 || subTar == 0)
                prev[subTar]++;
        }

        for (int i = 1; i < coins.size(); i++)
        {
            vector<unsigned long long> cur(amount + 1, 0);
            for (int subTar = 0; subTar <= amount; subTar++)
            {
                // Choice 1: Take the current coin (if possible)
                if (subTar - coins[i] >= 0)
                    cur[subTar] += cur[subTar - coins[i]];

                // Choice 2: Skip the current coin
                cur[subTar] += prev[subTar];
            }
            prev = cur;
        }

        return prev[amount];
    }
};

// most optimized

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1; // There's 1 way to make amount 0

        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount]; // Safe even if large
    }
};
