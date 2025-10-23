class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager,
                     vector<int> &informTime)
    {
        unordered_map<int, vector<int>> node;

        for (int i = 0; i < manager.size(); i++)
            if (manager[i] != -1)
                node[manager[i]].push_back(i);

        int totalTime = 0;

        queue<pair<int, int>> q;
        q.push({headID, 0});

        while (!q.empty())
        {
            auto [cur, time] = q.front();
            q.pop();
            totalTime = max(totalTime, time);

            for (auto child : node[cur])
                q.push({child, time + informTime[cur]});
        }

        return totalTime;
    }
};