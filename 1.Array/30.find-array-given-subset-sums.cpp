class Solution
{
public:
    vector<int> recoverArray(int n, vector<int> &sums)
    {

        vector<int> ans;
        sort(sums.begin(), sums.end());

        while (n--)
        {
            int dif = sums[1] - sums[0];
            unordered_map<int, int> freq;
            vector<int> s1;
            vector<int> s2;
            int flag = 0;

            for (auto &it : sums)
            {
                if (!freq[it])
                {
                    s1.push_back(it);
                    freq[it + dif]++;
                    if (it == 0)
                        flag = 1;
                }
                else
                {
                    s2.push_back(it);
                    freq[it]--;
                }
            }

            if (flag)
            {
                ans.push_back(dif);
                sums = s1;
            }
            else
            {
                ans.push_back(-dif);
                sums = s2;
            }
        }
        return ans;
    }
};