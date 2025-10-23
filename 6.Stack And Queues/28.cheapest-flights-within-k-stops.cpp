class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {

        vector<vector<pair<int, int>>> adj(n);

        for (auto it : flights)
            adj[it[0]].push_back({it[1], it[2]});

        queue<pair<int, pair<int, int>>> q; // step,{dis,node}
        q.push({0, {0, src}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty())
        {
            auto [steps, dsN] = q.front();
            auto [dis, node] = dsN;
            q.pop();
            if (steps > k)
                continue;
            for (auto it : adj[node])
            {
                auto [adjN, w] = it;
                if (dis + w < dist[adjN] && steps <= k)
                {
                    dist[adjN] = dis + w;
                    q.push({steps + 1, {dist[adjN], adjN}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};