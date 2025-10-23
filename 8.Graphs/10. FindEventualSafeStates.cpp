class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        unordered_map map<int, vector<int>> adjRev;
        vector<int> safeNode;
        queue<int> q;

        for (int i = 0; i < graph.size(); i++)
        {
            for (auto it : graph[i])
            {
                adjRev[it].push_back(i);
            }
        }

        vector<int> inDegree(graph.size(), 0);

        for (auto it : adjRev)
        {
            for (int node : adjRev[it.first])
            {
                inDegree[node]++;
            }
        }

        for (int i = 0; i < inDegree.size(); i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNode.push_back(node);

            for (int it : adjRev[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        sort(safeNode.begin(), safeNode.end());
        return safeNode;
    }
};
