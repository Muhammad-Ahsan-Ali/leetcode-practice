class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int sz = strs.size();

        vector<int> cntOne(sz, 0);
        vector<int> cntZero(sz, 0);

        for (int i = 0; i < sz; i++)
            for (auto c : strs[i])
                if (c == '1')
                    cntOne[i]++;
                else
                    cntZero[i]++;

        vector<vector<vector<int>>> dp(
            sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        function<int(int, int, int)> sol = [&](int i, int rm, int rn) -> int
        {
            if (i == sz || !rm && !rn)
                return 0;

            if (dp[i][rm][rn] != -1)
                return dp[i][rm][rn];

            int curOnes = cntOne[i];
            int curZeros = cntZero[i];

            int take = 0;
            if (rm >= curZeros && rn >= curOnes)
                take = 1 + sol(i + 1, rm - curZeros, rn - curOnes);
            int noTake = sol(i + 1, rm, rn);

            return dp[i][rm][rn] = max(take, noTake);
        };

        return sol(0, m, n);
    }
};

// bottom up

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int sz = strs.size();

        vector<int> cntOne(sz, 0);
        vector<int> cntZero(sz, 0);

        for (int i = 0; i < sz; i++)
            for (auto c : strs[i])
                if (c == '1')
                    cntOne[i]++;
                else
                    cntZero[i]++;

        vector<vector<vector<int>>> dp(
            sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = sz - 1; i >= 0; i--)
        {
            for (int rm = 0; rm <= m; rm++)
            {
                for (int rn = 0; rn <= n; rn++)
                {

                    int curOnes = cntOne[i];
                    int curZeros = cntZero[i];

                    int take = 0;
                    if (rm >= curZeros && rn >= curOnes)
                        take = 1 + dp[i + 1][rm - curZeros][rn - curOnes];
                    int noTake = dp[i + 1][rm][rn];

                    dp[i][rm][rn] = max(take, noTake);
                }
            }
        }

        return dp[0][m][n];
    }
};

// optimization

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int sz = strs.size();

        vector<int> cntOne(sz, 0);
        vector<int> cntZero(sz, 0);

        for (int i = 0; i < sz; i++)
            for (auto c : strs[i])
                if (c == '1')
                    cntOne[i]++;
                else
                    cntZero[i]++;

        vector<vector<int>> ahead(vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = sz - 1; i >= 0; i--)
        {
            vector<vector<int>> cur(vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
            for (int rm = 0; rm <= m; rm++)
            {
                for (int rn = 0; rn <= n; rn++)
                {

                    int curOnes = cntOne[i];
                    int curZeros = cntZero[i];

                    int take = 0;
                    if (rm >= curZeros && rn >= curOnes)
                        take = 1 + ahead[rm - curZeros][rn - curOnes];
                    int noTake = ahead[rm][rn];

                    cur[rm][rn] = max(take, noTake);
                }
            }
            ahead = cur;
        }

        return ahead[m][n];
    }
};

// another appraoch

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto &s : strs)
        {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;
            for (int i = m; i >= zeros; i--)
            {
                for (int j = n; j >= ones; j--)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                } 
            }
        }
        return dp[m][n];
    }
};
