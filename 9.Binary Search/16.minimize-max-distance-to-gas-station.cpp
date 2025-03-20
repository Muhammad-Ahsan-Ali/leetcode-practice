long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();

    // Vector to keep track of how many additional gas stations are added in each segment
    vector<int> howMany(n - 1, 0);

    // Max heap (priority queue) to store segment lengths along with their index
    // The largest segment will be at the top, ensuring we always divide the longest segment first
    priority_queue<pair<long double, int>> pq;

    // Initialize the priority queue with the initial segment lengths
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    // Iteratively add `k` gas stations to minimize the maximum segment distance
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        // Get the segment with the maximum current length
        auto tp = pq.top();
        pq.pop();

        // Extract the index of this segment in the original array
        int secInd = tp.second;

        // Increment the count of gas stations added to this segment
        howMany[secInd]++;

        // Calculate the new segment length after adding the station
        long double inidiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = inidiff / (long double)(howMany[secInd] + 1);

        // Push the updated segment length back into the priority queue
        pq.push({newSecLen, secInd});
    }

    // The maximum segment length after adding `k` gas stations is at the top of the heap
    return pq.top().first;
}

// binary search method

class Solution
{
private:
    bool isPossible(vector<int> &arr, long double dist, int k)
    {
        int curStation = 0;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int stationInBw = ceil((arr[i + 1] - arr[i]) / dist) - 1;

            // long double gap = arr[i + 1] - arr[i];
            // // Using multiplication instead of division
            // int stationInBw = (gap / dist);  // Equivalent to (gap >= dist * stationInBw)
            // if (gap == stationInBw * dist)
            // {
            //     stationInBw--; // Reduce one if exactly divisible
            // }

            curStation += stationInBw;
        }

        return curStation <= k;
    }

public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        long double low = 0;
        long double high = 0;
        for (int i = 0; i < stations.size() - 1; i++)
        {
            high = max(high, (long double)stations[i + 1] - stations[i]);
        }

        long double dif = 1e-6;

        while (high - low > dif)
        {
            long double mid = low + (high - low) / 2;
            if (isPossible(stations, mid, k))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }

        return high;
    }
};
