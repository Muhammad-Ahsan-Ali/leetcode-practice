class Solution
{
private:
    const int mod = 1e9 + 7;

public:
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> pow(n);
        pow[0] = 1;

        for (int i = 1; i < n; i++)
            pow[i] = (2 * pow[i - 1]) % mod;

        int cnt = 0;

        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            if (nums[r] + nums[l] <= target)
            {
                cnt = (cnt + pow[r - l]) % mod;
                l++;
            }
            else
            {
                r--;
            }
        }
        return cnt;
    }
};