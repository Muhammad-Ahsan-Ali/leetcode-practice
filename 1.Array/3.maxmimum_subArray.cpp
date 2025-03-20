class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxAll = INT_MIN;
        int n = nums.size();
        int cur = nums[0];
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            maxAll = max(sum, maxAll);
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return maxAll;
    }
};