class Solution
{
public:
    int minDiff = INT_MAX;
    int totalSum;

    void findSubsetSums(vector<int> &nums, int index, int subsetSum, int count, int N)
    {
        if (count > N)
            return; // We can only take N elements

        // Compute the other subset's sum and update minDiff
        int otherSum = totalSum - subsetSum;
        minDiff = min(minDiff, abs(otherSum - subsetSum));

        // Base case: If we have considered all elements
        if (index == nums.size())
            return;

        // Include current element
        findSubsetSums(nums, index + 1, subsetSum + nums[index], count + 1, N);

        // Exclude current element
        findSubsetSums(nums, index + 1, subsetSum, count, N);
    }

    int minimumDifference(vector<int> &nums)
    {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        int N = nums.size() / 2;

        findSubsetSums(nums, 0, 0, 0, N); // Start recursion

        return minDiff;
    }
};

//....................

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0); // To find the total sum of the array

        int N = n / 2;                                 // Divide it into two equals parts as length is even
        vector<vector<int>> left(N + 1), right(N + 1); // left array and right array

        // All possible sum in left and right part (Generating and storing using BIT-Masking)
        for (int mask = 0; mask < (1 << N); ++mask)
        { // (1<<n) means 2^n i.e we'll iterate through 0 to 2^n
            int idx = 0, l_sum = 0, r_sum = 0;
            for (int i = 0; i < N; ++i)
            {
                if (mask & (1 << i))
                { // To check if the bit is set or not
                    idx++;
                    l_sum += nums[i];
                    r_sum += nums[i + N];
                }
            }
            left[idx].push_back(l_sum);
            right[idx].push_back(r_sum); // storing
        }

        for (int idx = 0; idx <= N; ++idx)
        {
            sort(right[idx].begin(), right[idx].end()); // as we'll perform binary search on right so we have to sort it first
        }

        int res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0])); // To get the minimum answer from the max sum from both array
        // iterating over left part
        for (int idx = 1; idx < N; ++idx)
        { // iterate from 1 so we dont have to include 0 and check for all value except last as we have alr considered it
            for (auto &a : left[idx])
            {                                                  // check the sum at each number position
                int b = (sum - 2 * a) / 2;                     // find the value to be minimized
                int rightidx = N - idx;                        // find the number value in right array
                auto &v = right[rightidx];                     // store the vector in v at right number position
                auto itr = lower_bound(v.begin(), v.end(), b); // binary search over right part

                if (itr != v.end())
                    res = min(res, abs(sum - 2 * (a + (*itr)))); // if found in vector then only update otherwise continue
            }
        }
        return res;
    }
};

//...........

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int N = n / 2;

        vector<vector<int>> left(N + 1), right(N + 1);

        for (int mask = 0; mask < (1 << N); ++mask)
        {
            int ind = 0;
            int left_sum = 0;
            int right_sum = 0;
            for (int i = 0; i < N; i++)
            {
                if (mask & (1 << i))
                {
                    ind++;
                    left_sum += nums[i];
                    right_sum += nums[i + N];
                }
            }
            left[ind].push_back(left_sum);
            right[ind].push_back(right_sum);
        }

        for (int i = 0; i <= N; i++)
        {
            sort(right[i].begin(), right[i].end());
        }

        int res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

        for (int i = 1; i < N; i++)
        {
            for (auto &a : left[i])
            {
                int b = (sum - 2 * a) / 2;
                int rightInd = N - i;
                auto &v = right[rightInd];
                auto itr = lower_bound(v.begin(), v.end(), b);
                if (itr != v.end())
                    res = min(res, abs(sum - 2 * (a + *itr)));
            }
        }
        return res;
    }
};