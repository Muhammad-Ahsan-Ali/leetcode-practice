class Solution
{
private:
    int getMax(vector<int> &piles)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
        {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long hours(vector<int> &piles, int &k)
    {
        long long time = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            // time += (piles[i] + k - 1) / k;
            time += ceil((double)piles[i] / (double)k);
        }
        return time;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {

        int low = 1;
        int high = getMax(piles);
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long time = hours(piles, mid);
            if (time <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // return low;
        return ans;
    }
};
