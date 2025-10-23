class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int n = changed.size();
        if (n % 2)
            return vector<int>{};
        sort(changed.begin(), changed.end());

        unordered_map<int, int> hasElem;
        for (int i = 0; i < n; i++)
            hasElem[changed[i]]++;

        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
            if (changed[i] % 2 && hasElem.count(changed[i]))
                return vector<int>{};
            else if (changed[i] == 0 && (hasElem[0] >= 2))
            {
                ans.push_back(0);
                hasElem[0] -= 2;
                if (!hasElem[0])
                    hasElem.erase(0);
            }
            else if (changed[i] != 0 && hasElem.count(changed[i] / 2) &&
                     hasElem.count(changed[i]))
            {
                hasElem[changed[i] / 2]--;
                hasElem[changed[i]]--;

                if (!hasElem[changed[i] / 2])
                    hasElem.erase(changed[i] / 2);
                if (!hasElem[changed[i]])
                    hasElem.erase(changed[i]);

                ans.push_back(changed[i] / 2);
            }

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i];

        return ans.size() == n / 2 ? ans : vector<int>{};
    }
};

// optimized

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int n = changed.size();
        if (n % 2)
            return {};

        sort(changed.begin(), changed.end());
        unordered_map<int, int> hasElem;
        for (int x : changed)
            hasElem[x]++;

        vector<int> ans;
        for (int x : changed)
        {
            if (hasElem[x] == 0)
                continue;

            if (hasElem[2 * x] == 0)
                return {};

            ans.push_back(x);
            hasElem[x]--;
            hasElem[2 * x]--;
        }

        return ans;
    }
};
