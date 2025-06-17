class Solution
{
private:
    int getIdx(int n, int k)
    {
        if (n == 1)
            return 0;

        int idx = getIdx(n - 1, k);
        return (idx + k) % n;
    }

public:
    int findTheWinner(int n, int k)
    {

        return getIdx(n, k) + 1;
    }
};

// optimized

class Solution
{
public:
    int findTheWinner(int n, int k)
    {

        int idx = 0;
        for (int i = 2; i <= n; i++)
            idx = (idx + k) % i;

        return idx + 1;
    }
};