class Solution
{
private:
    int profCal(int ind, vector<int> &prices, int n, int canBuy, int transactionsLeft)
    {
        if (transactionsLeft == 0)
            return 0;
        if (ind == n)
            return 0;

        if (canBuy)
        { // Choose to buy (-prices[day]) or skip to the next day
            return max(-prices[ind] + profCal(ind + 1, prices, n, !canBuy, transactionsLeft),
                       0 + profCal(ind + 1, prices, n, canBuy, transactionsLeft));
        }
        else
        { // Choose to sell (+prices[day]) or skip to the next day
            return max(prices[ind] +
                           profCal(ind + 1, prices, n, !canBuy, transactionsLeft - 1),
                       0 + profCal(ind + 1, prices, n, canBuy, transactionsLeft));
        }
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return profCal(0, prices, n, 1, 2);
    }
};

///  ...................

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (canBuy)
                    {
                        dp[ind][canBuy][cap] =
                            max(-prices[ind] + dp[ind + 1][!canBuy][cap],
                                0 + dp[ind + 1][canBuy][cap]);
                    }
                    else
                    {
                        dp[ind][canBuy][cap] =
                            max(prices[ind] + dp[ind + 1][!canBuy][cap - 1],
                                0 + dp[ind + 1][canBuy][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};
///  ...................

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> after(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            vector<vector<int>> cur(2, vector<int>(3, 0));
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (canBuy)
                    {
                        cur[canBuy][cap] =
                            max(-prices[ind] + after[!canBuy][cap],
                                0 + after[canBuy][cap]);
                    }
                    else
                    {
                        cur[canBuy][cap] =
                            max(prices[ind] + after[!canBuy][cap - 1],
                                0 + after[canBuy][cap]);
                    }
                }
            }
            after = cur;
        }
        return after[1][2];
    }
};
