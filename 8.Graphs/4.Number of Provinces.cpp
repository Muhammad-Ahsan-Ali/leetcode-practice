class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        queue<int> q;
        vector<bool> visited(isConnected.size(), false);
        int provinces = 0;
        int n = isConnected.size();

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                provinces++;
                q.push(i);

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    visited[node] = true;

                    for (int j = 0; j < n; j++)
                    {
                        if (!visited[j] && isConnected[node][j] == 1)
                        {
                            q.push(j);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};
