class Solution
{
public:
    int lcsHelper(string &s, string &rev, int i, int j)
    {
        if (i < 0 || j < 0)
            return 0; // Base case: Empty string

        if (s[i] == rev[j])
        {
            return 1 + lcsHelper(s, rev, i - 1, j - 1);
        }
        else
        {
            return max(lcsHelper(s, rev, i - 1, j), lcsHelper(s, rev, i, j - 1));
        }
    }

    int minInsertions(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end()); // Get reversed string

        int lcsLength = lcsHelper(s, rev, s.size() - 1, rev.size() - 1);

        return s.size() - lcsLength; // Min insertions needed
    }
};

//.......
class Solution
{
public:
    int minInsertions(string s)
    {
        int len = s.length();
        string reverse(len, '\0');

        if (len == 0 || len == 1)
        {
            return 0;
        }

        for (int i = 0; i < len; i++)
        {
            reverse[len - i - 1] = s[i];
        }

        vector<int> prev(len + 1, 0);

        for (int i = 1; i <= len; i++)
        {
            vector<int> cur(len + 1, INT_MIN);
            cur[0] = 0;
            for (int j = 1; j <= len; j++)
            {
                if (s[i - 1] == reverse[j - 1])
                {
                    cur[j] = 1 + prev[j - 1];
                }
                else
                {
                    cur[j] = 0 + max(prev[j], cur[j - 1]);
                }
            }
            prev = cur;
        }

        int lcp = prev[len];

        return len - lcp;
    }
};