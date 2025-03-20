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

    int getSum(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum;
    }

    bool isPossible(vector<int> &pages, int curAbility, int k)
    {

        int students = 0;
        int i = 0;

        while (i < pages.size())
        {
            int pagesAssigned = 0;
            while (i < pages.size() && (pagesAssigned + pages[i]) <= curAbility)
            {
                pagesAssigned += pages[i];
                i++;
            }
            students++;
        }

        return students <= k;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {

        if (nums.size() < k)
        {
            return -1;
        }

        int low = getMax(nums);
        int high = getSum(nums);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, mid, k))
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