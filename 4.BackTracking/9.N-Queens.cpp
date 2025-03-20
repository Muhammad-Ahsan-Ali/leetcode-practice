#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool canPlace(vector<vector<char>> board, int n, char c, int row, int col)
{
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == c || board[i][col] == c)
        {
            return false;
        }
    }

    for (int i = 1; i <= min(row, col); i++)
    {
        if (board[row - i][col - i] == c)
        {
            return false;
        }
    }

    for (int i = 1; i <= min(row, n - col - 1); i++)
    {
        if (board[row - i][col + i] == c)
        {
            return false;
        }
    }

    for (int i = 1; i <= min(n - row - 1, col); i++)
    {
        if (board[row + i][col - i] == c)
        {
            return false;
        }
    }

    return true;
}

void sol(int n, vector<vector<char>> &board, int row, vector<vector<string>> &output)
{
    if (row == n)
    {
        vector<string> solution;
        for (int i = 0; i < n; i++)
        {
            string rowString;
            for (int j = 0; j < n; j++)
            {
                rowString.push_back(board[i][j]);
            }
            solution.push_back(rowString);
        }
        output.push_back(solution);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == '.')
        {
            char c = 'Q';
            if (canPlace(board, n, c, row, j))
            {
                board[row][j] = c;

                sol(n, board, row + 1, output);

                board[row][j] = '.';
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> output;

    vector<vector<char>> board(n, vector<char>(n, '.'));

    sol(n, board, 0, output);

    return output;
}

int main()
{
    int n = 4;
    solveNQueens(n);

    return 0;
}