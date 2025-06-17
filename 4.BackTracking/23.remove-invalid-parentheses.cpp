class Solution
{
public:
    bool isValidExpression(string s)
    {
        int track = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                track++;
            }
            else if (c == ')')
            {
                track--;
            }
            if (track < 0)
            {
                return false; // More closing than opening brackets at some point
            }
        }

        return track == 0; // True only if all brackets are balanced
    }

    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> visited; // To store the visited strings
        queue<string> q;               // To perform BFS
        vector<string> result;         // To store valid results
        bool found = false;

        // Start BFS with the original string
        q.push(s);
        visited.insert(s);

        while (!q.empty())
        {
            string curr = q.front();
            q.pop();

            // If current string is valid, add it to the result
            if (isValidExpression(curr))
            {
                result.push_back(curr);
                found = true; // We found at least one valid expression
            }

            // If we have found valid expressions at the current level, stop further removals
            if (found)
                continue;

            // Generate all possible strings by removing one parenthesis at each position
            for (int i = 0; i < curr.length(); i++)
            {
                if (curr[i] != '(' && curr[i] != ')')
                    continue;

                string next = curr.substr(0, i) + curr.substr(i + 1); // Remove the i-th character

                if (visited.find(next) == visited.end())
                {
                    q.push(next);
                    visited.insert(next); // Mark this string as visited
                }
            }
        }

        return result;
    }
};