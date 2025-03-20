
class Solution
{
    // Recursive function to find the maximum sum after partitioning
    int maxProfit(vector<int> &arr, int k, int n, int i)
    {
        // Base case: If index reaches or exceeds array size, return 0 (no further partitioning possible)
        if (i >= n)
            return 0;

        int maxVal = arr[i]; // Stores the maximum value in the current partition
        
        int maxi = INT_MIN;  // Stores the maximum sum for the current partitioning
        // Iterate over possible partition lengths (up to `k` elements)
        for (int j = i; (j < i + k) && (j < n); j++)
        {
            maxVal = max(maxVal, arr[j]); // Update the maximum value in the current partition

            // Compute cost: Maximum value * partition size + recursive call for the next partition
            int cost = (maxVal * (j - i + 1)) + maxProfit(arr, k, n, j + 1);

            // Update the maximum sum obtained so far
            maxi = max(maxi, cost);
        }

        return maxi; // Return the maximum sum for this partitioning
    }

public:
    // Public function to start the recursive process
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();             // Get the length of the array
        return maxProfit(arr, k, n, 0); // Start recursion from index 0
    }
};

// Tabulation

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {

        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {

            int maxVal = arr[i];
            int maxi = INT_MIN;

            for (int j = i; (j < i + k) && (j < n); j++)
            {
                maxVal = max(maxVal, arr[j]);
                int cost = (maxVal * (j - i + 1)) + dp[j + 1];
                maxi = max(maxi, cost);
            }

            dp[i] = maxi;
        }

        return dp[0];
    }
};