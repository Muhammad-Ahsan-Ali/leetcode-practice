class Solution
{
public:
    int lcsHelper(string &text1, string &text2, int i, int j)
    {
        if (i < 0 || j < 0)
            return 0; // Base case: Empty string

        if (text1[i] == text2[j])
        {
            return 1 + lcsHelper(text1, text2, i - 1, j - 1);
        }
        else
        {
            return max(lcsHelper(text1, text2, i - 1, j), lcsHelper(text1, text2, i, j - 1));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        return lcsHelper(text1, text2, text1.size() - 1, text2.size() - 1);
    }
};

//...............
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            vector<int> cur(m + 1, INT_MIN);
            cur[0] = 0;
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
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

        return prev[m];
    }
};