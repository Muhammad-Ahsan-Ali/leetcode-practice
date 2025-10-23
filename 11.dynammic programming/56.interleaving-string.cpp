class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        if (n1 + n2 != n3)
            return 0;

        int dp[101][101][201];
        memset(dp, -1, sizeof(dp));

        function<bool(int, int, int)> check = [&](int i, int j, int k) -> bool
        {
            if (i == n1 && j == n2 && k == n3)
                return 1;

            if (dp[i][j][k] != -1)
                return dp[i][j][k];

            if (s1[i] == s3[k])
                if (check(i + 1, j, k + 1))
                    return dp[i][j][k] = 1;

            if (s2[j] == s3[k])
                if (check(i, j + 1, k + 1))
                    return dp[i][j][k] = 1;

            return dp[i][j][k] = 0;
        };

        return check(0, 0, 0);
    }
};

// memoization
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3)
            return false;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        dp[n1][n2] = 1;

        // Fill last row
        for (int j = n2 - 1; j >= 0; j--)
        {
            int k = n1 + j;
            dp[n1][j] = (s2[j] == s3[k] && dp[n1][j + 1]);
        }

        // Fill last column
        for (int i = n1 - 1; i >= 0; i--)
        {
            int k = i + n2;
            dp[i][n2] = (s1[i] == s3[k] && dp[i + 1][n2]);
        }

        // Fill the rest
        for (int i = n1 - 1; i >= 0; i--)
        {
            for (int j = n2 - 1; j >= 0; j--)
            {
                int k = i + j;
                if (s1[i] == s3[k] && dp[i + 1][j])
                    dp[i][j] = 1;
                if (s2[j] == s3[k] && dp[i][j + 1])
                    dp[i][j] = 1;
            }
        }

        return dp[0][0];
    }
};

// optimization

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3)
            return false;

        vector<int> ahead(n2 + 1, 0), cur(n2 + 1, 0);

        ahead[n2] = 1;

        // Fill last row
        for (int j = n2 - 1; j >= 0; j--)
        {
            int k = n1 + j;
            ahead[j] = (s2[j] == s3[k] && ahead[j + 1]);
        }

        for (int i = n1 - 1; i >= 0; i--)
        {
            // last column
            cur[n2] = (s1[i] == s3[i + n2] && ahead[n2]);

            for (int j = n2 - 1; j >= 0; j--)
            {
                int k = i + j;
                cur[j] = 0;
                if (s1[i] == s3[k] && ahead[j])
                    cur[j] = 1;
                if (s2[j] == s3[k] && cur[j + 1])
                    cur[j] = 1;
            }

            ahead = cur;
        }

        return ahead[0];
    }
};
 