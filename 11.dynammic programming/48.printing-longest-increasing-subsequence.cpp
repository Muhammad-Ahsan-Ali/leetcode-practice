class Solution
{
public:
    vector<int> getLIS(vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        vector<int> dp(n, 1), hash(n); // dp[i]: length of LIS ending at i, hash[i]: backtracking index
        int lastIndex = 0;             // Index of the last element in the LIS
        int maxi = 1;                  // Length of the longest LIS

        // Initialize hash to point to itself (each element is its own predecessor initially)
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
        }

        // Compute dp array and track predecessors
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev; // Record the previous index
                }
            }
            // Update the maximum LIS length and its last index
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the LIS using the hash array
        vector<int> temp; // To store the LIS
        temp.push_back(arr[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        { // Follow the hash array to backtrack
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }

        reverse(temp.begin(), temp.end()); // Reverse the reconstructed sequence to correct order

        return temp;
    }
};