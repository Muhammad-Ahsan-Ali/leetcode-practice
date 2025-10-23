class Solution
{
public:
    int minDistanceHelper(string &word1, string &word2, int i, int j)
    {
        // Base cases
        if (i == 0)
            return j; // If word1 is empty, insert all remaining characters of word2
        if (j == 0)
            return i; // If word2 is empty, delete all remaining characters of word1

        // If characters match, move to the next pair
        if (word1[i - 1] == word2[j - 1])
        {
            return minDistanceHelper(word1, word2, i - 1, j - 1);
        }

        // If characters don't match, try insert, delete, and replace operations
        else
        {
            int replaceOp = minDistanceHelper(word1, word2, i - 1, j - 1); // Replace
            int deleteOp = minDistanceHelper(word1, word2, i - 1, j);      // Delete
            int insertOp = minDistanceHelper(word1, word2, i, j - 1);      // Insert
            return 1 + min({insertOp, deleteOp, replaceOp});
        }
    }

    int minDistance(string word1, string word2)
    {
        return minDistanceHelper(word1, word2, word1.size(), word2.size());
    }
};

//............
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

        int mod = 1e9 + 7;

        vector<long long> prev(m + 1, INT_MAX);

        for (int j = 0; j <= m; j++)
        {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            vector<long long> cur(m + 1, INT_MAX);
            cur[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    cur[j] = prev[j - 1];
                }
                else
                {
                    cur[j] =
                        min({1 + prev[j - 1], 1 + prev[j], 1 + cur[j - 1]});
                }
            }
            prev = cur;
        }

        return (int)prev[m];
    }
};