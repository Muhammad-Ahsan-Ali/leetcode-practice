class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;

        int l = 0;
        for (int r = 0; r < n; r++)
        {
            maxi = max(maxi, nums[r]);
            mini = min(mini, nums[r]);
        }
    }
};