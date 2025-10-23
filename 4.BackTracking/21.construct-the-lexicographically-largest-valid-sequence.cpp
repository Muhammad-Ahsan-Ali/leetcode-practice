class Solution
{
public:
    vector<int> constructDistancedSequence(int n)
    {

        vector<int> res(2 * n - 1, -1);
        vector<bool> used(n + 1, false);

        auto sol = [&](auto &&sol, int i) -> bool
        {
            if (i >= res.size())
                return true;

            if (res[i] != -1)
                return sol(sol, i + 1);

            for (int num = n; num >= 1; num--)
            {
                if (used[num])
                    continue;

                used[num] = 1;
                res[i] = num;

                if (num == 1)
                {
                    if (sol(sol, i + 1))
                        return true;
                }
                else
                {
                    int j = num + i;
                    if (j < res.size() && res[j] == -1)
                    {
                        res[j] = num;
                        if (sol(sol, i + 1))
                            return true;
                        res[j] = -1;
                    }
                }

                used[num] = 0;
                res[i] = -1;
            }
            return false;
        };
        sol(sol, 0);
        return res;
    }
};