class Solution
{
private:
    // Recursive function to find the longest string chain
    int lsc(vector<string> &words, int n, int cur, int prev)
    {
        // Base case: If we've processed all words, return 0
        if (cur >= n)
        {
            return 0;
        }

        // Option 1: Skip the current word
        int noTake = lsc(words, n, cur + 1, prev);

        // Option 2: Take the current word if it's a valid predecessor
        if (prev == -1 || isPredecessor(words[prev], words[cur]))
        {
            int take = 1 + lsc(words, n, cur + 1, cur);
            return max(take, noTake);
        }

        // Return the result for this step
        return noTake;
    }

    // Function to check if `a` is a predecessor of `b`
    bool isPredecessor(const string &a, const string &b)
    {
        // A predecessor must have exactly one character difference
        if (b.size() != a.size() + 1)
        {
            return false;
        }

        int i = 0, j = 0;
        bool skipped = false;

        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                if (skipped)
                {
                    return false; // Already skipped one mismatch
                }
                skipped = true;
                j++; // Skip one character in `b`
            }
        }

        return true;
    }

public:
    int longestStrChain(vector<string> &words)
    {
        // Sort words by length to ensure chains are built correctly
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });

        int n = words.size();
        return lsc(words, n, 0, -1);
    }
};

// riteraive approach

class Solution
{
private:
    bool isPredecessor(string &s1, string &s2)
    {
        int s1Len = s1.length();
        int s2Len = s2.length();

        if (s1Len != s2Len + 1)
            return false;

        int i = 0;
        int j = 0;

        while (i < s1Len)
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (i == s1Len && j == s2Len)
            return true;
        return false;
    }

public:
    int longestStrChain(vector<string> &words)
    {

        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });

        int n = words.size();

        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < i; j++)
            {
                if (isPredecessor(words[i], words[j]) && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                }
                maxi = max(maxi, dp[i]);
            }
        }
        return maxi;
    }
};