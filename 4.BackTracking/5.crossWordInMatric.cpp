bool canPlaceHorizontally(vector<vector<char>> &board, string word, int i, int j)
{
    int n = board[0].size();
    int m = word.size();
    bool leftToRight = false, rightToLeft = false;

    // Check if word can fit in left-to-right direction
    if (j + m <= n)
    {
        if ((j > 0 && board[i][j - 1] != '#') || (j + m < n && board[i][j + m] != '#'))
            leftToRight = false;
        else
        {
            leftToRight = true;
            for (int k = 0; k < m; k++)
            {
                if (board[i][j + k] != ' ' && board[i][j + k] != word[k])
                {
                    leftToRight = false;
                    break;
                }
            }
        }
    }

    // Check if word can fit in right-to-left direction
    if (j - m + 1 >= 0)
    {
        if ((j - m >= 0 && board[i][j - m] != '#') || (j < n - 1 && board[i][j + 1] != '#'))
            rightToLeft = false;
        else
        {
            rightToLeft = true;
            for (int k = 0; k < m; k++)
            {
                if (board[i][j - k] != ' ' && board[i][j - k] != word[k])
                {
                    rightToLeft = false;
                    break;
                }
            }
        }
    }

    return leftToRight || rightToLeft;
}

bool canPlaceVertically(vector<vector<char>> &board, string word, int i, int j)
{
    int n = board.size();
    int m = word.size();
    bool topToBottom = false, bottomToTop = false;

    // Check if word can fit in top-to-bottom direction
    if (i + m <= n)
    {
        if ((i > 0 && board[i - 1][j] != '#') || (i + m < n && board[i + m][j] != '#'))
            topToBottom = false;
        else
        {
            topToBottom = true;
            for (int k = 0; k < m; k++)
            {
                if (board[i + k][j] != ' ' && board[i + k][j] != word[k])
                {
                    topToBottom = false;
                    break;
                }
            }
        }
    }

    // Check if word can fit in bottom-to-top direction
    if (i - m + 1 >= 0)
    {
        if ((i - m >= 0 && board[i - m][j] != '#') || (i + 1 < n && board[i + 1][j] != '#'))
            bottomToTop = false;
        else
        {
            bottomToTop = true;
            for (int k = 0; k < m; k++)
            {
                if (board[i - k][j] != ' ' && board[i - k][j] != word[k])
                {
                    bottomToTop = false;
                    break;
                }
            }
        }
    }

    return topToBottom || bottomToTop;
}

bool placeWordInCrossword(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Check if the word can be placed horizontally or vertically
            if (board[i][j] == ' ' || board[i][j] == word[0])
            {
                if (canPlaceHorizontally(board, word, i, j) || canPlaceVertically(board, word, i, j))
                    return true;
            }
        }
    }

    return false;
}
