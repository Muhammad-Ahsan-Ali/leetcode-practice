class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {

        using T = pair<int, pair<int, int>>;
        priority_queue<T, vector<T>, greater<T>> pq;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        pq.push({0, {0, 0}});

        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
23.
            if (r == n - 1 && c == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m)
                {
                    int newEffort =
                        max(abs(heights[nr][nc] - heights[r][c]), diff);
                    if (newEffort < dist[nr][nc])
                    {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};

// O(m*n log(m*n))
// O(m*n) space