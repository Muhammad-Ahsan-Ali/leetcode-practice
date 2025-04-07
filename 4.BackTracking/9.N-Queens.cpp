class Solution
{
public:
    // Function to check if placing a queen at (row, col) is safe
    bool canPlace(vector<string> &board, int n, int row, int col)
    {

        // Check if the column already has a queen
        for (int i = 0; i < n; i++)
        {
            if (board[row][i] == 'Q' || board[i][col] == 'Q')
            {
                return false; // If found, placement is not safe
            }
        }

        // Check upper-left diagonal (\)
        for (int i = 1; i <= min(row, col); i++)
        {
            if (board[row - i][col - i] == 'Q')
            {
                return false; // Not safe if a queen is found
            }
        }

        // Check upper-right diagonal (/)
        for (int i = 1; i <= min(row, n - col - 1); i++)
        {
            if (board[row - i][col + i] == 'Q')
            {
                return false; // Not safe if a queen is found
            }
        }

        // Check lower-left diagonal (/)
        for (int i = 1; i <= min(n - row - 1, col); i++)
        {
            if (board[row + i][col - i] == 'Q')
            {
                return false; // Not safe if a queen is found
            }
        }

        return true;
    }

    // Recursive function to solve N-Queens
    void solve(int n, vector<string> &board, int row, vector<vector<string>> &solutions)
    {
        // Base Case: If all queens are placed, store the board configuration
        if (row == n)
        {
            solutions.push_back(board);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++)
        {
            if (canPlace(board, n, row, col))
            {
                board[row][col] = 'Q';               // Place queen
                solve(n, board, row + 1, solutions); // Recurse for next row
                board[row][col] = '.';               // Backtrack
            }
        }
    }

    // Main function to solve N-Queens
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> solutions;        // Store all solutions
        vector<string> board(n, string(n, '.')); // Single board used throughout

        solve(n, board, 0, solutions); // Start solving from row 0
        return solutions;
    }
};
