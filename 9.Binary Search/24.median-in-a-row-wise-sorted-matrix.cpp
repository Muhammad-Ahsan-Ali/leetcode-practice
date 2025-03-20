class Solution
{
private:
    // Function to check if the count of elements <= 'el' is too low (<= required count)
    bool countIsTooLow(vector<vector<int>> &mat, int el, int req, int n)
    {
        int smallerEqualEl = 0; // Counter for elements <= 'el'

        // Iterate through each row and count elements ≤ 'el' using upper_bound
        for (int i = 0; i < n; i++)
        {
            // upper_bound returns the first index where element > 'el'
            // Subtracting mat[i].begin() gives the count of elements ≤ 'el' in row i
            smallerEqualEl += upper_bound(mat[i].begin(), mat[i].end(), el) - mat[i].begin();
        }

        // If the count is less than or equal to required, return true (search in higher half)
        return smallerEqualEl <= req;
    }

public:
    int median(vector<vector<int>> &mat)
    {
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns

        int low = 0;  // Initialize lower bound for binary search
        int high = 0; // Initialize upper bound for binary search

        // Find the minimum and maximum elements in the matrix
        for (int i = 0; i < n; i++)
        {
            low = min(mat[i][0], low);       // Minimum element in the first column
            high = max(mat[i][m - 1], high); // Maximum element in the last column
        }

        int req = (m * n) / 2; // Required count to reach the median position

        // Perform binary search for the median value
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // If count of elements ≤ mid is too low, move right
            if (countIsTooLow(mat, mid, req, n))
            {
                low = mid + 1;
            }
            // Otherwise, move left
            else
            {
                high = mid - 1;
            }
        }

        return low; // The median value
    }
};
