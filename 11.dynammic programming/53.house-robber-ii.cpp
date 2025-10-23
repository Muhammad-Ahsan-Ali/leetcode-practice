class Solution
{
private:
    int cal(vector<int> &nums, int strt, int n)
    {

        int prev2 = 0;
        int prev1 = nums[strt];

        for (int i = strt + 1; i < n; i++)
        {
            int temp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = temp;
        }
        return prev1;
    }

public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(cal(nums, 1, n), cal(nums, 0, n - 1));
    }
};