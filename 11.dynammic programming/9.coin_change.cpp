class Solution
{
public:
    int coinChangeHelper(vector<int> &coins, int index, int amount)
    {
        if (amount == 0)
            return 0; // No coins needed
        if (index < 0 || amount < 0)
            return INT_MAX - 1; // Impossible case

        // Choice 1: Take the current coin (if possible)
        int take = 1 + coinChangeHelper(coins, index, amount - coins[index]);

        // Choice 2: Skip the current coin
        int noTake = coinChangeHelper(coins, index - 1, amount);

        return min(take, noTake);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int res = coinChangeHelper(coins, coins.size() - 1, amount);
        return (res == INT_MAX - 1) ? -1 : res;
    }
};

//...............
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        if (n == 0)
            return -1;
        if (amount == 0)
            return 0;

        vector<int> prev(amount + 1, INT_MAX);
        prev[0] = 0;

        for (int subTarg = 1; subTarg <= amount; subTarg++)
        {
            if (subTarg % coins[0] == 0)
            {
                prev[subTarg] = subTarg / coins[0];
            }
        }

        for (int ind = 1; ind < n; ind++)
        {
            vector<int> cur(amount + 1, INT_MAX);

            for (int subTarg = 0; subTarg <= amount; subTarg++)
            {
                int noTake = prev[subTarg];
                int take = INT_MAX;

                if (coins[ind] <= subTarg && cur[subTarg - coins[ind]] != INT_MAX)
                {
                    take = 1 + cur[subTarg - coins[ind]];
                }

                cur[subTarg] = min(noTake, take);
            }

            prev = cur;
        }

        return prev[amount] == INT_MAX ? -1 : prev[amount];
    }
};