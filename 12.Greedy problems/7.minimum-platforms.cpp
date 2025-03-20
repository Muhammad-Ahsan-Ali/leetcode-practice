class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();

        // Sort arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0;            // Pointer for arrival times
        int j = 0;            // Pointer for departure times
        int platforms = 0;    // Stores the maximum platforms needed
        int maxPlatforms = 0; // Tracks the current number of platforms in use

        // Iterate until all trains have arrived
        while (i < n)
        {

            // If a train arrives before or at the same time as the previous one departs
            if (arr[i] <= dep[j])
            {
                i++;            // Move to next arriving train
                maxPlatforms++; // Increase platform count
            }
            else
            {
                j++;            // Move to next departing train
                maxPlatforms--; // Decrease platform count
            }

            // Update maximum platforms needed
            platforms = max(platforms, maxPlatforms);
        }

        return platforms; // Return the maximum platforms required at any time
    }
};
