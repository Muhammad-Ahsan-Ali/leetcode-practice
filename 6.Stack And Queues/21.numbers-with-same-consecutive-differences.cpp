class Solution
{
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {

        queue<int> q;
        for (int i = 1; i <= 9; ++i)
            q.push(i);

        while (--n)
        {
            int sz = q.size();

            for (int i = 0; i < sz; i++)
            {
                int num = q.front();
                q.pop();

                for (int j = 0; j < 10; j++)
                    if (abs((num % 10) - j) == k)
                        q.push((num * 10) + j);
            }
        }
        vector<int> result;
        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};