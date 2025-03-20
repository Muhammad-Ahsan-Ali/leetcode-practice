class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int nonZeros = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[nonZeros] = nums[i];
                nonZeros++;
            }
        }

        for (int i = nonZeros; i < n; i++)
        {
            nums[i] = 0;
        }
    }
};

// optimized

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        int n = nums.size();
        int j = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                j = i;
                break;
            }
        }
        if (j == -1)
            return;

        for (int i = j + 1; i < n; i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};