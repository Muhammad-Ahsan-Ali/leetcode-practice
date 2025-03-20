class Solution
{
    // Function to find the row index of the maximum element in a given column
    int maxInd(vector<vector<int>> &mat, int col, int n)
    {
        int rowInd = 0; // Variable to store the row index of the maximum element
        int maxVal = 0; // Variable to store the maximum value in the column

        // Iterate through each row to find the maximum value in the current column
        for (int i = 0; i < n; i++)
        {
            if (mat[i][col] > maxVal)
            {
                maxVal = mat[i][col]; // Update max value
                rowInd = i;           // Update row index of the max value
            }
        }
        return rowInd; // Return the row index of the maximum element in the column
    }

public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns

        int low = 0;      // Left boundary of binary    (column index)
        int high = m - 1; // Right boundary of binary search (column index)

        // Binary search on columns
        while (low <= high)
        {
            int mid = low + (high - low) / 2; // Find the middle column
            int row = maxInd(mat, mid, n);    // Find the row index of the max element in this column

            // Get values of left and right neighboring columns (if they exist)
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < m ? mat[row][mid + 1] : -1;

            // Check if the current element is greater than both left and right neighbors
            if (mat[row][mid] > left && mat[row][mid] > right)
            {
                return {row, mid}; // Return the peak position
            }
            // If the left neighbor is greater, move left in binary search
            else if (left > mat[row][mid])
            {
                high = mid - 1;
            }
            // If the right neighbor is greater, move right in binary search
            else
            {
                low = mid + 1;
            }
        }
        return {-1, -1}; // If no peak is found (should not happen in a valid peak matrix)
    }
};
