class Solution
{
private:
    vector<int> lds(int n, int cur, int prev, vector<int> &nums)
    {
        if (cur >= n)
        {
            return {};
        }

        vector<int> exclude = lds(n, cur + 1, prev, nums);
        vector<int> include;

        if (prev == -1 || (nums[cur] % nums[prev] == 0))
        {
            include = lds(n, cur + 1, cur, nums);
            include.push_back(nums[cur]);
        }

        return include.size() > exclude.size() ? include : exclude;
    }

public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return lds(nums.size(), 0, -1, nums);
    }
};

//................

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>()));
        sort(nums.begin(), nums.end());

        for (int cur = n - 1; cur >= 0; cur--)
        {
            for (int prev = cur - 1; prev >= -1; prev--)
            {

                vector<int> exclude = dp[cur + 1][prev + 1];

                vector<int> include;

                if (prev == -1 || (nums[cur] % nums[prev] == 0))
                {
                    include = dp[cur + 1][cur + 1];
                    include.push_back(nums[cur]);
                }

                dp[cur][prev + 1] = include.size() > exclude.size() ? include : exclude;
            }
        }

        reverse(dp[0][0].begin(), dp[0][0].end());

        return dp[0][0];
    }
};

//................

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> ahead(n + 1, vector<int>());

        sort(nums.begin(), nums.end());

        for (int cur = n - 1; cur >= 0; cur--)
        {
            vector<vector<int>> curR(n + 1, vector<int>());
            for (int prev = cur - 1; prev >= -1; prev--)
            {
                vector<int> exclude = ahead[prev + 1];

                vector<int> include;
                if (prev == -1 || (nums[cur] % nums[prev] == 0))
                {
                    include = ahead[cur + 1];
                    include.push_back(nums[cur]);
                }
                if (include.size() > exclude.size())
                {
                    curR[prev + 1] = include;
                }
                else
                {
                    curR[prev + 1] = exclude;
                }
            }
            ahead = curR;
        }
        reverse(ahead[0].begin(), ahead[0].end());
        return ahead[0];
    }
};

///.............

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> len(n, 1), hash(n);

        int maxi = 1;
        int lstInd = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if ((nums[i] % nums[prev] == 0) && 1 + len[prev] > len[i])
                {
                    len[i] = 1 + len[prev];
                    hash[i] = prev;
                }

                if (len[i] > maxi)
                {
                    maxi = len[i];
                    lstInd = i;
                }
            }
        }

        vector<int> lds;

        lds.push_back(nums[lstInd]);

        while (hash[lstInd] != lstInd)
        {
            lstInd = hash[lstInd];
            lds.push_back(nums[lstInd]);
        }

        reverse(lds.begin(), lds.end());

        return lds;
    }
};