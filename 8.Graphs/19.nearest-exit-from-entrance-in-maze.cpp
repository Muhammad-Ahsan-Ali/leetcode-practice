class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        queue<pair<pair<int, int>, int>> q;
        int n = maze.size();
        int m = maze[0].size();

        for (int i = 0; i < n; i++)
        {
            if (maze[i][0] == '.' && !(entrance[0] == i && entrance[1] == 0))
            {
                maze[i][0] = '+';
                q.push({{i, 0}, 0});
            }

            if (maze[i][m - 1] == '.' &&
                !(entrance[0] == i && entrance[1] == m - 1))
            {
                maze[i][m - 1] = '+';
                q.push({{i, m - 1}, 0});
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (maze[0][i] == '.' && !(entrance[0] == 0 && entrance[1] == i))
            {
                maze[0][i] = '+';
                q.push({{0, i}, 0});
            }

            if (maze[n - 1][i] == '.' &&
                !(entrance[0] == n - 1 && entrance[1] == i))
            {
                maze[n - 1][i] = '+';
                q.push({{n - 1, i}, 0});
            }
        }

        vector<int> rof = {1, 0, -1, 0};
        vector<int> cof = {0, -1, 0, 1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            auto [r, c] = it.first;
            int dist = it.second;

            for (int i = 0; i < 4; i++)
            {
                int nr = r + rof[i];
                int nc = c + cof[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    maze[nr][nc] == '.')
                {
                    maze[nr][nc] = '+';
                    if (nr == entrance[0] && nc == entrance[1])
                        return dist + 1;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }
        return -1;
    }
};