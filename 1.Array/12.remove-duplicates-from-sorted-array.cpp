class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int j = 1;
        int frst_time = 1;
        int num = nums[0];
        int k = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= num)
            {
                if (frst_time)
                {
                    j = i + 1;
                    frst_time = !frst_time;
                }
                while (j < n && nums[j] <= num)
                {
                    j++;
                }
                if (j < n && nums[j] != num)
                {
                    nums[i] = nums[j];
                    num = nums[j];
                    k++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                k++;
                num = nums[i];
            }
        }
        return k;
    }
};

// optimized on

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int c = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[c] != nums[i])
            {
                nums[++c] = nums[i];
            }
        }
        return c + 1;
    }
};