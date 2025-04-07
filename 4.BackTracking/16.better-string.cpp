
class Solution
{
private:
    int countDistinctSubsequences(string &s)
    {
        int n = s.length();
        unordered_map<char, int> lastInd;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 2 * dp[i - 1];
            if (lastInd.find(s[i - 1]) != lastInd.end())
            {
                dp[i] = dp[i] - dp[lastInd[s[i - 1]] - 1];
            }
            lastInd[s[i - 1]] = i;
        }

        return dp[n];
    }

public:
    string betterString(string s1, string s2)
    {
        // code here
        int count1 = countDistinctSubsequences(s1);
        int count2 = countDistinctSubsequences(s2);

        return count1 >= count2 ? s1 : s2;
    }
};