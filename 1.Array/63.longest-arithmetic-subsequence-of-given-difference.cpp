class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> dp;
        int ans = 1;
        for (auto val : arr)
        { 
            dp[val] = 1 + dp[val - difference];
            ans = max(ans, dp[val]);
        }

        return ans;
    }
};