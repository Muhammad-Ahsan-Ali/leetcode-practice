class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cnt = 0;
                for (int I = max(0, i - 1); I < min(n, i + 2); I++)
                {
                    for (int J = max(0, j - 1); J < min(m, j + 2); J++)
                    {
                        if (I == i && J == j)
                            continue;
                        if (board[I][J] == 1 || board[I][J] == 2)
                            cnt++;
                    }
                }
                if (board[i][j] == 1)
                {
                    if (cnt > 3 || cnt < 2)
                        board[i][j] = 2;
                }
                else
                {
                    if (cnt == 3)
                        board[i][j] = 3;
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] %= 2;
    }
};