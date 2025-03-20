 
bool search(int i, int j, vector<vector<char>> &board, string word, int index)
{

    if (index == word.size())
    {
        return true;
    }

    if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[index])
    {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = search(i + 1, j, board, word, index + 1) || // down
                 search(i - 1, j, board, word, index + 1) || // up
                 search(i, j + 1, board, word, index + 1) || // right
                 search(i, j - 1, board, word, index + 1);   // left

    board[i][j] = temp;

    return found;
}

bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == word[0])
            {
                if (search(i, j, board, word, 0))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
 