class Solution
{
private:
    int getMax(vector<int> &nums)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    bool isPossible(vector<int> &nums, int weight, int threshold)
    {
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += ceil((double)nums[i] / (double)weight);
        }
        return total <= threshold;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1;
        int high = getMax(nums);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, mid, threshold))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};