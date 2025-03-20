class Solution
{
public:
    int minDistanceHelper(string &word1, string &word2, int i, int j)
    {
        // Base cases
        if (i < 0)
            return j + 1; // Delete remaining chars of word2
        if (j < 0)
            return i + 1; // Delete remaining chars of word1

        if (word1[i] == word2[j])
        {
            return minDistanceHelper(word1, word2, i - 1, j - 1);
        }
        else
        {
            int deleteFromWord1 = 1 + minDistanceHelper(word1, word2, i - 1, j);
            int deleteFromWord2 = 1 + minDistanceHelper(word1, word2, i, j - 1);
            return min(deleteFromWord1, deleteFromWord2);
        }
    }

    int minDistance(string word1, string word2)
    {
        return minDistanceHelper(word1, word2, word1.size() - 1, word2.size() - 1);
    }
};

//..........
class Solution
{
public:
    int minDistance(string word1, string word2)
    {

        int n = word1.size();
        int m = word2.size();

        if (n == 0 && m == 0)
            return 0;
        if (n == 0)
        {
            return m;
        }
        else if (m == 0)
        {
            return n;
        }

        vector<int> prev(m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            vector<int> cur(m + 1, INT_MIN);
            cur[0] = 0;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
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
        // The minimum deletions required = Total length - 2 * LCS
        return (m + n) - (2 * prev[m]);
    }
};