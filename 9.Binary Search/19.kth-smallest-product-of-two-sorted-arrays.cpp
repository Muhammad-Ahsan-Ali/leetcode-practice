class Solution
{
    // Helper function to check if at least 'k' products are <= 'product'
    bool isPossible(vector<int> &nums1, vector<int> &nums2, long long product, long long k)
    {
        long long cnt = 0; // Counter to track the number of valid pairs

        for (int i = 0; i < nums1.size(); i++)
        {
            // Case 1: nums1[i] is negative
            if (nums1[i] < 0)
            {
                // To keep product <= given 'product', find the smallest valid nums2[j]
                long long secondNum = ceil((double)product / nums1[i]);

                // Find the first element in nums2 >= secondNum (binary search)
                int ind = lower_bound(nums2.begin(), nums2.end(), secondNum) - nums2.begin();

                // All elements from 'ind' to end of nums2 form valid pairs
                cnt += nums2.size() - ind;
            }
            // Case 2: nums1[i] is positive
            else if (nums1[i] > 0)
            {
                // To keep product <= given 'product', find the largest valid nums2[j]
                long long secondNum = floor((double)product / nums1[i]);

                // Find the first element in nums2 > secondNum (binary search)
                int ind = upper_bound(nums2.begin(), nums2.end(), secondNum) - nums2.begin();

                // All elements before 'ind' form valid pairs
                cnt += ind;
            }
            // Case 3: nums1[i] is zero
            else
            {
                // If product is non-negative, every nums2[j] forms a valid pair
                if (product >= 0)
                {
                    cnt += nums2.size();
                }
            }

            // If we already have at least 'k' valid pairs, return true early
            if (cnt >= k)
            {
                return true;
            }
        }

        // Return whether we found at least 'k' valid pairs
        return cnt >= k;
    }

public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        // Define search range for the k-th smallest product
        long long low = -1e10; // Smallest possible product
        long long high = 1e10; // Largest possible product

        // Binary search for the k-th smallest product
        while (low <= high)
        {
            long long mid = low + ((high - low) >> 1);

            // Check if there are at least 'k' valid products <= 'mid'
            if (isPossible(nums1, nums2, mid, k))
            {
                high = mid - 1; // Look for a smaller possible product
            }
            else
            {
                low = mid + 1; // Increase the product value
            }
        }

        // 'low' will be the k-th smallest product
        return low;
    }
};
