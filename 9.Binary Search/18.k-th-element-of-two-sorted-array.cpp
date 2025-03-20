class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        // Get the sizes of both arrays
        int n1 = a.size();
        int n2 = b.size();

        // Ensure that 'a' is the smaller array for binary search efficiency
        if (n1 > n2)
        {
            return kthElement(b, a, k);
        }

        // Number of elements needed in the left partition
        int left = k;

        // Set binary search range in 'a'
        int low = max(0, k - n2); // At least 'k - n2' elements in 'a' to ensure 'k' elements total
        int high = min(n1, k);    // At most 'k' elements in 'a' to avoid excess elements

        // Binary search begins
        while (low <= high)
        {
            // Partition index for 'a'
            int mid1 = low + ((high - low) >> 1);

            // Partition index for 'b' to ensure 'k' elements in the left partition
            int mid2 = left - mid1;

            // Left and right boundary values of partitions
            int l1 = INT_MIN, l2 = INT_MIN; // Left side elements
            int r1 = INT_MAX, r2 = INT_MAX; // Right side elements

            // Set boundary values
            if (mid1 < n1)
                r1 = a[mid1]; // Right boundary of 'a'
            if (mid2 < n2)
                r2 = b[mid2]; // Right boundary of 'b'
            if (mid1 - 1 >= 0)
                l1 = a[mid1 - 1]; // Left boundary of 'a'
            if (mid2 - 1 >= 0)
                l2 = b[mid2 - 1]; // Left boundary of 'b'

            // If partition is correct
            if (l1 <= r2 && l2 <= r1)
            {
                // The k-th smallest element is the maximum of left-side elements
                return max(l1, l2);
            }
            // If 'l1' is greater than 'r2', we need to move 'a's partition left
            else if (l1 > r2)
            {
                high = mid1 - 1;
            }
            // Otherwise, move 'a's partition right
            else
            {
                low = mid1 + 1;
            }
        }

        return 0; // This case should never be reached
    }
};
