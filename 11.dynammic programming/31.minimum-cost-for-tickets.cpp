// RECURSIVE

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(366, -1);

        auto sol = [&](auto &&sol, int i) -> int
        {
            if (i >= n)
            {
                return 0;
            }

            if (dp[i] != -1)
                return dp[i];

            int p1 = costs[0] + sol(sol, i + 1);

            int nextStrt = 7 + days[i];
            int j = lower_bound(days.begin() + i, days.end(), nextStrt) -
                    days.begin();
            int p2 = costs[1] + sol(sol, j);

            nextStrt = 30 + days[i];
            j = lower_bound(days.begin() + i, days.end(), nextStrt) -
                days.begin();
            int p3 = costs[2] + sol(sol, j);

            return dp[i] = min({p1, p2, p3});
        };

        return sol(sol, 0);
    }
};

// TABULATION

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            int p1 = costs[0] + dp[i + 1];

            int nextStrt = 7 + days[i];
            int j = lower_bound(days.begin() + i, days.end(), nextStrt) -
                    days.begin();
            int p2 = costs[1] + dp[j];

            nextStrt = 30 + days[i];
            j = lower_bound(days.begin() + i, days.end(), nextStrt) -
                days.begin();
            int p3 = costs[2] + dp[j];

            dp[i] = min({p1, p2, p3});
        }
        return dp[0];
    }
};

// further optimization

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            int p1 = costs[0] + dp[i + 1];

            int nextStrt = 7 + days[i];
            int upper7 = min(i + 8, n);

            int j = lower_bound(days.begin() + i, days.begin() + upper7,
                                days[i] + 7) -
                    days.begin();
            int p2 = costs[1] + dp[j];

            int upper30 = min(i + 31, n);
            j = lower_bound(days.begin() + i, days.begin() + upper30,
                            days[i] + 30) -
                days.begin();
            int p3 = costs[2] + dp[j];

            dp[i] = min({p1, p2, p3});
        }
        return dp[0];
    }
};
