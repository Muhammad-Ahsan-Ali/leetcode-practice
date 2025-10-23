class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        using ull = unsigned long long;
        vector<ull> dp(target + 1, ULLONG_MAX);

        function<ull(int)> sol = [&](int tar) -> ull
        {
            if (tar == 0)
                return 1;
            if (dp[tar] != ULLONG_MAX)
                return dp[tar];

            ull ans = 0;
            for (int num : nums)
            {
                if (tar >= num)
                    ans += sol(tar - num);
            }
            return dp[tar] = ans;
        };

        return static_cast<int>(sol(target));
    }
};


//