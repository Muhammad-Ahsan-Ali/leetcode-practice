
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