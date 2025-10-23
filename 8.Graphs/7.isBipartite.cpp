class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int r = graph.size();       // Get the number of nodes in the graph
        vector<int> colored(r, -1); // Initialize a color array with -1 (unvisited)
        queue<int> q;               // Queue for BFS traversal

        // Iterate through all nodes (to handle disconnected graphs)
        for (int i = 0; i < r; i++)
        {
            if (colored[i] == -1) // If the node is uncolored, start BFS
            {
                colored[i] = 0; // Assign the first color (0)
                q.push(i);      // Push the node into the queue

                while (!q.empty()) // BFS loop
                {
                    int node = q.front(); // Get the front node
                    q.pop();              // Remove it from the queue

                    // Traverse all adjacent nodes
                    for (auto it : graph[node])
                    {
                        if (colored[it] == -1) // If the neighbor is uncolored
                        {
                            colored[it] = !colored[node]; // Color it with the opposite color
                            q.push(it);                   // Push it into the queue for further processing
                        }
                        else if (colored[it] == colored[node]) // If adjacent nodes have the same color
                        {
                            return false; // Graph is not bipartite
                        }
                    }

                }
            }
        }

        return true; // If all nodes are properly colored, the graph is bipartite
    }
};
