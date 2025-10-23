class NumArray
{
    vector<int> prefix;

public:
    NumArray(vector<int> &nums)
    {
        prefix.push_back(0);
        for (int i = 0; i < nums.size(); i++)
            prefix.push_back(nums[i] + prefix.back());
    }

    int sumRange(int left, int right)
    {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */52