class Solution
{
private:
    int numSubarraysWithOddLessEqlToK(vector<int> &nums, int k)
    {

        if (k < 0)
            return 0;

        int n = nums.size();

        int r = 0;
        int l = 0;
        int oddCnt = 0;
        int cnt = 0;

        for (int r = 0; r < n; r++)
        {
            if (nums[r] % 2 == 1)
                oddCnt++;

            while (oddCnt > k)
            {
                if (nums[l] % 2 == 1)
                    oddCnt--;
                l++;
            }

            cnt += r - l + 1;
        }
        return cnt;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return numSubarraysWithOddLessEqlToK(nums, k) - numSubarraysWithOddLessEqlToK(nums, k - 1);
    }
};