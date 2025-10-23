/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oBUpyPZ08zU
    Company Tags                : Amazon, Google, IBM, MAQ Software, Microsoft, Walmart, Zoho
    Leetcode Question Link      : https://leetcode.com/problems/word-break/
    NOTE :  SCROLL DOWN TO SEE JAVA VERSION AS WELL
*/

//***********************************************   C++   ***********************************************************//
// Approach-1 (Recur + Memoiz) -
// T.C :  O(n * 2^n) Because at each index, we eaither split it or not and substr also takes O(n)
class Solution
{
public:
    unordered_set<string> st;
    int t[301];
    int n;

    bool solve(string &s, int idx)
    {
        if (idx == n)
        {
            return true;
        }

        if (st.find(s.substr(idx, n - idx)) != st.end())
        {
            return true;
        }

        if (t[idx] != -1)
            return t[idx];

        for (int l = 1; l <= n; l++)
        {
            string temp = s.substr(idx, l);
            if (st.find(temp) != st.end() && solve(s, idx + l))
                return t[idx] = true;
        }

        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        n = s.length();

        memset(t, -1, sizeof(t));

        for (string &word : wordDict)
        {
            st.insert(word);
        }

        return solve(s, 0);
    }
};

// Approach-2 (Bottom Up DP)
class Solution
{
public:
    bool solve(string s, vector<string> &wordDict)
    {
        unordered_set<string> st(begin(wordDict), end(wordDict));
        int n = s.length();
        vector<bool> t(n + 1, false);

        t[0] = true; // string of length 0 is always true

        for (int i = 1; i <= n; i++)
        {
            // we choose different point (j) to break
            for (int j = 0; j < i; j++)
            {
                string temp = s.substr(j, i - j);

                if (st.count(temp) && t[j])
                {
                    t[i] = true;
                    break;
                }
            }
        }
        return t[n]; // length n
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        return solve(s, wordDict);
    }
};

// optimized dp
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        int n = s.length();
        vector<bool> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (auto &w : wordDict)
            {
                int start = i - w.length();

                if (start >= 0 && dp[start] && s.substr(start, w.length()) == w)
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

// actual recursion for this
class Solution
{
private:
    vector<int> dp;
    bool wordBreakHelper(string &s, vector<string> &wordDict, int n)
    {
        // Base case: empty string can always be segmented
        if (n == 0)
            return true;

        // If already computed, return the result
        if (dp[n] != -1)
            return dp[n];

        // Try every word in the dictionary
        for (auto &w : wordDict)
        {
            int start = n - w.length();
            if (start >= 0 && s.substr(start, w.length()) == w)
            {
                // Recur for the prefix
                if (wordBreakHelper(s, wordDict, start))
                {
                    dp[n] = 1; // Mark this position as true
                    return true;
                }
            }
        }

        // If no word matches, mark as false
        dp[n] = 0;
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();
        dp.assign(n + 1, -1); // Initialize DP with -1 (uncomputed)
        dp[0] = 1;            // Base case: empty string
        return wordBreakHelper(s, wordDict, n);
    }
};