class Solution
{
int dp[15] public : bool makesquare(vector<int> &matchsticks)
    {

        int n = matchsticks.size();
        function<bool(int, int, int, int, int)> sol = [&](int s1, int s2, int s3, int s4, int i) -> bool
        {
            if (i == n)
                return s1 == s2 && s2 == s3 && s3 == s4;
            bool ans = sol(s1 + matchsticks[i], s2, s3, s4, i + 1) || sol(s1, s2 + matchsticks[i], s3, s4, i + 1) || sol(s1, s2, s3 + matchsticks[i], s4, i + 1) || sol(s1, s2, s3, s4 + matchsticks[i], i + 1);
            return ans;
        };

        return sol(0, 0, 0, 0);
    }
};

// optimized one

class Solution
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
            return false;
        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<int> sides(4, 0);

        function<bool(int)> dfs = [&](int i)
        {
            if (i == matchsticks.size())
                return sides[0] == target && sides[1] == target &&
                       sides[2] == target && sides[3] == target;
            for (int j = 0; j < 4; j++)
            {
                if (sides[j] + matchsticks[i] > target)
                    continue;
                sides[j] += matchsticks[i];
                if (dfs(i + 1))
                    return true;
                sides[j] -= matchsticks[i];
            }
            return false;
        };

        return dfs(0);
    }
};

// bit mask dp memoization

class Solution
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
            return false;
        int target = sum / 4;

        // Sort descending to help pruning
        sort(matchsticks.rbegin(), matchsticks.rend());

        // Memoization: dp[mask][currSum] = whether this state can lead to a solution
        unordered_map<long long, bool> memo;

        function<bool(int, int)> dfs = [&](int mask, int currSum)
        {
            if (mask == (1 << n) - 1)
            {
                // all sticks used, check if sides are complete
                return currSum == 0;
            }

            // encode state (mask + currSum) into one key
            long long key = ((long long)mask << 10) | currSum; //<< 22 could be

            if (memo.count(key))
                return memo[key];

            // Try each unused stick
            for (int i = 0; i < n; i++)
            {
                if (!(mask & (1 << i)))
                { // if stick i not used
                    int next = currSum + matchsticks[i];
                    if (next <= target)
                    {
                        int newMask = mask | (1 << i);
                        // if currSum + stick == target, start a new side
                        if (dfs(newMask, next % target))
                            return memo[key] = true;
                    }
                }
            }
            return memo[key] = false;
        };

        return dfs(0, 0);
    }
};
