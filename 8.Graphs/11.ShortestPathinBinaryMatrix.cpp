
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // If the start or end cell is blocked, return -1 immediately.
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }

        // Directions for moving in 8 possible directions (left, right, up, down, and diagonals)
        vector<pair<int, int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};

        queue<pair<int, int>> q;                              // Queue for BFS traversal
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // Distance array initialized to INT_MAX

        q.push({0, 0}); // Start BFS from the top-left corner (0,0)
        dist[0][0] = 1; // Distance to the starting cell is 1

        while (!q.empty())
        {
            pair<int, int> cur = q.front(); // Get the current cell
            q.pop();

            int curRow = cur.first;
            int curCol = cur.second;

            // Explore all 8 possible directions
            for (auto it : offsets)
            {
                int nRow = curRow + it.first;
                int nCol = curCol + it.second;

                // Check if the new position is within bounds, not blocked, and not visited yet
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                    grid[nRow][nCol] == 0 && dist[nRow][nCol] == INT_MAX)
                {

                    dist[nRow][nCol] = dist[curRow][curCol] + 1; // Update the distance
                    q.push({nRow, nCol});                        // Push the new cell into the queue

                    // If we reached the bottom-right corner, return the shortest path length
                    if (nRow == n - 1 && nCol == n - 1)
                    {
                        return dist[nRow][nCol];
                    }

                }
            }
        }

        // If we couldn't reach the bottom-right corner, return -1
        return -1;
    }
};
