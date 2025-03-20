#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    vector<int> nums = {1, 5, 1, 5};
    cout << canPartition(nums);

    return 0;
}