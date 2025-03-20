class Solution
{
public:
    int numDistinctHelper(string &s, string &t, int i, int j)
    {
        if (j < 0)
            return 1; // If t is empty, 1 valid subsequence is found
        if (i < 0)
            return 0; // If s is empty but t isn't, no subsequence possible

        if (s[i] == t[j])
        {
            // Either take the character or skip it
            return numDistinctHelper(s, t, i - 1, j - 1) + numDistinctHelper(s, t, i - 1, j);
        }
        else
        {
            // If characters don't match, skip the character in s
            return numDistinctHelper(s, t, i - 1, j);
        }
    }

    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        return numDistinctHelper(s, t, n - 1, m - 1);
    }
};

//...
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        int mod = 1e9 + 7;

        // DP table of size (n+1) x (m+1)
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        // Base case: An empty t can be formed by any prefix of s in exactly 1 way
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] % mod;
                }
            }
        }

        return (int)(dp[n][m] % mod);
    }
};
//...........
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        int mod = 1e9 + 7;

        vector<long long> prev(m + 1, 0), cur(m + 1, 0);

        // Base case: An empty t can be formed by any prefix of s in exactly 1 way
        prev[0] = cur[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    cur[j] = (prev[j - 1] + prev[j]) % mod;
                }
                else
                {
                    cur[j] = prev[j] % mod;
                }
            }
            prev = cur; // Move current row to previous row for next iteration
        }

        return (int)(prev[m] % mod);
    }
};

//............
class Solution
{
public:
    int numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();
        int cnt = 0;
        if (t == s)
            return 1;

        vector<long long> prev(m + 1, 0);
        int mod = 1e9 + 7;
        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                {
                    prev[j] = (prev[j - 1] + prev[j]) % mod;
                }
            }
        }

        return (int)(prev[m] % mod);
    }
};