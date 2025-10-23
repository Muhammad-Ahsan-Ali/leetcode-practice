class Solution
{
private:
    int bfs(int start, vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;
        int count = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                    count++;
                }
            }
        }

        return count;
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        vector<vector<int>> adj;
        int n = bombs.size();
        adj.resize(n);

        // (xi​−xj​)2+(yi​−yj​)2 ≤ ri2​

        for (int i = 0; i < n; i++)
        {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];

            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                long long dx = x1 - x2;
                long long dy = y1 - y2;

                if (dx * dx + dy * dy <= r1 * 1LL * r1)
                    adj[i].push_back(j);
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
            result = max(result, bfs(i, adj));

        return result;
    }
};