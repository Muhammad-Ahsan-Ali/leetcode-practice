class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        int n = s.length();
        int ans = -1;

        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;

        while (r < n)
        {
            mp[s[r]]++;
            if (mp.size() > k)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }

                l++;
            }
            if (mp.size() == k)
            {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};
