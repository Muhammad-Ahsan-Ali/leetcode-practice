class Solution
{
public:
    string minWindow(string s, string t)
    {

        int n = s.length();
        int m = t.length();

        unordered_map<char, int> freqT;
        int TEls = 0;
        for (int i = 0; i < m; i++)
        {
            freqT[t[i]]++;
            if (freqT[t[i]] == 1)
                TEls++;
        }

        int minLen = INT_MAX;
        int found = 0;
        int strt;
        int l = 0;
        int r = 0;

        unordered_map<char, int> mp;
        while (r < n)
        {
            if (freqT[s[r]])
            {
                mp[s[r]]++;
                if (mp[s[r]] == freqT[s[r]])
                    found++;
            }

            while (found == TEls && l <= r)
            {
                if (minLen > r - l + 1)
                {
                    strt = l;
                    minLen = r - l + 1;
                }

                if (freqT[s[l]])
                {
                    if (mp[s[l]] == freqT[s[l]])
                        found--;
                    mp[s[l]]--;
                }
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(strt, minLen);
    }
};