class Solution
{
public:
    int climbStairs(int n)
    {
        int prev1 = 0;
        int prev2 = 1;
        int cur;

        for (int i = 0; i < n; i++)
        {
            cur = prev2 + prev1;
            prev1 = prev2;
            prev2 = cur;
        }
        return cur;
    }
};