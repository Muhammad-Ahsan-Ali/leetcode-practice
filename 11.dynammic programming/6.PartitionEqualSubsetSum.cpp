class Solution
{
public:
    bool canPartitionHelper(vector<int> &nums, int n, int target)
    {
        if (target == 0)
            return true; // Found a valid subset
        if (n == 0)
            return nums[0] == target; // Only one element left to consider

        bool noTake = canPartitionHelper(nums, n - 1, target);
        bool take = false;
        if (nums[n] <= target)
            take = canPartitionHelper(nums, n - 1, target - nums[n]);

        return take || noTake;
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false; // If the sum is odd, partitioning is impossible

        int target = sum / 2;
        return canPartitionHelper(nums, nums.size() - 1, target);
    }
};

//
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<bool> prev(target + 1, 0);
        vector<bool> cur(target + 1, 0);
        prev[0] = 1;
        cur[0] = 1;

        if (nums[0] <= target)
        {
            prev[nums[0]] = true;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int subTarg = 1; subTarg <= target; subTarg++)
            {
                bool noTake = prev[subTarg];
                bool take = false;
                if (nums[ind] <= subTarg)
                {
                    take = prev[subTarg - nums[ind]];
                }
                cur[subTarg] = take || noTake;
            }
            prev = cur;
        }

        return prev[target];
    }
};