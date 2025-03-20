class Solution
{
public:
    int uniquePathsHelper(int i, int j)
    {
        if (i == 0 || j == 0)
            return 1; // Only one way to reach any cell in the first row or first column.
        return uniquePathsHelper(i - 1, j) + uniquePathsHelper(i, j - 1);
    }

    int uniquePaths(int m, int n)
    {
        return uniquePathsHelper(m - 1, n - 1);
    }
};

///.................

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                    cur[j] = 1;
                else
                {
                    cur[j] = prev[j] + cur[j - 1];
                }
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};

// mathemetical

class Solution
{
    long long ncr(int n, int r)
    {
        long long ans = 1;
        for (int i = 0; i < r; i++)
        {
            ans = ans * (n - i) / (i + 1);
        }
        return ans;
    }

public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 && n == 1)
            return 1;

        int totalSteps = m + n - 2;
        int r = min(m - 1, n - 1);
        return (int)ncr(totalSteps, r);
    }
};