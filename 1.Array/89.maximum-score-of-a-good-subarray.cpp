class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();

        int i = k, j = k;
        int ans = nums[k];
        int subarrayMin = nums[k];
        while (i > 0 || j < n - 1)
        {
            if (i == 0)
                j++;
            else if (j == n - 1)
                i--;
            else if (nums[i - 1] > nums[j + 1])
                i--;
            else
                j++;

            subarrayMin = min({subarrayMin, nums[i], nums[j]});
            int cur = subarrayMin * (j - i + 1);
            ans = max(ans, cur);
        }

        return ans;
    }
};