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

    int getSum(vector<int> &weights)
    {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
        }
        return sum;
    }

    bool isPossible(vector<int> &weights, int curAbility, int days)
    {

        int curDays = 0;
        int i = 0;

        while (i < weights.size())
        {
            int weightLoaded = 0;
            while (i < weights.size() && (weightLoaded + weights[i]) <= curAbility)
            {
                weightLoaded += weights[i];
                i++;
            }
            curDays++;
        }

        return curDays <= days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = getMax(weights);
        int high = getSum(weights);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(weights, mid, days))
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