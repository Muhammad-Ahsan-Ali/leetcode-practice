class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int l = 0;
        int j = nums.size() - 1;
        vector<int> res(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
            {
                res[l] = nums[i];
                l++;
            }
            if (nums[nums.size() - i - 1] > pivot)
            {
                res[j] = nums[nums.size() - i - 1];
                j--;
            }
        }

        for (size_t i = l; i <= j; i++)
        {
            res[i] = pivot;
        }

        return res;
    }
};