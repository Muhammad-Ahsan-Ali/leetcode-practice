class Solution
{
    int dp[1001][1001];

public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {

        memset(dp, -1, sizeof(dp));

        auto sol = [&](auto &&sol, int i, int remWidth, int curRowHght) -> int
        {
            if (i == books.size())
                return curRowHght;

            if (dp[i][remWidth] != -1)
                return dp[i][remWidth];

            int pick = INT_MAX;
            int skipRow = INT_MAX;

            if (books[i][0] <= remWidth)
                pick = sol(sol, i + 1, remWidth - books[i][0],
                           max(curRowHght, books[i][1]));

            skipRow = curRowHght +
                      sol(sol, i + 1, shelfWidth - books[i][0], books[i][1]);
            return dp[i][remWidth] = min(pick, skipRow);
        };
        return sol(sol, 0, shelfWidth, 0);
    }
};

// antoher approach

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        vector<int> dp(n, -1);

        auto sol = [&](auto &&sol, int i) -> int
        {
            if (i == n)
                return 0;
            if (dp[i] != -1)
                return dp[i];

            int width = 0, height = 0, minHeight = INT_MAX;

            for (int j = i; j < n; ++j)
            {
                width += books[j][0];
                if (width > shelfWidth)
                    break;

                height = max(height, books[j][1]);
                minHeight = min(minHeight, height + sol(sol, j + 1));
            }

            return dp[i] = minHeight;
        };

        return sol(sol, 0);
    }
};

// optimized

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        vector<int> dp(n + 1, 0); // dp[i] = min height for books[i..n-1]

        for (int i = n - 1; i >= 0; i--)
        {
            int width = 0, height = 0, minHeight = INT_MAX;

            for (int j = i; j < n; ++j)
            {
                width += books[j][0];
                if (width > shelfWidth)
                    break;

                height = max(height, books[j][1]);
                minHeight = min(minHeight, height + dp[j + 1]);
            }

            dp[i] = minHeight;
        }

        return dp[0];
    }
};
