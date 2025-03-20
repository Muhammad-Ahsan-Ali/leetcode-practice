class Solution
{

    int maxCoin(vector<int> &nums, int i, int j, int size)
    {

        if (i > j)
            return 0;

        int maxi = INT_MIN;

        for (int k = i; k <= j; k++)
        {
            int leftBallon = (i == 0) ? 1 : nums[i - 1];
            int rightBallon = (j == size - 1) ? 1 : nums[j + 1];
            int profit = (leftBallon * nums[k] * rightBallon) +
                         maxCoin(nums, i, k - 1, size) +
                         maxCoin(nums, k + 1, j, size);
            maxi = max(profit, maxi);
        }

        return maxi;
    }

public:
    int maxCoins(vector<int> &nums)
    {

        int size = nums.size();

        return maxCoin(nums, 0, size - 1, size);
    }
};

// TABULATION

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--)
        {
            for (int j = i; j <= n; j++)
            {
                int maxi = INT_MIN;

                for (int k = i; k <= j; k++)
                {

                    int leftBallon = (i == 1) ? 1 : nums[i - 2];
                    int rightBallon = (j == n) ? 1 : nums[j];

                    int profit = (leftBallon * nums[k - 1] * rightBallon) +
                                 dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi, profit);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};