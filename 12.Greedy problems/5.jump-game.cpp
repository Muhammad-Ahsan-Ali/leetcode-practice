class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int range = 0;

        for (int i = 0; (i <= range) && (i < n); i++)
        {
            range = max(range, i + nums[i]);
            if (range >= n - 1)
                return true;
        }

        return false;
    }
};