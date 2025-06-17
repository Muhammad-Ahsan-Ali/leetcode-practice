class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        for (auto val : nums)
        {
            int ind = abs(val) - 1;
            if (nums[ind] < 0)
                res.push_back(ind + 1);
            else
                nums[ind] = -nums[ind];
        }
        return res;
    }
};