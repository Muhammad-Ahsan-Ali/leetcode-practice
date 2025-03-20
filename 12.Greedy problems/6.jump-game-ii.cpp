class Solution
{
public:
    int jump(vector<int> &nums)
    {

        int l = 0;
        int r = 0;

        int jumps = 0;

        int n = nums.size();

        while (r < n - 1)
        {
            int range = 0;

            for (int i = l; i <= r; i++)
            {
                range = max(i + nums[i], range);
                if (range >= n - 1)
                    return jumps + 1;
            }

            l = r + 1;
            r = range;
            jumps++;
        }

        return jumps;
    }
};
