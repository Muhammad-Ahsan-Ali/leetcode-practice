class Solution
{
public:
    int numSplits(string s)
    {
        unordered_map<char, int> suffix;
        int n = s.size();

        for (int i = 0; i < n; i++)
            suffix[s[i]]++;

        unordered_map<char, int> prefix;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            prefix[s[i]]++;
            suffix[s[i]]--;
            if (suffix[s[i]] == 0)
                suffix.erase(s[i]);

            if (suffix.size() == prefix.size())
                ans++;
        }

        return ans;
    }
};