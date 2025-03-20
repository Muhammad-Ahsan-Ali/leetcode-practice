class Solution
{
private:
    int lis(vector<int> &nums, int n, int cur, int prev)
    {

        if (cur >= n)
        {
            return 0;
        }

        int len = lis(nums, n, cur + 1, prev);

        if (prev == -1 || nums[prev] < nums[cur])
        {
            len = max(1 + lis(nums, n, cur + 1, cur), len);
        }

        return len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return lis(nums, n, 0, -1);
    }
};

///  ...................

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int cur = n - 1; cur >= 0; cur--)
        {
            for (int prev = cur - 1; prev >= -1; prev--)
            {
                int len = dp[cur + 1][prev + 1];
                if (prev == -1 || nums[prev] < nums[cur])
                {
                    len = max(1 + dp[cur + 1][cur + 1], len); // ...........
                }
                dp[cur][prev + 1] = len;
            }
        }
        return dp[0][0];
    }
};

///  ...................

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ahead(n + 1, 0);

        for (int cur = n - 1; cur >= 0; cur--)
        {
            vector<int> curR(n + 1, 0);
            for (int prev = cur - 1; prev >= -1; prev--)
            {

                int len = ahead[prev + 1];
                if (prev == -1 || nums[prev] < nums[cur])
                {
                    len = max(1 + ahead[cur + 1], len);
                }
                curR[prev + 1] = len;
            }
            ahead = curR;
        }
        return ahead[0];
    }
};

//// uisng single dp for printing

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
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
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
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
        temp.push_back(nums[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        { // Follow the hash array to backtrack
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }

        reverse(temp.begin(), temp.end()); // Reverse the reconstructed sequence to correct order

        // Optional: Print the LIS for visualization
        cout << "Longest Increasing Subsequence:";
        for (int num : temp)
        {
            cout << num << " ";
        }
        cout << endl;

        return maxi; // Return the length of the LIS
    }
};

// greedy and Using lower bound approach

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int len = 1;
        vector<int> temp;

        temp.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (temp.back() < nums[i])
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};