class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int len = 0;
        int l = 0;
        int r = 0;

        while (r < n)
        {

            if (nums[r] == 0)
                k--;

            if (k < 0 && l < n)
            {
                if (nums[l] == 0)
                    k++;
                l++;
            }

            if (k >= 0)
                len = max(len, r - l + 1);
            r++;
        }

        return len;
    }
};