class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {
        function<pair<int, int>(int, int, bool)> sol = [&](int l, int r, bool turn) -> pair<int, int>
        {
            // base case: no numbers left
            if (l > r)
                return {0, 0};

            // option 1: take left
            auto nextL = sol(l + 1, r, !turn);
            // option 2: take right
            auto nextR = sol(l, r - 1, !turn);

            pair<int, int> takeL, takeR;

            if (turn)
            { // Player1's turn
                takeL = {nextL.first + nums[l], nextL.second};
                takeR = {nextR.first + nums[r], nextR.second};
            }
            else
            { // Player2's turn
                takeL = {nextL.first, nextL.second + nums[l]};
                takeR = {nextR.first, nextR.second + nums[r]};
            }

            // each player plays optimally: current player maximizes their own score
            if (turn)
            {
                return (takeL.first > takeR.first ? takeL : takeR);
            }
            else
            {
                return (takeL.second > takeR.second ? takeL : takeR);
            }
        };

        auto res = sol(0, nums.size() - 1, true);
        return res.first >= res.second;
    }
};

// optimal

class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        function<int(int, int)> sol = [&](int l, int r) -> int
        {
            if (l == r)
                return nums[l];
            if (dp[l][r] != -1)
                return dp[l][r];

            int takeLeft = nums[l] - sol(l + 1, r);
            int takeRight = nums[r] - sol(l, r - 1);

            return dp[l][r] = max(takeLeft, takeRight);
        };

        return sol(0, n - 1) >= 0;
    }
};

// BUTTOM UP

class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];

        for (int l = n - 2; l >= 0; l--)
        {
            for (int r = l + 1; r < n; r++)
            {
                int takeLeft = nums[l] - dp[l + 1][r];
                int takeRight = nums[r] - dp[l][r - 1];
                dp[l][r] = max(takeLeft, takeRight);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};

// most optimal
class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(nums); // base case: dp[i] = nums[i]

        // l goes backwards
        for (int l = n - 2; l >= 0; l--)
        {
            for (int r = l + 1; r < n; r++)
            {
                int takeLeft = nums[l] - dp[r];      // dp[r] is old dp[l+1][r]
                int takeRight = nums[r] - dp[r - 1]; // dp[r-1] is dp[l][r-1]
                dp[r] = max(takeLeft, takeRight);
            }
        }

        return dp[n - 1] >= 0;
    }
};
 
// 1. Outer loop goes backwards: for (int l = n-2; l >= 0; l--)

// This ensures that when we’re at a fixed l, the values for l+1 are still intact in dp.

// 2. Inner loop goes forward: for (int r = l+1; r < n; r++)

// So when we update dp[r], we still have access to:

// dp[r] (before overwriting) → this is dp[l+1][r]

// dp[r-1] (already updated in this row) → this is dp[l][r-1]

// That matches exactly what the recurrence needs.