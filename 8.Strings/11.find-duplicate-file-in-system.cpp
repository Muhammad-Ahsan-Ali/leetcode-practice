class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {

        unordered_map<string, vector<string>> mp;

        for (auto &path : paths)
        {
            string pth;
            int i = 0;
            while (path[i] != ' ')
                pth += path[i++];
            pth += '/';
            i++;

            while (i < path.size())
            {
                string data;
                string file;

                while (path[i] != '(')
                    file += path[i++];

                while (i < path.size() && path[i] != ' ')
                    data += path[i++];
                i++;

                mp[data].push_back(pth + file);
            }
        }

        vector<vector<string>> ans;
        for (auto &&cur : mp)
        {
            if (cur.second.size() > 1)
                ans.push_back(cur.second);
        }
        return ans;
    }
};