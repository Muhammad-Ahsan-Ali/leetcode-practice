// class Solution
// {
// public:
//     bool check(int i, int j, int n, int m, string s, string p)
//     {
//         if (i == n && j == m)
//             return true;
//         if (i == n || j == m)
//             return false;

//         if (s[i] == p[j])
//         {
//             return check(i + 1, j + 1, n, m, s, p);
//         }

//         else
//         {

//             if (p[j] == '?')
//             {
//                 return check(i + 1, j + 1, n, m, s, p);
//             }
//             if (p[j] == '*')
//             {
//                 int seqL = m - (j + 1);
//                 int ind = n - (seqL);
//                 bool starCheck = false;
//                 for (int k = i; k <= ind; k++)
//                 {
//                     starCheck = starCheck || check(k, j + 1, n, m, s, p);
//                 }
//                 return starCheck;
//             }
//             // if (p[j] == '*')
//             // {
//             //     return check(i + 1, j, n, m, s, p) || check(i, j + 1, n, m, s, p);
//             // }
//             else
//             {
//                 return false;
//             }
//         }
//     }

//     bool isMatch(string s, string p)
//     {
//         int n = s.length();
//         int m = p.length();
//         return check(0, 0, n, m, s, p);
//     }
// };

// //............
// class Solution
// {
// public:
//     bool isMatch(string s, string p)
//     {
//         int n = s.length();
//         int m = p.length();

//         // Initialize DP table with all false values
//         vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

//         // Base case: Both strings are empty
//         dp[n][m] = true;

//         // Fill the DP table in reverse (bottom-up)
//         for (int i = n; i >= 0; i--)
//         {
//             for (int j = m - 1; j >= 0; j--)
//             {
//                 if (i < n && s[i] == p[j])
//                 {
//                     // Characters match
//                     dp[i][j] = dp[i + 1][j + 1];
//                 }
//                 else if (i < n && p[j] == '?')
//                 {
//                     // '?' matches any single character
//                     dp[i][j] = dp[i + 1][j + 1];
//                 }
//                 else if (p[j] == '*')
//                 {
//                     // '*' can match zero or more characters
//                     int seqL = m - (j + 1);
//                     int ind = n - (seqL);

//                     // Instead of looping in recursion, accumulate the results directly
//                     for (int k = i; k <= ind; k++)
//                     {
//                         if (dp[k][j + 1])
//                         {
//                             dp[i][j] = true;
//                             break; // No need to check further once true
//                         }
//                     }
//                 }
//                 else
//                 {
//                     // Characters don't match
//                     dp[i][j] = false;
//                 }
//             }
//         }

//         return dp[0][0];
//     }
// };

//.............

class Solution
{
public:
    bool check(int i, int j, string &s, string &p)
    {
        if (i < 0 && j < 0)
            return true;
        if (j < 0)
            return false;
        if (i < 0)
        {
            // If only '*' remains in pattern, it can match an empty string
            while (j >= 0)
            {
                if (p[j] != '*')
                    return false;
                j--;
            }
            return true;
        }

        if (s[i] == p[j] || p[j] == '?')
        {
            return check(i - 1, j - 1, s, p);
        }

        if (p[j] == '*')
        {
            return check(i - 1, j, s, p) || check(i, j - 1, s, p);
        }

        return false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        return check(n - 1, m - 1, s, p);
    }
};
//,.................
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();

        // DP table
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base case: empty string and empty pattern match
        dp[0][0] = true;

        // Base case: pattern with '*' can match an empty string
        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        // Filling the DP table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1]; // Previous match
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // Match empty or previous char
                }
            }
        }

        return dp[n][m];
    }
};

//..................

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();

        vector<bool> prev(m + 1, false);

        prev[0] = true;

        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == '*')
            {
                prev[j] = prev[j - 1];
            }
        }

        for (int i = 1; i <= n; i++)
        {

            vector<bool> cur(m + 1, false);

            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    cur[j] = prev[j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    cur[j] = prev[j] || cur[j - 1];
                }
                else
                {
                    cur[j] = false;
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};