class Solution
{
private:
    long long substrNotGood(string &s)
    {
        int n = s.length();
        unordered_map<char, int> mp;
        int l = 0;
        long long cnt = 0;
        for (int r = 0; r < n; r++)
        {
            mp[s[r]]++;

            while (mp.size() >= 3)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }

public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        long long totalSubstr = (1ll * n * (n + 1)) / 2;

        return totalSubstr - substrNotGood(s);
    }
};

// other approach

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        int ans = 0;
        vector<int> trck(3, -1);
        for (int i = 0; i < n; i++)
        {
            trck[s[i] - 'a'] = i;
            ans += 1 + min({trck[0], trck[1], trck[2]});
        }
        return ans;
    }
};
