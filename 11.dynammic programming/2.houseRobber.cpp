class Solution
{
public:
    int robHelper(vector<int> &nums, int i)
    {
        if (i < 0)
            return 0;
        return max(robHelper(nums, i - 1), nums[i] + robHelper(nums, i - 2));
    }

    int rob(vector<int> &nums)
    {
        return robHelper(nums, nums.size() - 1);
    }
};

// .....
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int prev2 = 0;
        int prev1 = nums[0];

        for (int i = 1; i < n; i++)
        {
            int temp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = temp;
        }
        return prev1;
    }
};