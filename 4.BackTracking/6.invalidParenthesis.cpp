
bool isValidExpression(string s)
{
    int track = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            track++;
        }
        if (s[i] == ')')
        {
            track--;
        }
        if (track < 0)
        {
            return false;
        }
    }

    if (track == 0)
    {
        return true;
    }
    return false;
}

int invalidBrackets(string s)
{
    int count = 0;
    int track = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            track++;
        }
        if (s[i] == ')')
        {
            track--;
        }
        if (track < 0)
        {
            track++;
            count++;
        }
    }
    count += track;
    return count;
}

bool isValid(string temp, string s)
{

    if (isValidExpression(temp) && (temp.length() == s.length() - invalidBrackets(s)))
    {
        return true;
    }

    return false;
}

void sol(int index, vector<string> &output, string temp, string s)
{
    if (index >= s.length())
    {
        if (isValid(temp, s))
        {
            output.push_back(temp);
        }
        return;
    }
    temp.push_back(s[index]);
    sol(index + 1, output, temp, s);
    temp.pop_back();
    sol(index + 1, output, temp, s);
}

vector<string> removeInvalidParentheses(string s)
{
    vector<string> output;
    string temp;
    sol(0, output, temp, s);
    return output;
}

// accepted

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
                continue; // We found at least one valid expression
            }
            // If we have found valid expressions at the current level, stop further removals

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