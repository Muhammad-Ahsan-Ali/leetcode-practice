#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceHorizontally(vector<vector<char>> &board, string word, int i, int j)
{
    int n = board[0].size();
    int m = word.size();

    // Check if word can fit in left-to-right direction
    if (j + m <= n)
    {
        // Check boundaries
        if ((j > 0 && board[i][j - 1] != '#') || (j + m < n && board[i][j + m] != '#'))
            return false;
        // Match or place word
        for (int k = 0; k < m; k++)
        {
            if (board[i][j + k] != ' ' && board[i][j + k] != word[k])
                return false;
        }
        return true;
    }

    // Check if word can fit in right-to-left direction
    if (j - m + 1 >= 0)
    {
        // Check boundaries
        if ((j - m >= 0 && board[i][j - m] != '#') || (j < n - 1 && board[i][j + 1] != '#'))
            return false;
        // Match or place word
        for (int k = 0; k < m; k++)
        {
            if (board[i][j - k] != ' ' && board[i][j - k] != word[k])
                return false;
        }
        return true;
    }

    return false;
}

bool canPlaceVertically(vector<vector<char>> &board, string word, int i, int j)
{
    int n = board.size();
    int m = word.size();

    // Check if word can fit in top-to-bottom direction
    if (i + m <= n)
    {
        // Check boundaries
        if ((i > 0 && board[i - 1][j] != '#') || (i + m < n && board[i + m][j] != '#'))
            return false;
        // Match or place word
        for (int k = 0; k < m; k++)
        {
            if (board[i + k][j] != ' ' && board[i + k][j] != word[k])
                return false;
        }
        return true;
    }

    // Check if word can fit in bottom-to-top direction
    if (i - m + 1 >= 0)
    {
        // Check boundaries
        if ((i - m >= 0 && board[i - m][j] != '#') || (i < n - 1 && board[i + 1][j] != '#'))
            return false;
        // Match or place word
        for (int k = 0; k < m; k++)
        {
            if (board[i - k][j] != ' ' && board[i - k][j] != word[k])
                return false;
        }
        return true;
    }

    return false;
}

bool placeWordInCrossword(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();

    string reversedWord = word;
    reverse(reversedWord.begin(), reversedWord.end());

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Check if the word can be placed horizontally or vertically
            if (board[i][j] == ' ' || board[i][j] == word[0])
            {
                if (canPlaceHorizontally(board, word, i, j) || canPlaceHorizontally(board, reversedWord, i, j) ||
                    canPlaceVertically(board, word, i, j) || canPlaceVertically(board, reversedWord, i, j))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board = {{'#', ' ', '#'},
                                  {' ', ' ', '#'},
                                  {'#', 'c', ' '}};

    string word = "abc";
    cout << placeWordInCrossword(board, word);

    return 0;
}