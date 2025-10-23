class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        unordered_map<int, vector<pair<int, int>>> list;

        for (auto node : times)
            list[node[0]].push_back({node[1], node[2]});

        vector<int> weight(n + 1, INT_MAX);

        using pi = pair<int, int>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        pq.push({0, k});
        weight[k] = 0;

        while (!pq.empty())
        {
            auto [dist, node] = pq.top();
            pq.pop();

            if (dist > weight[node])
                continue;

            for (auto &[nei, w] : list[node])
            {
                if (weight[node] + w < weight[nei])
                {
                    weight[nei] = weight[node] + w;
                    pq.push({weight[nei], nei});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if (weight[i] == INT_MAX)
                return -1;
            ans = max(ans, weight[i]);
        }

        return ans;
    }
};