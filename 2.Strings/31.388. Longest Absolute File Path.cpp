class Solution
{
public:
    int lengthLongestPath(string input)
    {
        // split input by '\n' into lines
        vector<string> lines;

        string line;
        for (char c : input)
        {
            if (c == '\n')
            {
                lines.push_back(line);
                line.clear();
            }
            else
            {
                line.push_back(c);
            }
        }
        lines.push_back(line); // last line

        unordered_map<int, int> pathLen; // depth -> length of path till that depth
        pathLen[0] = 0;
        int maxLen = 0;

        for (const string &line : lines)
        {
            // count depth = number of '\t'
            int depth = 0;
            while (depth < line.length() && line[depth] == '\t')
                depth++;

            string name = line.substr(depth); // remove tabs
 
            if (name.find('.') != string::npos)
            {
                // it's a file
                int curLen = pathLen[depth] + name.length();
                maxLen = max(maxLen, curLen);
            }
            else
            {
                // it's a directory (+1 for '/')
                pathLen[depth + 1] = pathLen[depth] + name.length() + 1;
            }
        }
        return maxLen;
    }
};
