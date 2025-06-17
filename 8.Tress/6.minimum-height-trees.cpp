class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {

        if (n == 1)
            return {0};

        vector<int> indeg(n);
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            indeg[u]++;
            indeg[v]++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 1)
                q.push(i);
        }

        while (n > 2)
        {
            int sz = q.size();
            n -= sz;
            while (sz--)
            {
                int u = q.front();
                q.pop();
                for (auto &v : adj[u])
                {
                    indeg[v]--;
                    if (indeg[v] == 1)
                        q.push(v);
                }
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};