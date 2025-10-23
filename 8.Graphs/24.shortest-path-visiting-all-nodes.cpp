class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int allVis = (1 << n) - 1;
        vector<vector<int>> dist(n, vector<int>(1 << n, INT_MAX));
        queue<pair<int, int>> q; // cur, mask

        for (int i = 0; i < n; i++)
        {
            q.push({i, 1 << i});
            dist[i][1 << i] = 0;
        }

        while (!q.empty())
        {
            auto [cur, mask] = q.front();
            q.pop();
            int d = dist[cur][mask];
            if (mask == allVis)
                return d;

            for (auto neig : graph[cur])
            {
                int nMsk = mask | (1 << neig);
                if (dist[neig][nMsk] > d + 1)
                {
                    dist[neig][nMsk] = d + 1;
                    q.push({neig, nMsk});
                }
            }
        }

        return -1;
    }
};