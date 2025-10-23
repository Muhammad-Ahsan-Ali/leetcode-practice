class Solution
{
    vector<int> original;
    int n;

public:
    Solution(vector<int> &nums)
    {
        original = nums;
        n = nums.size();
    }

    vector<int> reset() { return original; }

    vector<int> shuffle()
    {
        vector<int> temp = original;
        for (int i = n - 1; i >= 0; i--)
        {
            int j = rand() % (i + 1);
            swap(temp[i], temp[j]);
        }

        return temp;
    }
};
