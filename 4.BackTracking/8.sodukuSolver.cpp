#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

bool canPlace(vector<vector<char>> board, char c, int row, int col)
{
    // check horizentaly and vertically
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == c || board[i][col] == c)
        {
            return false;
        }
    }
    int effectRow;
    int effectCol;

    if (row < 3)
    {
        effectRow = 3;
    }
    else if (row < 6)
    {
        effectRow = 6;
    }
    else
    {
        effectRow = 9;
    }
    if (col < 3)
    {
        effectCol = 3;
    }
    else if (col < 6)
    {
        effectCol = 6;
    }
    else
    {
        effectCol = 9;
    }

    for (int i = effectRow - 3; i < effectRow; i++)
    {
        for (int j = effectCol - 3; j < effectCol; j++)
        {
            if (board[i][j] == c)
            {
                return false;
            }
        }
    }
    return true;
}

bool sol(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (canPlace(board, c, i, j))
                    {
                        board[i][j] = c;

                        if (sol(board))
                        {
                            return true; // If solving the rest is successful, return true
                        }

                        board[i][j] = '.'; // Reset the cell (backtrack)
                    }
                }
                return false; // If noAA valid number can be placed, return false
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    sol(board);
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);
    return 0;
}