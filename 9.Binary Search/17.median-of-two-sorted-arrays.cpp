class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Get the sizes of both input arrays
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Ensure nums1 is the smaller array for binary search efficiency
        if (n1 > n2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // The total elements that should be in the left half
        int left = (n2 + n1 + 1) / 2;
        int low = 0, high = n1;

        while (low <= high)
        {
            // Find the partition index for nums1
            int mid1 = low + ((high - low) >> 1);
            // Calculate corresponding partition index for nums2
            int mid2 = left - mid1;

            // Initialize left and right boundaries for both arrays
            int l1 = INT_MIN, l2 = INT_MIN; // Left side elements
            int r1 = INT_MAX, r2 = INT_MAX; // Right side elements

            // Update boundary values based on partition positions
            if (mid1 < n1)
                r1 = nums1[mid1]; // Right boundary of nums1
            if (mid2 < n2)
                r2 = nums2[mid2]; // Right boundary of nums2
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1]; // Left boundary of nums1
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1]; // Left boundary of nums2

            // If correct partition is found
            if (l1 <= r2 && l2 <= r1)
            {
                // If total length is odd, return max of left side
                if ((n1 + n2) % 2)
                {
                    return max(l1, l2);
                }
                // If total length is even, return average of middle elements
                else
                {
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            // If l1 is greater than r2, move left in nums1
            else if (l1 > r2)
            {
                high = mid1 - 1;
            }
            // Otherwise, move right in nums1
            else
            {
                low = mid1 + 1;
            }
        }
        return 0; // This case should never be reached
    }
};
