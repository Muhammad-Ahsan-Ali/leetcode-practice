class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();

        if (k % n == 0)
        {
            return;
        }

        vector<int> rotatedNums(n);

        for (int i = 0; i < n; i++)
        {
            rotatedNums[(i + k) % n] = nums[i];
        }

        nums = rotatedNums;
    }
};

// optimized

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        if (k % n == 0)
        {
            return;
        }
        k = k % n;
        int n = nums.size();
        reverse(nums, nums + (n - k));
        reverse(nums + (n - k), nums + n);
        reverse(nums, nums + n);
    }
};