class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adj;
        vector<int> indeg(numCourses, 0);
        queue<int> q;

        for (auto prerequisite : prerequisites)
            adj[prerequisite[1]].push_back(prerequisite[0]);

        for (auto it : adj)
            for (auto nodes : adj[it.first])
                indeg[nodes]++;

        for (int i = 0; i < numCourses; i++)
            if (indeg[i] == 0)
                q.push(i);

        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto neibr : adj[node])
            {
                indeg[neibr]--;
                if (indeg[neibr] == 0)
                    q.push(neibr);
            }
        }

        return ans.size() == numCourses ? ans : vector<int>{};
    }
};