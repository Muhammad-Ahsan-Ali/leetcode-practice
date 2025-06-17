class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        long long n = nums.size();
        sort(nums.begin(), nums.end());

        long long sum, l, r, maxFreq;
        maxFreq = 1;
        sum = 0;
        l = 0;
        r = 0;

        for (int r = 0; r < n; r++)
        {
            sum += nums[r];
            if (l < r && nums[r] * (r - l + 1) > sum + k)
            {
                sum -= nums[l];
                l++;
            }
            maxFreq = max(maxFreq, r - l + 1);
        }
        return maxFreq;
    }
};
