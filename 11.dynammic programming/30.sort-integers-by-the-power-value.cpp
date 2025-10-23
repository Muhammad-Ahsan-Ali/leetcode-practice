class Solution
{
    unordered_map<int, int> mp;

    int comp(int n)
    {
        if (n == 1 || n == 0)
            return 0;

        if (mp.count(n))
            return mp[n];

        return mp[n] = (n % 2) ? 1 + comp((n * 3) + 1) : 1 + comp(n / 2);
    }

public:
    int getKth(int lo, int hi, int k)
    {

        vector<int> ans(hi - lo + 1);
        iota(ans.begin(), ans.end(), lo);
        nth_element(ans.begin(), ans.begin() + k - 1, ans.end(),
                    [&](int a, int b)
                    {
                        return comp(a) == comp(b) ? a < b : comp(a) < comp(b);
                    });

        return ans[k - 1];
    }
};