class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        unordered_map<int, int> mp;

        int len = 0;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            mp[fruits[r]]++;

            if (mp.size() > 2)
            {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);

                l++;
            }

            if (mp.size() <= 2)
                len = max(len, r - l + 1);
        }
        return len;
    }
};