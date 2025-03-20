class Solution
{
public:
    int lcs(string l, string s)
    {
        int len1 = s.length();
        int len2 = l.length();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (s[i - 1] == l[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[len1][len2];
    }

    int longestPalindromeSubseq(string s)
    {
        int len = s.length();
        string reverse(len, '\0');

        if (len == 0)
        {
            return 0;
        }
        if (len == 1)
        {
            return 1;
        }

        for (int i = 0; i < len; i++)
        {
            reverse[len - i - 1] = s[i];
        }

        int longest = lcs(reverse, s);
        return longest;
    }
};