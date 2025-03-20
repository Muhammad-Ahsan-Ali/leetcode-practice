class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int maxCookies = 0;
        int l = 0;
        int r = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (1)
        {

            if (l >= s.size() || r >= g.size())
                return maxCookies;

            if (g[r] <= s[l])
            {
                l++;
                r++;
                maxCookies++;
                continue;
            }
            if (g[r] > s[l])
            {
                l++;
                continue;
            }
        }
    }
};