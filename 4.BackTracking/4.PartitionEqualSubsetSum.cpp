
bool solve(int index, vector<int> &nums, int target)
{
    if (target == 0)
    {
        return 1;
    }

    if (target < 0 || index >= nums.size())
    {
        return 0;
    }

    bool include = solve(index + 1, nums, target - nums[index]);
    bool exclude = solve(index + 1, nums, target);

    return (include || exclude);
}

bool canPartition(vector<int> &nums)
{
    int total = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        total += nums[i];
    }
    if (total % 2 != 0)
    {
        return false;
    }
    int target = total / 2;

    return solve(0, nums, target);
}

// optimized

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