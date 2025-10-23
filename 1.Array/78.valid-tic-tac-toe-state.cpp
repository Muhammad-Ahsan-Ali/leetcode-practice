class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        int cntX = 0, cntO = 0;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == 'X')
                    cntX++;
                else if (board[i][j] == 'O')
                    cntO++;

        if (cntO > cntX || cntX > cntO + 1)
            return 0;

        function<bool(char)> wins = [&](char c) -> bool
        {
            for (int i = 0; i < 3; i++)
            {
                // check rows
                if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
                    return true;
                // check columns
                if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
                    return true;
            }

            // check diagonals
            if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
                return true;
            if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
                return true;

            return false;
        };

        bool xWins = wins('X');
        bool oWins = wins('O');

        if (xWins && oWins)
            return 0;

        if (xWins && cntX != cntO + 1)
            return false;

        if (oWins && cntX != cntO)
            return false;

        return 1;
    }
};