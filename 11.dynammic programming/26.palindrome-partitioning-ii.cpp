class Solution
{

    bool isPalindrome(string &s, int i, int j)
    {
        bool output = true;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                output = false;
                break;
            }
            i++;
            j--;
        }
        return output;
    }

    int plndrmCuts(string &s, int i, int j)
    {
        if (i == j || isPalindrome(s, i, j))
            return 0;

        int mini = 10e7;

        for (int k = i; k < j; k++)
        {
            int cost = 1 + plndrmCuts(s, i, k) + plndrmCuts(s, k + 1, j);
            mini = min(cost, mini);
        }
        return mini;
    }

public:
    int minCut(string s)
    {
        int n = s.length();
        return plndrmCuts(s, 0, n - 1);
    }
};

// tabulation

class Solution
{
public:
    int minCut(string s)
    {
        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n, 0); // dp[i] stores min cuts for substring s[0:i]

        // Step 1: Precompute palindrome table
        for (int gap = 0; gap < n; gap++) // Length of substring
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0) // Single character is always a palindrome
                    isPalindrome[i][j] = true;
                else if (gap == 1) // Two characters are palindrome if both are same
                    isPalindrome[i][j] = (s[i] == s[j]);
                else // More than two characters
                    isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
            }
        }

        // Step 2: Fill DP table using the precomputed palindrome info
        for (int i = 0; i < n; i++)
        {
            if (isPalindrome[0][i]) // If s[0:i] is already a palindrome, no cuts needed
            {
                dp[i] = 0;
            }
            else
            {
                int minCuts = INT_MAX;
                for (int j = 0; j < i; j++)
                {
                    if (isPalindrome[j + 1][i]) // If s[j+1:i] is palindrome
                    {
                        minCuts = min(minCuts, dp[j] + 1);
                    }
                }
                dp[i] = minCuts;
            }
        }

        return dp[n - 1]; // Minimum cuts needed for the whole string
    }
};

////...............

class Solution
{

    bool isPalindrome(string &s, int i, int j)
    {
        bool output = true;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                output = false;
                break;
            }
            i++;
            j--;
        }
        return output;
    }

public:
    int minCut(string s)
    {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= n - 1; j++)
            {

                int mini = 10e7;

                for (int k = i; k < j; k++)
                {
                    int cost = 1 + dp[i][k] + dp[k + 1][j];
                    mini = min(cost, mini);
                }
                dp[i][j] = mini;
            }
        }

        return dp[0][n - 1];
    }
};

// optimized

class Solution
{

    bool isPalindrome(string &s, int i, int j)
    {
        bool output = true;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                output = false;
                break;
            }
            i++;
            j--;
        }
        return output;
    }

public:
    int minCut(string s)
    {

        int n = s.length();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int mini = 1e7;
            for (int k = i; k < n; k++)
            {
                if (isPalindrome(s, i, k))
                {
                    int cost = 1 + dp[k + 1];
                    mini = min(mini, cost);
                }
                dp[i] = mini;
            }
        }
        return dp[0] - 1;
    }
};