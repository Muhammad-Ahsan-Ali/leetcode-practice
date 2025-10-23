class Solution
{
public:
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
};