class Solution
{
private:
    bool isIsomorphic(string s, string t)
    {

        unordered_map<char, char> mp;

        for (int i = 0; i < s.length(); i++)
        {
            if (mp.contains(s[i]))
            {
                if (mp[s[i]] != t[i])
                    return false;
            }
            else
                for (auto cur : mp)
                    if (cur.second == t[i])
                        return false;

            mp[s[i]] = t[i];
        }
        return true;
    }

public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> res;

        for (int i = 0; i < words.size(); i++)
        {
            if (isIsomorphic(words[i], pattern))
                res.push_back(words[i]);
        }
        return res;
    }
};