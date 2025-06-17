class Solution
{
private:
    long long count(string num, string s, int limit)
    {

        int n = num.length();
        int m = s.length();

        if (n < m)
            return 0;

        vector<vector<long long>> dp(20, vector<long long>(2, -1));

        auto f = [&](auto &&f, int i, int tight) -> long long
        {
            if (dp[i][tight] != -1)
                return dp[i][tight];

            int ub = tight ? num[i] - '0' : limit;
            long long res = 0;

            int rLen = n - i;
            if (rLen == 1)
            {
                return dp[i][tight] = (ub >= s[m - 1] - '0' && limit >= s[m - 1] - '0');
            }
            if (rLen <= m)
            {
                if (tight)
                {
                    int a = s[m - rLen] - '0';
                    if (a > ub)
                        return dp[i][tight] = 0LL;
                    else if (a == ub)
                        return dp[i][tight] = f(f, i + 1, tight);
                    else
                    {
                        return dp[i][tight] = 1LL;
                    }
                }
                else
                {
                    return dp[i][tight] = 1;
                }
            }
            else
            {
                for (int d = 0; d <= ub && d <= limit; d++)
                {
                    bool newTight = tight && (d == ub);
                    res += f(f, i + 1, newTight);
                }
            }

            return dp[i][tight] = res;
        };

        return f(f, 0, 1);
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s)
    {

        string l = to_string(start - 1);
        string e = to_string(finish);

        long long ans = count(e, s, limit) - count(l, s, limit);
        return max(0LL, ans);
    }
};