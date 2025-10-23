class Solution
{
public:
    string alphabetBoardPath(string target)
    {

        vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        unordered_map<char, pair<int, int>> mp;

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                mp[board[i][j]] = {i, j};

        // keep LDUR pattern
        string ans = "";
        int curR = 0;
        int curC = 0;
        for (auto ch : target)
        {
            auto [r, c] = mp[ch];
            int rowDif = r - curR;
            int colDif = c - curC;
            curR = r;
            curC = c;
            if (rowDif < 0)
                ans += string(abs(rowDif), 'U');
            if (colDif < 0)
                ans += string(abs(colDif), 'L');
            if (rowDif > 0)
                ans += string(abs(rowDif), 'D');
            if (colDif > 0)
                ans += string(abs(colDif), 'R');
            ans += +"!";
        }
        return ans;
    }
};

// optimal

class Solution
{
public:
    string alphabetBoardPath(string target)
    {
        string ans;
        int curR = 0, curC = 0;

        for (char ch : target)
        {
            int r = (ch - 'a') / 5; // row
            int c = (ch - 'a') % 5; // column

            // Move up first, then left
            if (r < curR)
                ans += string(curR - r, 'U');
            if (c < curC)
                ans += string(curC - c, 'L');

            // Move down, then right
            if (r > curR)
                ans += string(r - curR, 'D');
            if (c > curC)
                ans += string(c - curC, 'R');

            ans += '!';
            curR = r;
            curC = c;
        }

        return ans;
    }
};
