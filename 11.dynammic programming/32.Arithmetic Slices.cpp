// dp

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;

        vector<int> dp(n, 0);
        int total = 0;

        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dp[i] = dp[i - 1] + 1;
                total += dp[i];
            }
            // else dp[i] remains 0
        }

        return total;
    }
};

// optimized

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ans = 0;
        int temp = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                temp++;
            }
            else
            {
                temp = 0;
            }
            ans += temp;
        }
        return ans;
    }
};