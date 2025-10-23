class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int numRow = grid.size();
        int numCol = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;

        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0)
            return 0;

        vector<int> rowOffset = {-1, 0, 1, 0};
        vector<int> colOffset = {0, -1, 0, 1};
        int time = 0;

        while (!q.empty())
        {
            int qSize = q.size();
            bool hasRotted = false;

            for (int i = 0; i < qSize; i++)
            {

                pair<int, int> ind = q.front();
                q.pop();
                int currRow = ind.first;
                int currCol = ind.second;

                for (int j = 0; j < 4; j++)
                {
                    int adjRow = currRow + rowOffset[j];
                    int adjCol = currCol + colOffset[j];

                    if (adjRow >= 0 && adjRow < numRow && adjCol >= 0 &&
                        adjCol < numCol && grid[adjRow][adjCol] == 1)
                    {
                        grid[adjRow][adjCol] = 2;
                        q.push({adjRow, adjCol});
                        freshCount--;
                        hasRotted = true;
                    }
                }
            }

            if (hasRotted)
                time++;
        }

        return (freshCount == 0) ? time : -1;
    }
};