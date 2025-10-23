class Solution
{
private:
    void processSegment(string &line, vector<string> &dirOfFiles)
    {
        if (line == "..")
        {
            if (!dirOfFiles.empty())
                dirOfFiles.pop_back();
        }
        else if (!line.empty() && line != ".")
        {
            dirOfFiles.push_back(line);
        }
    }

public:
    string simplifyPath(string path)
    {
        vector<string> dirOfFiles;
        string line;

        for (char c : path)
            if (c == '/')
            {
                processSegment(line, dirOfFiles);
                line.clear();
            }
            else
                line.push_back(c);

        processSegment(line, dirOfFiles);

        if (dirOfFiles.empty())
            return "/";

        string ans;
        for (auto &dir : dirOfFiles)
            ans += "/" + dir;

        return ans;
    }
};
