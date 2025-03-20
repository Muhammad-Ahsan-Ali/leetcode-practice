
class Solution {
private:
    void dfsSavr(vector<vector<bool>>& saved, vector<vector<char>>& board,
                 int curR, int curC) {
        if (board[curR][curC] != 'O')
            return;

        saved[curR][curC] = true;
        vector<int> rOffset = {1, 0, -1, 0};
        vector<int> cOffset = {0, 1, 0, -1};

        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < 4; i++) {
            nexR = curR + rOffset[i];
            nexC = curC + cOffset[i];
            if (nexR >= 0 && nexC >= 0 && nexR < r && nexC < c) {
                dfsSavr(saved, board, nexR, nexC);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int r = board.size();
        int c = board[0].size();

        vector<vector<bool>> saved(r, vector<bool>(c, false))

            for (int i = 0; i < r; i++) {
            if (board[i][0] == 'O') {
                dfsSavr(saved, board, i, 0);
            }
            if (board[i][c - 1] == 'O') {
                dfsSavr(saved, board, i, c - 1);
            }
        }

        for (int i = 0; i < c; i++) {
            if (board[0][i] == 'O') {
                dfsSavr(saved, board, 0, i);
            }

            if (board[r - 1][i] == 'O') {
                dfsSavr(saved, board, r - 1, i);
            }
        }

        for (int i = 0; i < r; i++) {

            for (int j = 0; j < c; j++) {
                if (!saved[i][j]) {
                    board[i][j] == 'x';
                }
            }
        }
    }
};