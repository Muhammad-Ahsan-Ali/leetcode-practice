// binary search method o(n)log(n)

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int left = 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            int cnt = 0;

            for (auto num : nums)
                if (num <= mid)
                    cnt++;

            if (cnt > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

// optimized

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (nums[slow] != nums[fast]);

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};