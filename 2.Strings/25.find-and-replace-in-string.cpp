class Solution
{
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        vector<pair<int, int>> ops;

        for (int i = 0; i < indices.size(); i++)
        {
            ops.push_back({indices[i], i});
        }

        sort(ops.begin(), ops.end());

        int pos = 0;
        string res;
        for (auto [idx, i] : ops)
        {
            while (pos < idx)
            {
                res += s[pos];
                pos++;
            }

            string src = sources[i];
            string trgt = targets[i];
            if (src == s.substr(idx, src.length()))
            {
                res += trgt;
                pos += src.length();
            }
        }
        while (pos < s.length())
        {
            res += s[pos];
            pos++;
        }
        return res;
    }
};

// anther appraoch same time and space o(n)
class Solution
{
public:
    string findReplaceString(string s, vector<int> &indices,
                             vector<string> &sources, vector<string> &targets)
    {
        int n = indices.size();

        // Pair index with operation id
        vector<pair<int, int>> ops;
        for (int i = 0; i < n; i++)
        {
            ops.push_back({indices[i], i});
        }

        // Sort descending
        sort(ops.rbegin(), ops.rend());

        // Always compare against original s, not modified version
        string original = s;

        for (auto [idx, i] : ops)
        {
            string src = sources[i];
            string tgt = targets[i];
            if (original.substr(idx, src.size()) == src)
            {
                s = s.substr(0, idx) + tgt + s.substr(idx + src.size());
            }
        }
        return s;
    }
};
