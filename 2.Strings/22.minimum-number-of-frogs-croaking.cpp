class Solution
{
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {

        unordered_map<char, int> mp;
        int ans = 0;
        int frog = 0;
        for (auto &&ch : croakOfFrogs)
        {
            if (ch == 'c')
                frog++, mp[ch]++;
            else if (ch == 'r' && mp['c'] > mp['r'])
                mp['r']++;
            else if (ch == 'o' && mp['r'] > mp['o'])
                mp['o']++;
            else if (ch == 'a' && mp['o'] > mp['a'])
                mp['a']++;
            else if (ch == 'k' && mp['a'] > mp['k'])
            {
                ans = max(ans, frog);
                mp['k']++;
                frog--;
            }
            else
                return -1;
        }
        return frog == 0 ? ans : -1;
    }
};