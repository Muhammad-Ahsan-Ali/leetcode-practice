class Solution
{
public:
    // Function to find the minimum number of intervals to remove
    // so that the remaining intervals are non-overlapping
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size(); // Get the number of intervals

        // Sort intervals based on their ending times in ascending order
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int res = 0;             // Counter for non-overlapping intervals
        int lastFinishTime = -1; // Variable to track the end time of the last selected interval

        for (int i = 0; i < n; i++) // Iterate through sorted intervals
        {
            // If the current interval does not overlap with the last selected interval
            if (lastFinishTime < intervals[i].first)
            {
                res++;                                // Increment count of non-overlapping intervals
                lastFinishTime = intervals[i].second; // Update last finish time
            }
        }

        return n - res; // Return the number of intervals that need to be removed
    }
};
