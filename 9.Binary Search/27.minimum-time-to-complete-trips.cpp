class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {

        long long min = 1LL * *min_element(time.begin(), time.end());

        long long low = 1;
        long long high = totalTrips * min;

        function<bool(long long)> isPossible = [&](long long curTime) -> bool
        {
            long long rides = 0;
            for (auto timeTakes : time)
            {
                rides += curTime / timeTakes;
                if (rides >= totalTrips)
                    return true;
            }

            return rides >= totalTrips;
        };

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (isPossible(mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};