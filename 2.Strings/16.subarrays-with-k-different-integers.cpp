class Solution
{
private:
    int NumSubStrlessEqualToK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;

        unordered_map<int, int> mp;
        int l = 0;
        int r = 0;

        while (r < n)
        {

            mp[nums[r]]++;

            while (mp.size() > k)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }

            cnt += r - l + 1;

            r++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return (NumSubStrlessEqualToK(nums, k) -
                NumSubStrlessEqualToK(nums, k - 1));
    }
};
