class Solution
{
private:
    int mcst(vector<int> &cuts, int i, int j)
    {

        if (i > j)
        {
            return 0;
        }

        int mini = 1e9;

        for (int k = i; k <= j; k++)
        {
            int cost = (cuts[j + 1] - cuts[i - 1]) + mcst(cuts, i, k - 1) + mcst(cuts, k + 1, j);
            mini = min(mini, cost);
        }

        return mini;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        int size = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        return mcst(cuts, 1, size);
    }
};

// Tabulation
class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        int size = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));

        for (int i = size; i >= 1; i--)
        {
            for (int j = i; j <= size; j++)
            {
                int mini = 1e9;
                for (int k = i; k <= j; k++)
                {
                    int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] +
                               dp[k + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][size];
    }
};