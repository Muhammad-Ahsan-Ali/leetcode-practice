class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        int n = nums.size();
        long long op = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] <= nums[i + 1])
                continue;

            int parts = ceil((double)nums[i] / nums[i + 1]);
            op += parts - 1;

            nums[i] = nums[i] / parts;
        }

        return op;
    }
};