class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int numSubsets = 1 << n;
        vector<vector<int>> subsets(numSubsets);

        for (int i = 0; i < numSubsets; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    subsets[i].push_back(nums[j]);
                }
            }
        }

        return subsets;
    }
};
