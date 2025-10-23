class Solution
{
    int dp[1001][1001];

public:
    bool canMeasureWater(int x, int y, int target)
    {
        memset(dp, -1, sizeof(dp));

        function<bool(int, int)> sol = [&](int curx, int cury) -> bool
        {
            if (curx == target || cury == target || curx + cury == target)
                return true;

            if (dp[curx][cury] != -1)
                return dp[curx][cury];

            // mark as visited
            dp[curx][cury] = 0;

            // operation 1: empty jug X
            if (sol(curx, 0))
                return dp[curx][cury] = 1;

            // operation 2: empty jug Y
            if (sol(0, cury))
                return dp[curx][cury] = 1;

            // operation 3: fill jug Y completely
            if (sol(curx, y))
                return dp[curx][cury] = 1;

            // operation 4: fill jug X completely
            if (sol(x, cury))
                return dp[curx][cury] = 1;

            // operation 5: pour from Y → X
            int transfer = min(cury, (x - curx));
            int newY = cury - transfer;
            int newX = curx + transfer;
            if (sol(newX, newY))
                return dp[curx][cury] = 1;

            // operation 6: pour from X → Y
            transfer = min(curx, (y - cury));
            newX = curx - transfer;
            newY = cury + transfer;
            if (sol(newX, newY))
                return dp[curx][cury] = 1;

            return dp[curx][cury] = 0;
        };

        return sol(0, 0);
    }
};

// math

class Solution
{
public:
    bool canMeasureWater(int x, int y, int target)
    {
        if (target > x + y)
            return false;
        return target % gcd(x, y) == 0;
    }
};
