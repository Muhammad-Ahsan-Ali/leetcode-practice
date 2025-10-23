class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 4)
            return 0;
        sort(nums.begin(), nums.end());

        int result = nums[n - 4] - nums[0];
        result = min(nums[n - 3] - nums[1], result);
        result = min(nums[n - 2] - nums[2], result);
        result = min(nums[n - 1] - nums[3], result);
        return result;
    }
};

// optimized

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 4)
            return 0;

        sort(nums.begin(), nums.begin() + 4, nums.end());

        nth_element(nums.begin(), nums.begin() + (n - 4), nums.end());
        sort(nums.begin() + (n - 4), nums.end());

        int result = nums[n - 4] - nums[0];
        result = min(nums[n - 3] - nums[1], result);
        result = min(nums[n - 2] - nums[2], result);
        result = min(nums[n - 1] - nums[3], result);
        return result;
    }
};