class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDegree(numCourses, 0); // Stores the in-degree (number of prerequisites) for each course
        unordered_map<int, vector<int>> adj; // Adjacency list representation of the graph
        queue<int> q;                        // Queue for processing courses with zero prerequisites
        int cnt = 0;                         // Counter to track the number of courses that can be completed

        // Construct the adjacency list from prerequisites
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            // Add an edge from prerequisite to the dependent course
        }

        // Compute in-degrees for each course
        for (auto it : adj)
        {
            for (int node : adj[it.first])
            {
                inDegree[node]++;
                // Increase in-degree for courses that have prerequisites
            }
        }

        // Add all courses with zero in-degree (no prerequisites) to the queue
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Process courses in topological order
        while (!q.empty())
        {
            int node = q.front(); // Get the current course
            q.pop();              // Remove it from the queue
            cnt++;                // Increase the count of completed courses

            // Reduce indegree for all dependent courses
            for (int ngber : adj[node])
            {
                inDegree[ngber]--;
                if (inDegree[ngber] == 0)
                { // If in-degree becomes zero, add it to the queue
                    q.push(ngber);
                }
            }
        }

        // If we were able to process all courses, return true; otherwise, return false
        if (cnt == numCourses)
            return true;

        return false;
    }
};
