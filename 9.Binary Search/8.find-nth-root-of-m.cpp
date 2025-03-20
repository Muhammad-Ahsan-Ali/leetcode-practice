class Solution
{

private:
    long long myPow(long long x, int n, int m)
    {
        long long ans = 1;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans = ans * x;
                if (ans > m)
                    return m + 1;
                n--;
            }
            else
            {
                x = x * x;
                if (x > m)
                    return m + 1;
                n /= 2;
            }
        }
        return ans;
    }

public:
    int nthRoot(int n, int m)
    {
        int low = 1;
        int high = m;
        int ans = -1;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long val = myPow(mid, n, m);

            if (val == m)
                return mid; // ans
            else if (val < m)
                low = mid + 1;
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};