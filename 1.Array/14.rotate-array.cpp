class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();

        if (k % n == 0)
        {
            return;
        }

        vector<int> rotatedNums(n);

        for (int i = 0; i < n; i++)
        {
            rotatedNums[(i + k) % n] = nums[i];
        }

        nums = rotatedNums;
    }
};

// optimized

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
    
            int n = nums.size();
            if (k % n == 0) {
                return;
            }
            k = k % n;
            reverse(nums.begin(), nums.begin() + (n - k));
            reverse(nums.begin() + (n - k), nums.end());
            reverse(nums.begin(), nums.end());
        }
    };