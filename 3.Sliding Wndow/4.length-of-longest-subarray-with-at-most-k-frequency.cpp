class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;

        unordered_map<int, int> freq;
        int l = 0;
        int r = 0;
        int len = 0;

        while (r < n)
        {

            freq[nums[r]]++;

            while (freq[nums[r]] > k)
            {
                freq[nums[l]]--;
                l++;
            }

            len = max(r - l + 1, len);
            r++;
        }

        return len;
    }
};
