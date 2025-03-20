class Solution
{
    int lowBound(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size();

        while (low < high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }

    int upperBound(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size();

        while (low < high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int first = lowBound(nums, target);
        int last = upperBound(nums, target) - 1;
        if (first == n || nums[first] != target)
        {
            return {-1, -1};
        }
        return {first, last};
    }
};