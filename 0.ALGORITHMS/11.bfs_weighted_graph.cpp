int bfs(unordered_map<int, vector<pair<int, int>>> &adj, int trgtN)
{
    queue<pair<int, int>> q;

    q.push({1, 0});
    int ans = INT_MAX;
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        if (node.first == trgtN)
        {
            return node.second;
        }

        for (auto &&child : adj[node.first])
        {
            int cost = node.second + child.second;
            q.push({child.first, cost});
        }
    }
    return 0;
}