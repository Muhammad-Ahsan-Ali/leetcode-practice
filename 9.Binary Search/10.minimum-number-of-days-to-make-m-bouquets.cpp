class Solution
{
private:
    int getMax(vector<int> &bloomDay)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }
    int getMin(vector<int> &bloomDay)
    {
        int mini = INT_MAX;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            mini = min(mini, bloomDay[i]);
        }
        return mini;
    }

    bool isPossible(vector<int> &bloomDay, int curDay, int m, int k)
    {
        int buckets = 0;
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= curDay)
            {
                cnt++;
            }
            else
            {
                buckets += cnt / k;
                cnt = 0;
            }
        }
        buckets += cnt / k;
        return buckets >= m;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long val = m * 1LL * k * 1LL;
        if (val > bloomDay.size())
        {
            return -1;
        }

        int low = getMin(bloomDay);
        int high = getMax(bloomDay);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(bloomDay, mid, m, k))
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