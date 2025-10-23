class Solution
{
private:
    bool inBlock = false; // track if we are inside a block comment

    // Process a single line, removing comments, and return the "cleaned" string
    string processLine(const string &line)
    {
        string cur;
        int n = line.size();

        for (int i = 0; i < n; i++)
        {
            if (!inBlock)
            {
                // Check line comment //
                if (i + 1 < n && line[i] == '/' && line[i + 1] == '/')
                {
                    break; // ignore rest of line
                }
                // Check block comment /*
                else if (i + 1 < n && line[i] == '/' && line[i + 1] == '*')
                {
                    inBlock = true;
                    i++; // skip '*'
                }
                else
                    cur.push_back(line[i]);
            }
            else
            {
                // We look for */
                if (i + 1 < n && line[i] == '*' && line[i + 1] == '/')
                {
                    inBlock = false;
                    i++;
                }
            }
        }

        return cur;
    }

public:
    vector<string> removeComments(vector<string> &source)
    {
        vector<string> ans;
        string curLine;

        for (auto &line : source)
        {
            string part = processLine(line);
            curLine += part;
            if (!inBlock)
            {
                // If we are not in a block comment
                if (!curLine.empty())
                {
                    ans.push_back(curLine);
                    curLine.clear();
                }
            }
        }

        return ans;
    }
};
