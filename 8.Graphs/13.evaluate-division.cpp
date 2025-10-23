class Solution
{
private:
    void dfs(string src, string dest, double &ans, double product, unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &visited)
    {
        if (visited.contains(src))
            return;

        visited.insert(src);

        if (src == dest)
        {
            ans = product;
            return;
        }

        for (auto &p : adj[src])
        {
            string next = p.first;
            double val = p.second;
            dfs(next, dest, ans, product * val, adj, visited);
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        unordered_map<string, vector<pair<string, double>>> adj;
        int n = equations.size();

        for (int i = 0; i < n; i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> res;
        for (auto &query : queries)
        {
            string src = query[0];
            string dest = query[1];

            double ans = -1.0;
            double product = 1.0;

            unordered_set<string> visited;

            if (adj.contains(src) && adj.contains(dest))
            {
                dfs(src, dest, ans, product, adj, visited);
            }
            res.push_back(ans);
        }

        return res;
    }
};
