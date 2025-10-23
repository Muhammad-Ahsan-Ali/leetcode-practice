class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = nums[0] + nums[1] + nums[2];
        int dif = abs(target - ans);

        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                int newDif = abs(target - sum);
                if (newDif < dif)
                {
                    dif = newDif;
                    ans = sum;
                }
                if (sum == target)
                    return target;

                if (sum < target)
                    j++;
                else
                    k--;
                while (nums[j] == nums[j - 1] && j < k && j != i + 1)
                    j++;
                while (k != n - 1 && j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }

        return ans;
    }
};