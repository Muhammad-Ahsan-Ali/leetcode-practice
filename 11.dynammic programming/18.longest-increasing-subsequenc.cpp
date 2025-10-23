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

// 🔎 Explanation of the tricky part:

// dp[cur][prev+1] = LIS length if we are at index cur and last chosen index is prev.

// Why prev+1? Because prev can be -1 (no element chosen yet). Shifting by +1 makes it valid as an array index.

// Transition:

// Skip current element → move to cur+1 without changing prev.

// Take current element → only allowed if nums[prev] < nums[cur] → then 1 + dp[cur+1][cur+1].

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